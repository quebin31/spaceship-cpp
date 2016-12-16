//
// Created by kevin on 9/12/16.
//

#include "power_up.h"

int type_powerup[] = {0,30,60,90};

int POWER_UP::generate_random_power_up()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(60, 200);
  return distr(eng);
}

POWER_UP::POWER_UP(): BITMAP("power_up.png")
{
  width  = 40;
  height = 40;
  //posX = generate_random_power_up();
  posX = generate_random_power_up();
  posY = generate_random_power_up();
  sourceY = 0;
}

POWER_UP::~POWER_UP(){
  delete power_up;
}

void POWER_UP::draw_bitmap(const int flags)
{
  if (destroyed == false)
    al_draw_bitmap(bitmap,posX,posY,0);
}

void POWER_UP::reset_bitmap()
{
  posX = generate_random_power_up();
  posY = generate_random_power_up();
}

bool POWER_UP::check_colision_with(BITMAP *some)
{
  if (posX + width >= some->getX() && posX <= some->getX() + some->getW()){
    if (posY + height >= some->getY() && posY <= some->getY() + some->getH()){
      destroyed = true;
      reset_bitmap();
      return true;
    }
  }
  return false;
}

POWER_UP* POWER_UP::power_up = 0;
