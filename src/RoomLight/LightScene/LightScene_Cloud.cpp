/*******************************************************************************
Project   RoomLight

  This is an OpenSource Project.
  You can use, share or improve this project. If you improve this source code
  please share with the comunity or at least with the author of the original 
  source code
  
  Created 10. November 2022 by MarkusNTrains
================================================================================
$HeadURL:  $
$Id:  $
*******************************************************************************/


//-----------------------------------------------------------------------------
// includes
#include "LightScene_Cloud.h"


//-----------------------------------------------------------------------------
// typedef


//-----------------------------------------------------------------------------
// define


//-----------------------------------------------------------------------------
// static module variable



//*****************************************************************************
// description:
//   constructor
//*****************************************************************************
LightScene_Cloud::LightScene_Cloud(RoomLightHdl* parent, LightHdl* light_hdl) 
{
    this->m_scene_hdl_p = parent;
    this->m_light_hdl_p = light_hdl;

    this->m_nof_clouds = 0;
}


//*****************************************************************************
// description:
//   destructor
//*****************************************************************************
LightScene_Cloud::~LightScene_Cloud() 
{
    this->DeleteAllClouds();
}


//*****************************************************************************
// description:
//   Enter
//*****************************************************************************
void LightScene_Cloud::Enter() 
{
    uint8_t cnt = 0;

    this->m_scene_color = this->m_light_hdl_p->GetColor();
    this->m_start_next_cloud_idx = 0;
    this->m_start_cloud_timestamp_ms = 0;
    this->m_start_next_cloud_tmo_ms = TASK_TmoMs;
    this->m_task_hdl_timestamp_ms = 0;
    this->m_task_cycle_cnt = 0;

    this->DeleteAllClouds();

    srand(millis());
    this->m_nof_clouds = (rand() % ((CLOUD_MaxNof + 1) - CLOUD_MinNof)) + CLOUD_MinNof;
    for (cnt = 0; cnt < this->m_nof_clouds; cnt++) 
    {
        this->m_cloud_p[cnt] = new SkyCloud();
        this->m_cloud_p[cnt]->is_enable = false;
        this->m_cloud_p[cnt]->position_px = 0;
        this->m_cloud_p[cnt]->row = rand() % LedRow::LED_ROW_NOF;
        this->m_cloud_p[cnt]->width = (rand() % ((CLOUD_MaxWidth + 1) - CLOUD_MinWidth)) + CLOUD_MinWidth;;
        this->m_cloud_p[cnt]->length_px = (rand() % ((CLOUD_MaxLengthPx + 1) - CLOUD_MinLengthPx)) + CLOUD_MinLengthPx;
        this->m_cloud_p[cnt]->speed = (rand() % ((CLOUD_MaxSpeed + 1) - CLOUD_MinSpeed)) + CLOUD_MinSpeed;
        this->m_cloud_p[cnt]->darkness = (rand() % ((CLOUD_MaxDarkness + 1) - CLOUD_MinDarkness)) + CLOUD_MinDarkness;
    }
}


//*****************************************************************************
// description:
//   Exit
//*****************************************************************************
void LightScene_Cloud::Exit() 
{
    this->DeleteAllClouds();
}


//*****************************************************************************
// description:
//   Delete all clouds
//*****************************************************************************
void LightScene_Cloud::DeleteAllClouds()
{
    for (uint16_t cnt = 0; cnt < this->m_nof_clouds; cnt++) 
    {
        delete this->m_cloud_p[cnt];
    }

    this->m_nof_clouds = 0;
}


