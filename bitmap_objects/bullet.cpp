//
// Created by kevin on 7/12/16.
//

#include "bullet.h"

/* =======================================================================================================================================================================*/

BaseBullet::BaseBullet(const char* file): Bitmap(file) {}

/* =======================================================================================================================================================================*/

Bullet::Bullet(): BaseBullet("bullet2.png")
{
  type = BULLET_TYPE;
  width  = 10;
  height = 10;
}

bool Bullet::check_colision_with(Bitmap *some)
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

void Bullet::draw_bitmap(const int flags)
{ al_draw_bitmap(bitmap,float (posX), float (posY), flags); }

void Bullet::reset_bitmap()
{
  posX      = 0;
  posY      = 0;
  destroyed = false;
}


/* =======================================================================================================================================================================*/

Laser::Laser(): BaseBullet("laser.png")
{
  type = LASER_TYPE;
  width  = 10;
  height = 39;
}

bool Laser::check_colision_with(Bitmap *some)
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

void Laser::draw_bitmap(const int flags)
{ al_draw_bitmap(bitmap, float(posX), float(posY), flags);}

void Laser::reset_bitmap()
{
  posX = 0;
  posY = 0;
  destroyed = false;
}

/* =======================================================================================================================================================================*/

BaseBullet *BulletConverter::convert_to(BaseBullet *baseB, const int new_type)
{
  if (baseB->type == new_type)
    return baseB;

  if (new_type == BULLET_TYPE)
  {
    baseB->type = BULLET_TYPE;
    baseB->changeBitmap("bullet2.png");
  }
  else if (new_type == LASER_TYPE)
  {
    baseB->type = LASER_TYPE;
    baseB->changeBitmap("laser.png");

  }
  return baseB;
}

/* =======================================================================================================================================================================*/