/*******************************************************************************
Project   RoomLight

  This is an OpenSource Project.
  You can use, share or improve this project. If you improve this source code
  please share with the comunity or at least with the author of the original 
  source code
  
  Created 18. May 2021 by MarkusNTrains
================================================================================
$HeadURL:  $
$Id:  $
*******************************************************************************/


#ifndef _COMMON_H
#define _COMMON_H


//-----------------------------------------------------------------------------
// includes
#include "Arduino.h"
#include <Ethernet.h>
#include "typedef.h"



//----------------------------------------------------------------------------
// typedef
typedef struct 
{
    uint8_t pin;
    uint16_t nof_pixel;
} ledStrip_t;


//-----------------------------------------------------------------------------
// defines

//############################################################################
// DO NOT CHANGE
//--- version -------------------------------------------------------------
#define SW_VERSION_Major 1
#define SW_VERSION_Minor 8


//--- switch --------------------------------------------------------------
#define ON  1
#define OFF 0
// End of DO NOT CHANGE
//############################################################################


//--- debug setting -------------------------------------------------------
#define IS_DEBUG_MODE OFF  // can be ON or OFF


//--- save data permanent -------------------------------------------------
#define DATASTORE_SaveDataPermanent ON   // if ON then lightscene, color, brightness and led area are saved permanent on EEPROM
#define DATASTORE_SaveLightScene    ON   // if ON then lightscene is saved permanent on EEPROM


//--- hardware setting ----------------------------------------------------
// enhance the following setting to use it for another room light
// and enhance the following files:
//  - LED_MATRIX_LUT in file common.cpp
//  - ip, myDns, gatway, subnet in file common.cpp
typedef enum 
{
    ROOM_LIGHT_TestBoard = 0,
    ROOM_LIGHT_MarkusNTrains,
    ROOM_LIGHT_Altenglienicke,
    ROOM_LIGHT_Ide,
    ROOM_LIGHT_Sennholz
} roomLight_type_t;

#define ROOM_LIGHT ROOM_LIGHT_TestBoard


#ifdef __AVR__
    #define ETHERNETSHIELD_SlaveSelect_Pin 4
#else
    #define ETHERNETSHIELD_SlaveSelect_Pin 5
#endif


#if (ROOM_LIGHT == ROOM_LIGHT_MarkusNTrains)
//--- Enable LightSource ---------------------------------- 
    #define LIGHT_SOURCE_EnableMap ((0x1 << LightSourceHdl::Source::RoomLight) | (0x1 << LightSourceHdl::Source::ShadowStation))


//--- Room Light ------------------------------------------
    // LED Matrix defines -----------------------------
    #define ROOM_LIGHT_NofRows  5
    #define ROOM_LIGHT_RowNofPx 285
    
    // LED Strips define ------------------------------
    #define ROOM_LIGHT_NofLedStrips 5

  #ifdef __AVR__
    #define ROOM_LIGHT_LedStrip1_Pin 26
    #define ROOM_LIGHT_LedStrip2_Pin 28 
    #define ROOM_LIGHT_LedStrip3_Pin 24
    #define ROOM_LIGHT_LedStrip4_Pin 30
    #define ROOM_LIGHT_LedStrip5_Pin 22
  #else
    #define ROOM_LIGHT_LedStrip1_Pin 17
    #define ROOM_LIGHT_LedStrip2_Pin 18
    #define ROOM_LIGHT_LedStrip3_Pin 16
    #define ROOM_LIGHT_LedStrip4_Pin 19
    #define ROOM_LIGHT_LedStrip5_Pin 15
  #endif

    #define ROOM_LIGHT_LedStrip1_NofLed 300
    #define ROOM_LIGHT_LedStrip2_NofLed 285
    #define ROOM_LIGHT_LedStrip3_NofLed 285
    #define ROOM_LIGHT_LedStrip4_NofLed 184
    #define ROOM_LIGHT_LedStrip5_NofLed 285

    const ledStrip_t ROOM_LIGHT_LedStripList[ROOM_LIGHT_NofLedStrips] = {
        { ROOM_LIGHT_LedStrip1_Pin, ROOM_LIGHT_LedStrip1_NofLed},
        { ROOM_LIGHT_LedStrip2_Pin, ROOM_LIGHT_LedStrip2_NofLed},
        { ROOM_LIGHT_LedStrip3_Pin, ROOM_LIGHT_LedStrip3_NofLed},
        { ROOM_LIGHT_LedStrip4_Pin, ROOM_LIGHT_LedStrip4_NofLed},
        { ROOM_LIGHT_LedStrip5_Pin, ROOM_LIGHT_LedStrip5_NofLed},
    };

