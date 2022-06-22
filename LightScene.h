/*******************************************************************************
Project   RoomLight

  This is an OpenSource Project.
  You can use, share or improve this project. If you improve this source code
  please share with the comunity or at least with the author of the original 
  source code
  
  Created 24. August 2020 by MarkusNTrains
================================================================================
$HeadURL:  $
$Id:  $
*******************************************************************************/

#ifndef _LIGHT_SCENE_H
#define _LIGHT_SCENE_H

//----------------------------------------------------------------------------
// include
#include "common.h"
#include "LedMatrix.h"
#include "LedArea.h"

//----------------------------------------------------------------------------
// define

//----------------------------------------------------------------------------
// enum
enum LightScene
{
    OFFICE_TABLE_WW = 0,
    LIGHT_ON_WW,
    RAINBOW,
    SUNSET,
    SUNRISE,
    POWER_OFF,
    MOVING_DOT,
    SBH,
    USER_SETTING,
    IDLE,
    LITGHTING,
    MOBA,
};


//----------------------------------------------------------------------------
// class
class LightSceneHdl
{
    public:
        LightSceneHdl();
        ~LightSceneHdl();
        void Tasks(void);
        void ChangeLightScene(LightScene scene);
        void ChangeLightScene(LightScene scene, uint8_t brightness);
        LightScene GetLightScene(void);
        LedArea *GetLedArea(void);
        void SetLedArea(uint16_t xs, uint16_t xe, uint16_t ys, uint16_t ye);
        uint8_t GetBrightness(void);
        void SetBrightness(uint8_t brightness);
        uint32_t GetColor(void);
        void SetColor(uint32_t color);

    private:
        const uint32_t TMO_TILL_NEXT_UPDATE_MS = 20;
        const uint32_t COLOR_BLUE = 0x000000FF;
        const uint32_t COLOR_GREEN = 0x0000FF00;
        const uint32_t COLOR_RED = 0x00FF0000;
        const uint32_t COLOR_WHITE = 0xFF000000;

        LedMatrix *m_led_matrix;
        LedArea *m_led_area;
        LightScene m_scene;
        LightScene m_last_scene;
        uint8_t m_current_brightness;
        uint8_t m_desired_brightness;
        uint32_t m_color;
        uint32_t m_update_time_ms;
        uint16_t m_px;


        void UpdateBrightness(void);

        // light scene
        void LightScene_OfficeTableWW_Enter(uint16_t brightness);
        void LightScene_OfficeTableWW_Task(void);
        void LightScene_MoBa_Enter(uint16_t brightness);
        void LightScene_MoBa_Task(void);
        void LightScene_LightOnWW_Enter(uint16_t brightness);
        void LightScene_LightOnWW_Task(void);
        void LightScene_Sunrise_Task(void);
        void LightScene_PowerOff_Task(void);
        void LightScene_MovingDot_Task(void);
        void LightScene_UserSetting_Task(void);
        void LightScene_Lightning_Task(void);
        void LightScene_WhiteOverRainbow_Task(int whiteSpeed, int whiteLength);
};

#endif // _LIGHT_SCENE_H