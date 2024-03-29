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

#ifndef _LIGHT_SCENE_CLOUD_H
#define _LIGHT_SCENE_CLOUD_H


//----------------------------------------------------------------------------
// include
#include "../RoomLightHdl.h"


//----------------------------------------------------------------------------
// struct
struct SkyCloud
{
    bool is_enable;
    uint8_t row;
    uint8_t speed;
    uint8_t darkness;
    uint16_t position_px;
    uint16_t length_px;
    uint16_t width;
};


//----------------------------------------------------------------------------
// extern


//----------------------------------------------------------------------------
// class
class LightScene_Cloud
{
    public:
        LightScene_Cloud(RoomLightHdl* parent, LightHdl* light_hdl);
        ~LightScene_Cloud();
        void Enter();
        void Exit();
        bool Task();

    private:
        // lightning task
        const static uint32_t TASK_TmoMs = 50ul;
        const static uint32_t CLOUD_AddNext_MinTmoMs = 200ul;
        const static uint32_t CLOUD_AddNext_MaxTmohMs = 60000ul;
        const static uint32_t CLOUD_MinSpeed = 1ul;
        const static uint32_t CLOUD_MaxSpeed = 6ul;
        const static uint32_t CLOUD_MinLengthPx = 20ul;
        const static uint32_t CLOUD_MaxLengthPx = 100ul;
        const static uint32_t CLOUD_MinWidth = 1ul;
        const static uint32_t CLOUD_MaxWidth = LedRow::LED_ROW_NOF;
        const static uint32_t CLOUD_MinDarkness = 100ul;
        const static uint32_t CLOUD_MaxDarkness = 255ul;
        const static uint8_t CLOUD_MinNof = 5;
        const static uint8_t CLOUD_MaxNof = 30;

        RoomLightHdl* m_scene_hdl_p;
        LightHdl* m_light_hdl_p;
        SkyCloud* m_cloud_p[CLOUD_MaxNof];
        uint32_t m_scene_color;
        uint32_t m_task_hdl_timestamp_ms;
        uint32_t m_task_cycle_cnt;
        uint32_t m_start_cloud_timestamp_ms;
        uint32_t m_start_next_cloud_tmo_ms;
        uint16_t m_nof_clouds;
        uint16_t m_start_next_cloud_idx;

        void DeleteAllClouds();
        void Leave();
        uint8_t SubtractDarkness(uint8_t color, uint8_t darkness);
};

#endif // _LIGHT_SCENE_CLOUD_H
