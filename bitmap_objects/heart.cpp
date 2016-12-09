//
// Created by kevin on 7/12/16.
//

#include "heart.h"

HEART::HEART(): BITMAP("lifes.png")
{
  width = 30;
  height = 30;
  sourceX = HEART_ALIVE;
  sourceY = 0;
}

void HEART::broken_heart()
{
  sourceX = HEART_DEAD;
  destroyed = true;
}

void HEART::draw_bitmap(const int flags)
{
  al_draw_bitmap_region(bitmap,sourceX,sourceY,width,height,posX,posY,flags);
}

void HEART::reset_bitmap()
{
  sourceX = HEART_ALIVE;
  destroyed = false;
}
