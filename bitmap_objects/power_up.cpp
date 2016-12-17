//
// Created by kevin on 9/12/16.
//

#include "power_up.h"

int type_powerup[] = {0,30,60,90};

int POWER_UP::generate_random_power_up()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(0, 3);
  return distr(eng);
}

POWER_UP::POWER_UP(): Bitmap("power_up")
{
  width  = 30;
  height = 30;
  sourceX = generate_random_power_up();
  sourceY = 0;
}

void POWER_UP::draw_bitmap(const int flags)
{ al_draw_bitmap_region(bitmap, sourceX, sourceY, width, height, posX, posY, flags); }

void POWER_UP::reset_bitmap()
{
  sourceX = generate_random_power_up();
  sourceY = 0;
}

bool POWER_UP::check_colision_with(Bitmap *some)
{
  if (this->posX + this->width >= some->getX() && this->posX <= some->getX() + some->getW())
    if (this->posY + this->height >= some->getY() && this->posY <= some->getY() + some->getH())
    {
      this->destroyed = true;
      return true;
    }
  return false;
}


