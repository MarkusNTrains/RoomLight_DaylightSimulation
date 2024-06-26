/*******************************************************************************
Project   RoomLight

  This is an OpenSource Project.
  You can use, share or improve this project. If you improve this source code
  please share with the comunity or at least with the author of the original 
  source code
  
  Created 25. April 2023 by MarkusNTrains
================================================================================
$HeadURL:  $
$Id:  $
*******************************************************************************/


//-----------------------------------------------------------------------------
// includes
#include "LightScene_MoBa.h"



//-----------------------------------------------------------------------------
// typedef



//*****************************************************************************
// description:
//   constructor
//*****************************************************************************
LightScene_MoBa::LightScene_MoBa(LightHdl* light_hdl, Datastore* datastore_p) : 
    LightScene(light_hdl, datastore_p, TASK_TmoMs, Parameter::Id::SceneMoBa_Brightness, Parameter::Id::SceneMoBa_Color)
{
}


//*****************************************************************************
// description:
//   destructor
//*****************************************************************************
LightScene_MoBa::~LightScene_MoBa()
{
}


//*****************************************************************************
// description:
//   Enter
//*****************************************************************************
void LightScene_MoBa::Enter()
{
    this->m_light_hdl_p->Clear();
    this->m_light_hdl_p->SetBrightness_Fade((uint8_t)this->m_datastore_p->GetParameter(this->m_brightness_param_id));
    this->m_light_hdl_p->SetColor(this->m_datastore_p->GetParameter(this->m_color_param_id));
    this->TaskHdl();
}


//*****************************************************************************
// description:
//   Exit
//*****************************************************************************
void LightScene_MoBa::Exit()
{
}


//*****************************************************************************
// description:
//   Task
// return:
//   true if LightHdl::Show() needs to be called, else false
//*****************************************************************************
bool LightScene_MoBa::TaskHdl()
{
  #if (ROOM_LIGHT == ROOM_LIGHT_MarkusNTrains)
    this->m_light_hdl_p->SetLedArea(0, LedRow::LED_ROW_LENGTH, 0, 0);  
    this->m_light_hdl_p->SetLedArea(0, 30, 1, 3);  
    this->m_light_hdl_p->SetLedArea(LedRow::LED_ROW_LENGTH - 30, LedRow::LED_ROW_LENGTH, 1, 3);  
    this->m_light_hdl_p->SetLedArea(0, LedRow::LED_ROW_LENGTH, 4, 4);  
  #elif (ROOM_LIGHT == ROOM_LIGHT_Altenglienicke)
    this->m_light_hdl_p->SetLedArea(0, LedRow::LED_ROW_LENGTH, 0, (LedRow::LED_ROW_NOF - 1));  
  #else
    this->m_light_hdl_p->SetLedArea(3, 5, 0, 0);  
    this->m_light_hdl_p->SetLedArea(9, LedRow::LED_ROW_LENGTH - 3, 0, 0);  
  #endif

    return true;
}


