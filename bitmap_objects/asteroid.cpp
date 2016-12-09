//
// Created by kevin on 7/12/16.
//

#include "asteroid.h"

int type_asters[] = {0,45,90,135,180};

int ASTEROID::generate_random_type()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(0, 5);
  return distr(eng);
}

int ASTEROID::generate_random_X()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(30, 490);
  return distr(eng);
}

int ASTEROID::generate_random_Y()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(0, 30);
  return distr(eng);
}

ASTEROID::ASTEROID(): BITMAP("asteroides.png")
{
  width    = 45;
  height   = 45;
  posX     = (double) generate_random_X();
  posY     = (double) generate_random_Y();
  int type = generate_random_type();
  sourceX  = type_asters[type];
}

bool ASTEROID::check_colision_with(BITMAP *some)
{
  if (this->posX + this->width >= some->getX() && this->posX <= some->getX() + some->getW())
  {
    if (this->posY + this->height >= some->getY() && this->posY <= some->getY() + some->getH())
    {
      this->destroyed = true;
      some->setDestroyed(true);
      return true;
    }
  }
  return false;
}

void ASTEROID::draw_bitmap(const int flags)
{
  al_draw_bitmap_region(bitmap,sourceX,sourceY,width,height,posX,posY,flags);
}

void ASTEROID::reset_bitmap()
{
  posX      = generate_random_X();
  posY      = generate_random_Y();
  int type  = generate_random_type();
  sourceX   = type_asters[type];
  destroyed = false;
}

