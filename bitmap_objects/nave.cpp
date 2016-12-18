//
// Created by kevin on 7/12/16.
//

#include "nave.h"
#include "../bitmap_interfaces/bullet_interface.h"

/* =======================================================================================================================================================================*/

Nave* Nave::_instance = 0;

Nave::Nave(): Bitmap("nave1.png")
{
  width        = 32;
  height       = 32;
  sourceX      = NAVE_UP;
}

Nave *Nave::Instance()
{
  if (!_instance)
    _instance = new Nave;
  return _instance;
}

void Nave::deleteNave()
{ delete Nave::Instance(); }


/* =======================================================================================================================================================================*/

void Nave::shootGun()
{ BulletInterface::createBullet(posX, posY); }

/* =======================================================================================================================================================================*/

void Nave::make_invulnerable(const int64_t fps_count)
{
  destroyed    = true;
  destroyed_at = fps_count;
  BulletInterface::decGunScoreIn(30);
}

void Nave::make_vulnerable()
{ destroyed = false; }

int64_t Nave::getWhenDestroyed()
{ return destroyed_at; }

/* =======================================================================================================================================================================*/

void Nave::draw_bitmap(const int flags)
{ al_draw_bitmap_region(bitmap, sourceX, sourceY, width, height, float (posX), float (posY), flags); }

void Nave::reset_bitmap()
{
  posX         = 0;
  posY         = 0;
  sourceX      = NAVE_UP;
  sourceY      = 0;
  destroyed    = false;
  destroyed_at = 0;
}

bool Nave::check_colision_with(Bitmap *some) { return false; }

/* =======================================================================================================================================================================*/
