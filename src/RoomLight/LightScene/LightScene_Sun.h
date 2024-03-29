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
#include "../../common.h"
#include "../../Datastore/Datastore.h"
#include "../LightHdl/LightHdl.h"
#include "../RoomLightHdl.h"
#include "LightScene_Night.h"



//----------------------------------------------------------------------------
// extern


//----------------------------------------------------------------------------
// class
class LightScene_Sun
{
    public:
        LightScene_Sun(RoomLightHdl* parent, LightHdl* light_hdl, Datastore* datastore_p);
        ~LightScene_Sun();

        void Sunrise_Enter();
        bool Sunrise_Task();
        void Sunset_Enter();
        bool Sunset_Task();
        bool CalculateAndShow_Sunlight();
        void Update_DayParameter();


    private:
        enum SunState
        {
            Sunrise = 0,
            Sunset,
            Fading,
            FadingToNight,
            Unknown,
        };

        const static uint32_t TASK_TmoMs = 80ul; 

        const static uint32_t STRIPE_PixelDistanceMM = 16ul;  // distance between neo pixels in mm
        const static uint32_t SUN_MaxHeight = 5000ul;
        const static uint8_t FADING_Factor = 5;
        const static uint8_t FADING_Max = Parameter::BRIGHTNESS_Max;
        const static uint8_t RED_Max = 255;
        const static uint8_t GREEN_Max = 135;
        const static uint8_t BLUE_Max = 32;
        const static uint8_t TWILIGHT_RedOffsetToBlue = LightScene_Night::BRIGHTNESS_Max;
        const static uint8_t SUNRISE_StartBrightness = 20 + TWILIGHT_RedOffsetToBlue;
        const static uint8_t TWILIGHT_GreenOffsetToBlue = SUNRISE_StartBrightness;

        RoomLightHdl* m_scene_hdl_p;
        LightHdl* m_light_hdl_p;
        Datastore* m_datastore_p;

        SunState m_state;
        uint32_t m_sun_height;
        uint32_t m_sun_pos;
        wrgb_color_t m_day_color;
        uint32_t m_task_timestamp_ms;
        uint16_t m_fading_progress_rgb;

        uint16_t m_day_brightness_white;
        uint16_t m_day_brightness_rgb;
        uint16_t m_red_max;
        uint16_t m_green_max;
        uint16_t m_blue_max;
        uint16_t m_twilight_brightness;
        uint16_t m_night_brightness;

        void Sunrise_Leave();
        void Sunset_Leave();
};

#endif // _LIGHT_SCENE_SUN_H
