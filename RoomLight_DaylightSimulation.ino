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



//-----------------------------------------------------------------------------
// includes
#include "src/common.h"
#include "src/LightSourceHdl.h"
#include "src/Webserver/WebServer.h"

#ifdef __AVR__
  #include <avr/wdt.h>
#else
  // install Sodaq_wdt library by GabrielNotman version v1.0.2 or higher
  #include <Sodaq_wdt.h>
#endif


//-----------------------------------------------------------------------------
// defines


//-----------------------------------------------------------------------------
// extern


//-----------------------------------------------------------------------------
// static module variable
static LightSourceHdl* s_lightSourceHdl_p;
static WebServer* s_webServer_p;

#if (IS_DEBUG_MODE == ON)
const static uint32_t MAIN_PrintFreeMemoryTmoMs = 2000ul;
static uint32_t s_main_printFreeMemoryTimestampMs = 0;
#endif


//-----------------------------------------------------------------------------
// function prototype
uint16_t GetAvailableMemory();



//*****************************************************************************
// description:
//   initialize
//*****************************************************************************
void setup()
{
#if (IS_DEBUG_MODE == ON)
    Serial.begin(115200);       // for debugging
    uint32_t find_serial_timestamp_ms = millis();
    while (!Serial) 
    { 
        // wait for serial port to connect. Needed for native USB port only
        if (millis() - find_serial_timestamp_ms > 10000)
        {
            // exit loop if serial connection did not work
            break;
        }
    }

    Serial.println(F("\n\n************************************"));
    Serial.println(F("Start Room Light"));
    Serial.print(F("Free Memory: "));
    Serial.println(GetAvailableMemory());
    //delay(50);
 #endif

    //--- enable watchdog ---
#ifdef __AVR__
    wdt_enable(WDTO_8S);
    uint32_t cpuFreq = F_CPU;
#else
    sodaq_wdt_enable(WDT_PERIOD_8X);
    uint32_t cpuFreq = SystemCoreClock;
#endif

    //--- init objects ---
    s_lightSourceHdl_p = new LightSourceHdl();
    s_webServer_p = new WebServer(s_lightSourceHdl_p);

    //--- print memory usage ---
#if (IS_DEBUG_MODE == ON)
    Serial.print("CPU-Frequenz: ");
    Serial.print(cpuFreq);
    Serial.println(" Hz");

    s_main_printFreeMemoryTimestampMs = millis();
    Serial.print(F("Free Memory: "));
    Serial.println(GetAvailableMemory());
#endif
}


//*****************************************************************************
// description:
//   Statemachine
//*****************************************************************************
void loop()
{
    s_lightSourceHdl_p->Tasks();
    s_webServer_p->Tasks();

#ifdef __AVR__
    wdt_reset();
#else
    sodaq_wdt_reset();
#endif


#if (IS_DEBUG_MODE == ON)
    if (millis() - s_main_printFreeMemoryTimestampMs > MAIN_PrintFreeMemoryTmoMs)
    {
        s_main_printFreeMemoryTimestampMs = millis();
        //Serial.print(F("Free Memory: "));
        //Serial.println(GetAvailableMemory());
    }
#endif
}


//*****************************************************************************
// description:
//   GetAvailableMemory
//*****************************************************************************
#if (IS_DEBUG_MODE == ON)
uint16_t GetAvailableMemory() 
{
    // Use 1024 with ATmega168
    uint16_t size = 8192; // SRAM size of target
    byte *buf;
    while ((buf = (byte *) malloc(--size)) == NULL);
        free(buf);

    return size;
}
#endif


