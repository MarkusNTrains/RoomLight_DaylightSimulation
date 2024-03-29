/*******************************************************************************
Project   RoomLight

  This is an OpenSource Project.
  You can use, share or improve this project. If you improve this source code
  please share with the comunity or at least with the author of the original 
  source code
  
  Created 21. April 2023 by MarkusNTrains
================================================================================
$HeadURL:  $
$Id:  $
*******************************************************************************/

#ifndef _LIGHT_SCENE_USER_SETTING_H
#define _LIGHT_SCENE_USER_SETTING_H


//----------------------------------------------------------------------------
// include
#include "LightScene.h"



//----------------------------------------------------------------------------
// extern


//----------------------------------------------------------------------------
// class
class LightScene_UserSetting : public LightScene
{
    public:
        LightScene_UserSetting(LightHdl* light_hdl, Datastore* datastore_p);
        ~LightScene_UserSetting();

        void Enter();
        void Exit();

        void GetLedArea(LedArea* area);
        void SetLedArea(LedArea* area);

    private:
        const static uint32_t TASK_TmoMs = 1000ul;

        Datastore* m_datastore_p;
        LightHdl* m_light_hdl_p;

        LedArea* m_led_area_p;

        bool TaskHdl();
};

#endif // _LIGHT_SCENE_USER_SETTING_H
