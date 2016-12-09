//
// Created by kevin on 7/12/16.
//

#include "bullet.h"

BULLET::BULLET(): BITMAP("bullet2.png")
{
  width = 10;
  height = 10;
}

bool BULLET::check_colision_with(BITMAP *some)
{
  if (this->posX + this->width >= some->getX() && this->posX <= some->getX() + some->getW())
    if (this->posY + this->height >= some->getY() && this->posY <= some->getY() + some->getH())
    {
      this->destroyed = true;
      some->setDestroyed(true);
      return true;
    }
  return false;
}

void BULLET::draw_bitmap(const int flags)
{
  al_draw_bitmap(bitmap,posX,posY,flags);
}

void BULLET::reset_bitmap()
{
  posX = 0;
  posY = 0;
  destroyed = false;
}