//*****************************************************************************
// description:
//   Task
// return:
//   true if LightHdl::Show() needs to be called, else false
//*****************************************************************************
bool LightScene_Cloud::Task() 
{
    bool is_update_needed = false;

    //--- check if a new cloud has to be enabled -----------------------------
    if (this->m_start_next_cloud_idx < this->m_nof_clouds) 
    {
        if (millis() >= this->m_start_cloud_timestamp_ms + this->m_start_next_cloud_tmo_ms) 
        {
            this->m_start_cloud_timestamp_ms = millis();

            this->m_cloud_p[this->m_start_next_cloud_idx]->is_enable = true;
            this->m_start_next_cloud_idx++;

            srand(millis());
            this->m_start_next_cloud_tmo_ms = (rand() % ((CLOUD_AddNext_MaxTmohMs + 1) / this->m_nof_clouds))  + CLOUD_AddNext_MinTmoMs;
        }
    }

    //--- move clouds ---------------------------------------------------------
    if (millis() >= this->m_task_hdl_timestamp_ms + TASK_TmoMs) 
    {
        this->m_task_hdl_timestamp_ms = millis();
        this->m_task_cycle_cnt++;

        uint16_t cnt = 0;
        uint16_t nof_active_clouds = 0;
        uint16_t start_pos;
        uint16_t end_pos;
        uint16_t column;
        uint8_t row;
        wrgb_color_t color;
        uint32_t darkness = 0;

        this->m_light_hdl_p->SetLedArea_DoNotChangeBlackLED(0, LedRow::LED_ROW_LENGTH, 0, LedRow::LED_ROW_NOF, this->m_scene_color);
        for (cnt = 0; cnt < this->m_nof_clouds; cnt++) 
        {
            if (this->m_cloud_p[cnt]->is_enable == true) 
            {
                nof_active_clouds++;

                //--- calculate end pos ---------------------------------------
                end_pos = this->m_cloud_p[cnt]->position_px;

                //--- calculate start pos -------------------------------------
                if (end_pos > this->m_cloud_p[cnt]->length_px) 
                {
                    start_pos = end_pos - this->m_cloud_p[cnt]->length_px;
                } 
                else 
                {
                    start_pos = 0;
                }

                if (start_pos >= LedRow::LED_ROW_LENGTH) 
                {
                    this->m_cloud_p[cnt]->is_enable = false;
                }

                //--- calculate color -----------------------------------------
                color.color = this->m_scene_color;
                darkness = this->m_cloud_p[cnt]->darkness;
                color.red = this->SubtractDarkness(color.red, darkness);
                color.green = this->SubtractDarkness(color.green, darkness);
                color.blue = this->SubtractDarkness(color.blue, darkness);
                color.white = this->SubtractDarkness(color.white, darkness);
                
                // show clouds in different colors --> use for debugging
                /*switch (cnt % 6)
                {
                    case 0:
                        color = 0x00FF0000;
                        break;

                    case 1:
                        color = 0x0000FF00;
                        break;

                    case 2:
                        color = 0x000000FF;
                        break;

                    case 3:
                        color = 0x00FFFF00;
                        break;

                    case 4:
                        color = 0x00FF00FF;
                        break;

                    case 5:
                        color = 0x0000FFFF;
                        break;
                }*/

                //--- set cloud into stripe -----------------------------------
                /*for (row = this->m_cloud_p[cnt]->row; row < (this->m_cloud_p[cnt]->row + this->m_cloud_p[cnt]->width); row++) 
                {
                    if (row >= LedRow::LED_ROW_NOF) 
                    {
                        break;
                    }

                    for (column = start_pos; column <= end_pos; column++) 
                    {
                        if (column < LedRow::LED_ROW_LENGTH)
                        {
                            if (this->m_light_hdl_p->GetLedColor(row, column) > color) 
                            {
                                this->m_light_hdl_p->SetLedColor(row, column, color);
                            }
                        }
                    }
                }*/
                
                this->m_light_hdl_p->SetLedArea_DoNotChangeBlackLED(start_pos, end_pos, this->m_cloud_p[cnt]->row, this->m_cloud_p[cnt]->row + this->m_cloud_p[cnt]->width, color.color);
                is_update_needed = true;

                //--- update position -----------------------------------------
                if ((this->m_task_cycle_cnt % this->m_cloud_p[cnt]->speed) == 0) 
                {
                    this->m_cloud_p[cnt]->position_px++;
                }
            }
        }

        //--- check exit condition --------------------------------------------
        if ((nof_active_clouds == 0) && (this->m_start_next_cloud_idx >= this->m_nof_clouds)) 
        {
            is_update_needed = false;
            this->Leave();
        }
    }

    return is_update_needed;
}


//*****************************************************************************
// description:
//   Leave light scene --> used for internal porpuse
//*****************************************************************************
void LightScene_Cloud::Leave()
{
    this->m_scene_hdl_p->ChangeScene((uint8_t)this->m_scene_hdl_p->GetLastScene());
}


//*****************************************************************************
// description:
//   subtract darkness from a single (red, green, blue or white) color value
//*****************************************************************************
uint8_t LightScene_Cloud::SubtractDarkness(uint8_t color, uint8_t darkness)
{
    uint8_t min_color = 255 / this->m_light_hdl_p->GetBrightness();

    if (color > 0)
    {
        if (color - darkness > min_color)
        {
            color -= darkness;
        }
        else
        {
            color = min_color;
        }
    }

    return color;
}