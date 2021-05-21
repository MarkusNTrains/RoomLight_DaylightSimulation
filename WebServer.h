/*******************************************************************************
Project   Train TimeTable

  This is an OpenSource Project.
  You can use, share or improve this project. If you improve this source code
  please share with the comunity or at least with the author of the original 
  source code
  
  Created 09. May 2019 by MarkusNTrains
================================================================================
$HeadURL:  $
$Id:  $
*******************************************************************************/


#ifndef _WEB_SERVER_H
#define _WEB_SERVER_H


//----------------------------------------------------------------------------
// include
#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>
#include "common.h"
#include "LedScene.h"



//----------------------------------------------------------------------------
// define
#define REQ_BUF_SZ 100  // size of buffer used to capture HTTP requests


//----------------------------------------------------------------------------
// class
class WebServer
{
	public:
		WebServer(LedScene* led_scene);
		~WebServer();
        void Tasks(void);		
		
	private:
        typedef enum {
            ACTION_SetLightSecene = 0,
            ACTION_SetBrightness,
            ACTION_SetLedArea,
            ACTION_Unknown
        } action_t;
        
        EthernetServer* m_server;
		File webFile;                     // the web page file on the SD card
		char HTTP_req[REQ_BUF_SZ] = {0};  // buffered HTTP request stored as null terminated string
		char req_index = 0;               // index into HTTP_req buffer
		unsigned char LED_state[3] = {0}; // stores the states of the LEDs, 1 bit per LED
        LedScene* m_led_scene;
        action_t m_action;

		void HandleRequest(void);
		void XML_response(EthernetClient cl);
		void StrClear(char *str, char length);
		char StrContains(char *str, char *sfind);   
};

#endif  // _WEB_SERVER_H
