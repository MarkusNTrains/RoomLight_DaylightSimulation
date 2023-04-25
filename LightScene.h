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

#ifndef _LIGHT_SCENE_H
#define _LIGHT_SCENE_H


//----------------------------------------------------------------------------
// include
#include "common.h"
#include "Datastore.h"
#include "LightHdl.h"



//----------------------------------------------------------------------------
// define


//----------------------------------------------------------------------------
// enum


//----------------------------------------------------------------------------
// extern
class LightSceneHdl;


//----------------------------------------------------------------------------
// class
class LightScene
{
    public:
        LightScene(LightHdl* light_hdl, Datastore* datastore_p, uint32_t task_tmo_m, Datastore::ParameterId brightness_param_id, Datastore::ParameterId color_param_id);
        ~LightScene();

        virtual void Enter() = 0;
        virtual void Exit() = 0;
        virtual void TaskHdl() = 0;

        void Task();
        void SetBrightness(uint8_t brightness);
        void SetColor(uint32_t color);

    protected:
        Datastore* m_datastore_p = nullptr;
        LightHdl* m_light_hdl_p;
        Datastore::ParameterId m_brightness_param_id;
        Datastore::ParameterId m_color_param_id;

    private:
        uint32_t m_task_tmo_ms;
        uint32_t m_task_timestamp_ms;

};

#endif // _LIGHT_SCENE_H