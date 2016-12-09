//
// Created by kevin on 7/12/16.
//

#include "nave.h"
#include "../bitmap_interfaces/bullet_interface.h"

NAVE::NAVE(): BITMAP("nave1.png")
{
  nave_gun     = new NAVE_GUN;
  width        = 32;
  height       = 32;
  sourceX      = NAVE_UP;
}

NAVE::~NAVE()
{
  al_destroy_bitmap(bitmap);
  delete nave_gun;
}

void NAVE::draw_bitmap(const int flags)
{
  al_draw_bitmap_region(bitmap, sourceX, sourceY, width, height, posX, posY, flags);
}

void NAVE::shoot_gun()
{
  nave_gun->create_bullet(posX, posY);
}

void NAVE::update_bullets()
{
  nave_gun->update_bullets();
}

NAVE_GUN *NAVE::getGun()
{
  return nave_gun;
}

void NAVE::reset_bitmap()
{
  posX         = 0;
  posY         = 0;
  sourceX      = NAVE_UP;
  sourceY      = 0;
  destroyed    = false;
  destroyed_at = 0;
}

void NAVE::make_invulnerable(const int64_t fps_count)
{
  destroyed    = true;
  destroyed_at = fps_count;
}

int64_t NAVE::getWhenDestroyed() { return destroyed_at; }

void NAVE::make_vulnerable() { destroyed    = false; }



