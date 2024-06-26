/*##############################################################################

  THIS IS GENERATED CODE (use RoomLight_Parameter.ods)
    ==> DO NOT EDIT MANUALLY !!!

##############################################################################*/


/*******************************************************************************
Project   RoomLight

  This is an OpenSource Project.
  You can use, share or improve this project. If you improve this source code
  please share with the comunity or at least with the author of the original
  source code

  Created 03.05.2024 08:27:02 by MarkusNTrains
================================================================================
$HeadURL: file:///C:/SwProjects/Arduino/RoomLight_DaylightSimulation/src/Datastore/Parameter_RoomLight.cpp $
$Id: 03.05.2024 08:27:02 automatic gen. $
*******************************************************************************/

/*
Defines the Parameter of RoomLight device and their properties.
 Usage of this file allows to have configuration parameter specific information
 only within this file. See RoomLight_Parameter.ods for more Information.
*/

//------------------------------------------------------------------------------
// include
#include "Parameter.h"
#include "../RoomLight/RoomLightHdl.h"
#include "../RoomLight/LightScene/LightScene_Day.h"
#include "../RoomLight/LightScene/LightScene_Night.h"
#include "../SimpleLedStrip/SimpleLedStripHdl.h"



//-----------------------------------------------------------------------------
// Info
// PROGMEM -> store data in flash
//   to read out the sored data from PROGMEM use one macro of <avr/pgmspace.h>
//   - e.g. (char*)pgm_read_word(&(PARAM_IN_PROGMEM))
//   - or use memcpy_P
//      data_type_t param_SRAM
//      memcpy_P(&param_SRAM, &PARAM_IN_PROGMEM, sizeof(data_type_t))
//   more infos: https://www.arduino.cc/reference/en/language/variables/utilities/progmem/


//------------------------------------------------------------------------------
// const parameter
const parameter_t PARAM_TABLE[Parameter::Id::Nof] PROGMEM = {
    [Parameter::Id::SceneID] = {
        .default_value = (uint32_t)RoomLightHdl::SceneID::OfficeTable,
        .min = 0,
        .max = ((uint32_t)RoomLightHdl::SceneID::Nof - 1) ,
        .addr = 0,
        .width = 1,
    },
    [Parameter::Id::SceneDay_Brightness] = {
        .default_value = LightScene_Day::BRIGHTNESS_Default ,
        .min = LightScene_Day::BRIGHTNESS_Min,
        .max = Parameter::BRIGHTNESS_Max ,
        .addr = 1,
        .width = 1,
    },
    [Parameter::Id::SceneDisco_Brightness] = {
        .default_value = Parameter::BRIGHTNESS_Default ,
        .min = Parameter::BRIGHTNESS_Min ,
        .max = Parameter::BRIGHTNESS_Max ,
        .addr = 2,
        .width = 1,
    },
    [Parameter::Id::SceneMoBa_Brightness] = {
        .default_value = Parameter::BRIGHTNESS_Default ,
        .min = Parameter::BRIGHTNESS_Min ,
        .max = Parameter::BRIGHTNESS_Max ,
        .addr = 3,
        .width = 1,
    },
    [Parameter::Id::SceneMoBa_Color] = {
        .default_value = Parameter::COLOR_Default,
        .min = Parameter::COLOR_Min,
        .max = Parameter::COLOR_Max,
        .addr = 4,
        .width = 4,
    },
    [Parameter::Id::SceneLightOn_Brightness] = {
        .default_value = Parameter::BRIGHTNESS_Default ,
        .min = Parameter::BRIGHTNESS_Min ,
        .max = Parameter::BRIGHTNESS_Max ,
        .addr = 8,
        .width = 1,
    },
    [Parameter::Id::SceneLightOn_Color] = {
        .default_value = Parameter::COLOR_Default,
        .min = Parameter::COLOR_Min,
        .max = Parameter::COLOR_Max,
        .addr = 9,
        .width = 4,
    },
    [Parameter::Id::SceneNight_Brightness] = {
        .default_value = LightScene_Night::BRIGHTNESS_Default ,
        .min = LightScene_Night::BRIGHTNESS_Min,
        .max = LightScene_Night::BRIGHTNESS_Max,
        .addr = 13,
        .width = 1,
    },
    [Parameter::Id::SceneOfficeTable_Brightness] = {
        .default_value = Parameter::BRIGHTNESS_Default ,
        .min = Parameter::BRIGHTNESS_Min ,
        .max = Parameter::BRIGHTNESS_Max ,
        .addr = 14,
        .width = 1,
    },
    [Parameter::Id::SceneOfficeTable_Color] = {
        .default_value = Parameter::COLOR_Default,
        .min = Parameter::COLOR_Min,
        .max = Parameter::COLOR_Max,
        .addr = 15,
        .width = 4,
    },
    [Parameter::Id::SceneRainbow_Brightness] = {
        .default_value = Parameter::BRIGHTNESS_Default ,
        .min = Parameter::BRIGHTNESS_Min ,
        .max = Parameter::BRIGHTNESS_Max ,
        .addr = 19,
        .width = 1,
    },
    [Parameter::Id::SceneUserSetting_Brightness] = {
        .default_value = Parameter::BRIGHTNESS_Default ,
        .min = Parameter::BRIGHTNESS_Min ,
        .max = Parameter::BRIGHTNESS_Max ,
        .addr = 20,
        .width = 1,
    },
    [Parameter::Id::SceneUserSetting_Color] = {
        .default_value = Parameter::COLOR_Default,
        .min = Parameter::COLOR_Min,
        .max = Parameter::COLOR_Max,
        .addr = 21,
        .width = 4,
    },
    [Parameter::Id::SceneUserSetting_Xs] = {
        .default_value = 0,
        .min = 0,
        .max = (ROOM_LIGHT_RowNofPx - 1) ,
        .addr = 25,
        .width = 2,
    },
    [Parameter::Id::SceneUserSetting_Xe] = {
        .default_value = (ROOM_LIGHT_RowNofPx - 1) ,
        .min = 0,
        .max = (ROOM_LIGHT_RowNofPx - 1) ,
        .addr = 27,
        .width = 2,
    },
    [Parameter::Id::SceneUserSetting_Ys] = {
        .default_value = 0,
        .min = 0,
        .max = (ROOM_LIGHT_NofRows - 1) ,
        .addr = 29,
        .width = 1,
    },
    [Parameter::Id::SceneUserSetting_Ye] = {
        .default_value = (ROOM_LIGHT_NofRows - 1) ,
        .min = 0,
        .max = (ROOM_LIGHT_NofRows - 1) ,
        .addr = 30,
        .width = 1,
    },
    [Parameter::Id::Sbf_SceneID] = {
        .default_value = (uint32_t)SimpleLedStripHdl::SceneID::Off,
        .min = 0,
        .max = ((uint32_t)SimpleLedStripHdl::SceneID::Nof - 1) ,
        .addr = 31,
        .width = 1,
    },
    [Parameter::Id::Sbf_Brightness] = {
        .default_value = 100,
        .min = 0,
        .max = Parameter::BRIGHTNESS_Max ,
        .addr = 32,
        .width = 1,
    },
    [Parameter::Id::Sbf_Color] = {
        .default_value = 0,
        .min = 0,
        .max = 0xFFFFFF,
        .addr = 33,
        .width = 3,
    },
    [Parameter::Id::Sbf_White] = {
        .default_value = 0,
        .min = 0,
        .max = 0xFFFF,
        .addr = 36,
        .width = 2,
    },
};