//--- Shadow Station ---------------------------------------
    // LED Strips define ------------------------------
  #ifdef __AVR__
    #define SBF_LEDRed_Pin       25
    #define SBF_LEDGreen_Pin     27
    #define SBF_LEDBlue_Pin      23
    #define SBF_LEDWarmWhite_Pin 29
    #define SBF_LEDColdWhite_Pin 31
  #else
    #define SBF_LEDRed_Pin       3
    #define SBF_LEDGreen_Pin     2
    #define SBF_LEDBlue_Pin      4
    #define SBF_LEDWarmWhite_Pin 1
    #define SBF_LEDColdWhite_Pin 0
  #endif


#elif (ROOM_LIGHT == ROOM_LIGHT_Altenglienicke)
//--- Enable LightSource ---------------------------------- 
    #define LIGHT_SOURCE_EnableMap ((0x1 << LightSourceHdl::Source::RoomLight))
    

//--- Room Light ------------------------------------------
    // LED Matrix defines -----------------------------
    #define ROOM_LIGHT_NofRows  6
    #define ROOM_LIGHT_RowNofPx 240

    // LED Strips define ------------------------------
    #define ROOM_LIGHT_NofLedStrips 6

    #define ROOM_LIGHT_LedStrip1_Pin 22
    #define ROOM_LIGHT_LedStrip2_Pin 24
    #define ROOM_LIGHT_LedStrip3_Pin 26
    #define ROOM_LIGHT_LedStrip4_Pin 28
    #define ROOM_LIGHT_LedStrip5_Pin 30
    #define ROOM_LIGHT_LedStrip6_Pin 32

    #define ROOM_LIGHT_LedStrip1_NofLed 66
    #define ROOM_LIGHT_LedStrip2_NofLed 240
    #define ROOM_LIGHT_LedStrip3_NofLed 240
    #define ROOM_LIGHT_LedStrip4_NofLed 240
    #define ROOM_LIGHT_LedStrip5_NofLed 240
    #define ROOM_LIGHT_LedStrip6_NofLed 66

    const ledStrip_t ROOM_LIGHT_LedStripList[ROOM_LIGHT_NofLedStrips] = {
        { ROOM_LIGHT_LedStrip1_Pin, ROOM_LIGHT_LedStrip1_NofLed},
        { ROOM_LIGHT_LedStrip2_Pin, ROOM_LIGHT_LedStrip2_NofLed},
        { ROOM_LIGHT_LedStrip3_Pin, ROOM_LIGHT_LedStrip3_NofLed},
        { ROOM_LIGHT_LedStrip4_Pin, ROOM_LIGHT_LedStrip4_NofLed},
        { ROOM_LIGHT_LedStrip5_Pin, ROOM_LIGHT_LedStrip5_NofLed},
        { ROOM_LIGHT_LedStrip6_Pin, ROOM_LIGHT_LedStrip6_NofLed},
    };

//--- Shadow Station ---------------------------------------
    // LED Strips define ------------------------------
  #ifdef __AVR__
    #define SBF_LEDRed_Pin       25
    #define SBF_LEDGreen_Pin     27
    #define SBF_LEDBlue_Pin      23
    #define SBF_LEDWarmWhite_Pin 29
    #define SBF_LEDColdWhite_Pin 31
  #else
    #define SBF_LEDRed_Pin       A0
    #define SBF_LEDGreen_Pin     A1
    #define SBF_LEDBlue_Pin      A2
    #define SBF_LEDWarmWhite_Pin A3
    #define SBF_LEDColdWhite_Pin A4
  #endif

#elif (ROOM_LIGHT == ROOM_LIGHT_Ide)
//--- Enable LightSource ---------------------------------- 
    #define LIGHT_SOURCE_EnableMap ((0x1 << LightSourceHdl::Source::RoomLight))
    

//--- Room Light ------------------------------------------
    // LED Matrix defines -----------------------------
    #define ROOM_LIGHT_NofRows  4
    #define ROOM_LIGHT_RowNofPx 196

    // LED Strips define ------------------------------
    #define ROOM_LIGHT_NofLedStrips 4

    #define ROOM_LIGHT_LedStrip1_Pin 22
    #define ROOM_LIGHT_LedStrip2_Pin 24
    #define ROOM_LIGHT_LedStrip3_Pin 26
    #define ROOM_LIGHT_LedStrip4_Pin 28

    #define ROOM_LIGHT_LedStrip1_NofLed 196
    #define ROOM_LIGHT_LedStrip2_NofLed 196
    #define ROOM_LIGHT_LedStrip3_NofLed 196
    #define ROOM_LIGHT_LedStrip4_NofLed 196

    const ledStrip_t ROOM_LIGHT_LedStripList[ROOM_LIGHT_NofLedStrips] = {
        { ROOM_LIGHT_LedStrip1_Pin, ROOM_LIGHT_LedStrip1_NofLed},
        { ROOM_LIGHT_LedStrip2_Pin, ROOM_LIGHT_LedStrip2_NofLed},
        { ROOM_LIGHT_LedStrip3_Pin, ROOM_LIGHT_LedStrip3_NofLed},
        { ROOM_LIGHT_LedStrip4_Pin, ROOM_LIGHT_LedStrip4_NofLed},
    };

