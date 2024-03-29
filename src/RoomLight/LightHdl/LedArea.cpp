/*******************************************************************************
Project   RoomLight

  This is an OpenSource Project.
  You can use, share or improve this project. If you improve this source code
  please share with the comunity or at least with the author of the original 
  source code
  
  Created 4. November 2021 by MarkusNTrains
================================================================================
$HeadURL:  $
$Id:  $
*******************************************************************************/


//-----------------------------------------------------------------------------
// includes
#include "LedArea.h"



//*****************************************************************************
// description:
//   constructor
//*****************************************************************************
LedArea::LedArea()
{
    m_xs = 0;
    m_xe = 0;
    m_ys = 0;
    m_ye = 0;
}


//*****************************************************************************
// description:
//   destructor
//*****************************************************************************
LedArea::~LedArea()
{
}


//*****************************************************************************
// description:
//   GetColumnStart
//*****************************************************************************
uint16_t LedArea::GetColumnStart()
{
    return this->m_xs;
}


//*****************************************************************************
// description:
//   GetColumnEnd
//*****************************************************************************
uint16_t LedArea::GetColumnEnd()
{
    return this->m_xe;
}
        

//*****************************************************************************
// description:
//   GetRowStart
//*****************************************************************************
uint16_t LedArea::GetRowStart()
{
    return this->m_ys;
}


//*****************************************************************************
// description:
//   GetRowEnd
//*****************************************************************************
uint16_t LedArea::GetRowEnd()
{
    return this->m_ye;
}


//*****************************************************************************
// description:
//   Get
//*****************************************************************************
void LedArea::Get(LedArea* area)
{
    area->m_xs = this->m_xs;
    area->m_xe = this->m_xe;
    area->m_ys = this->m_ys;
    area->m_ye = this->m_ye;
}


//*****************************************************************************
// description:
//   Set
//*****************************************************************************
void LedArea::Set(LedArea* area)
{
    this->Set(area->m_xs, area->m_xe, area->m_ys, area->m_ye);
}


//*****************************************************************************
// description:
//   Set
//*****************************************************************************
void LedArea::Set(uint16_t xs, uint16_t xe, uint16_t ys, uint16_t ye)
{
    this->m_xs = xs;
    this->m_xe = xe;
    this->m_ys = ys;
    this->m_ye = ye;
}


