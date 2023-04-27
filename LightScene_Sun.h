/*******************************************************************************
Project   RoomLight

  This is an OpenSource Project.
  You can use, share or improve this project. If you improve this source code
  please share with the comunity or at least with the author of the original 
  source code
  
  Created 8. September 2022 by MarkusNTrains
================================================================================
$HeadURL:  $
$Id:  $
*******************************************************************************/

#ifndef _LIGHT_SCENE_SUN_H
#define _LIGHT_SCENE_SUN_H


//----------------------------------------------------------------------------
// include
#include "common.h"
#include "LightHdl.h"
#include "LightSceneHdl.h"
#include "LightScene_Night.h"



//----------------------------------------------------------------------------
// enum
enum LightningState
{
    LIGHTSCENESUN_STATE_Sunrise = 0,
    LIGHTSCENESUN_STATE_Sunset,
    LIGHTSCENESUN_STATE_Fading,
    LIGHTSCENESUN_STATE_FadingToNight,
    LIGHTSCENESUN_STATE_Unknown,
};


//----------------------------------------------------------------------------
// extern
class LightSceneHdl;


//----------------------------------------------------------------------------
// class
class LightScene_Sun
{
    public:
        LightScene_Sun(LightSceneHdl* parent, LightHdl* light_hdl, Datastore* datastore_p);
        ~LightScene_Sun();

        void Sunrise_Enter();
        void Sunrise_Exit();
        void Sunrise_Task();
        void Sunset_Enter();
        void Sunset_Exit();
        void Sunset_Task();
        void CalculateAndShow_Sunlight();
        void Update_DayParameter();


    private:
        const static uint32_t TASK_Sun_TmoMs = 80; 

        const static uint32_t PIXEL_DISTANCE_MM = 16;  // distance between neo pixels in mm
        const static uint32_t SUN_MAX_HEIGHT = 10000;

        const static uint8_t SUNRISE_BIRGHTNESS = LightScene_Night::BRIGHTNESS_Max;
        const static uint8_t RED_MAX = 255;
        const static uint8_t GREEN_MAX = 120;
        const static uint8_t BLUE_MAX = 32;

        LightSceneHdl* m_scene_hdl_p;
        LightHdl* m_light_hdl_p;
        Datastore* m_datastore_p;

        LightningState m_state;
        uint32_t m_sun_height;
        uint32_t m_sun_pos;
        uint32_t m_day_color;
        uint32_t m_task_timestamp_ms;

        uint8_t m_day_brightness_white;
        uint8_t m_day_brightness_rgb;
        uint8_t m_red_max;
        uint8_t m_green_max;
        uint8_t m_blue_max;
        uint8_t m_twilight_brightness;
        uint8_t m_night_brightness;
};

#endif // _LIGHT_SCENE_SUN_H
