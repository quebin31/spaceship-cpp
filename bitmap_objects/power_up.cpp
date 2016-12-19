//
// Created by kevin on 9/12/16.
//

#include "power_up.h"

/* =======================================================================================================================================================================*/

PowerUp* PowerUp::_instance = 0;

double PowerUp::generate_random_coord(const int x, const int y)
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_real_distribution<> distr(x,y);
  return distr(eng);
}

int PowerUp::generate_random_fps_count(const int i, const int j)
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(i,j);
  return distr(eng);
}

PowerUp::PowerUp(): Bitmap("power_up.png")
{
  width  = 40;
  height = 40;
  posX = generate_random_coord(70,410);
  posY = generate_random_coord(0,100);
  destroyed = true;
}

bool PowerUp::check_colision_with(Bitmap *some)
{
  if (this->posX + this->width >= some->getX() && this->posX <= some->getX() + some->getW())
    if (this->posY + this->height >= some->getY() && this->posY <= some->getY() + some->getH())
    {
      this->destroyed = true;
      return true;
    }
  return false;
}

void PowerUp::draw_bitmap(const int flags)
{ if (!destroyed) al_draw_bitmap(bitmap, float (posX), float (posY), flags); }

void PowerUp::reset_bitmap()
{
  posX = generate_random_coord(70,410);
  posY = generate_random_coord(0,100);
  destroyed = true;
}


/* =======================================================================================================================================================================*/