//--- Shadow Station ---------------------------------------
    // LED Strips define ------------------------------
    #define SBF_LEDRed_Pin       23
    #define SBF_LEDGreen_Pin     25
    #define SBF_LEDBlue_Pin      27
    #define SBF_LEDWarmWhite_Pin 29
    #define SBF_LEDColdWhite_Pin 31

#elif (ROOM_LIGHT == ROOM_LIGHT_Sennholz)
//--- Enable LightSource ---------------------------------- 
    #define LIGHT_SOURCE_EnableMap ((0x1 << LightSourceHdl::Source::RoomLight))
    

//--- Room Light ------------------------------------------
    // LED Matrix defines -----------------------------
    #define ROOM_LIGHT_NofRows  2
    #define ROOM_LIGHT_RowNofPx 32

    // LED Strips define ------------------------------
    #define ROOM_LIGHT_NofLedStrips 2

    #define ROOM_LIGHT_LedStrip1_Pin 22
    #define ROOM_LIGHT_LedStrip2_Pin 24

    #define ROOM_LIGHT_LedStrip1_NofLed 63
    #define ROOM_LIGHT_LedStrip2_NofLed 29

    const ledStrip_t ROOM_LIGHT_LedStripList[ROOM_LIGHT_NofLedStrips] = {
        { ROOM_LIGHT_LedStrip1_Pin, ROOM_LIGHT_LedStrip1_NofLed},
        { ROOM_LIGHT_LedStrip2_Pin, ROOM_LIGHT_LedStrip2_NofLed},
    };

//--- Shadow Station ---------------------------------------
    // LED Strips define ------------------------------
    #define SBF_LEDRed_Pin       23
    #define SBF_LEDGreen_Pin     25
    #define SBF_LEDBlue_Pin      27
    #define SBF_LEDWarmWhite_Pin 29
    #define SBF_LEDColdWhite_Pin 31

#else // ROOM_LIGHT_TestBoard
//--- Enable LightSource ---------------------------------- 
    #define LIGHT_SOURCE_EnableMap ((0x1 << LightSourceHdl::Source::RoomLight) | (0x1 << LightSourceHdl::Source::ShadowStation))
    

//--- Room Light ------------------------------------------
    // LED Matrix defines -----------------------------
    #define ROOM_LIGHT_NofRows  1
    #define ROOM_LIGHT_RowNofPx 14

    // LED Strips define ------------------------------
    #define ROOM_LIGHT_NofLedStrips 1

  #ifdef __AVR__
    #define ROOM_LIGHT_LedStrip1_Pin 22
  #else
    #define ROOM_LIGHT_LedStrip1_Pin A0
  #endif

    #define ROOM_LIGHT_LedStrip1_NofLed ROOM_LIGHT_RowNofPx

    const ledStrip_t ROOM_LIGHT_LedStripList[ROOM_LIGHT_NofLedStrips] = {
        { ROOM_LIGHT_LedStrip1_Pin, ROOM_LIGHT_LedStrip1_NofLed},
    };


//--- Shadow Station ---------------------------------------
    // LED Strips define ------------------------------
  #ifdef __AVR__
    #define SBF_LEDRed_Pin       25
    #define SBF_LEDGreen_Pin     27
    #define SBF_LEDBlue_Pin      23
    #define SBF_LEDWarmWhite_Pin 29
    #define SBF_LEDColdWhite_Pin 31
  #else
    #define SBF_LEDRed_Pin       3
    #define SBF_LEDGreen_Pin     2
    #define SBF_LEDBlue_Pin      4
    #define SBF_LEDWarmWhite_Pin 1
    #define SBF_LEDColdWhite_Pin 0
  #endif
#endif



//-----------------------------------------------------------------------------
// extern definition
extern const uint16_t LED_MATRIX_LUT[ROOM_LIGHT_NofRows][ROOM_LIGHT_RowNofPx];
extern byte mac[];
extern IPAddress ip;
extern IPAddress myDns;
extern IPAddress gateway;
extern IPAddress subnet;

#endif //_COMMON_H
