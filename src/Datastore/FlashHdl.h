/*******************************************************************************
Project   RoomLight

  This is an OpenSource Project.
  You can use, share or improve this project. If you improve this source code
  please share with the comunity or at least with the author of the original 
  source code
  
  Created 25. April 2024 by MarkusNTrains
================================================================================
$HeadURL:  $
$Id:  $
*******************************************************************************/

#ifndef __AVR__
#ifndef _FLASH_HDL_H
#define _FLASH_HDL_H


//----------------------------------------------------------------------------
// include
#include "../common.h"
#include "Flash.h"
#include "StoreHdl.h"


//----------------------------------------------------------------------------
// class
class FlashHdl : public StoreHdl
{
    public:
        const static uint32_t NOF_BLOCKS = 256;
        const static uint32_t FLASH_STORE_SIZE = (NOF_BLOCKS * sizeof(StoreBlockData));
        const static uint32_t FLASH_RESERVED_SIZE = (FLASH_STORE_SIZE + (2 * Flash::ROW_SIZE));


        FlashHdl();
        ~FlashHdl();

        Error ReadBlock(uint8_t* data, uint32_t size, uint32_t offset);
        Error WriteToNextBlock(uint8_t* data, uint32_t size);

    private:
        uint16_t m_active_block_idx;
        uint16_t m_write_cnt;
        uint32_t m_last_row_addr;
        StoreBlockInfo* m_block_a[NOF_BLOCKS];

        bool FindNewestBlock();
        void EraseWholeWritableFlash();
        void EraseRow(uint32_t row_addr);
};


const static uint8_t FLASH_WritableArea[FlashHdl::FLASH_RESERVED_SIZE] = { 0xFF };
const static uint32_t FLASH_StartAddress = ((((((uint32_t)&FLASH_WritableArea) - 1) / Flash::ROW_SIZE) * Flash::ROW_SIZE) + Flash::ROW_SIZE);


#endif // _FLASH_HDL_H
#endif // __AVR__