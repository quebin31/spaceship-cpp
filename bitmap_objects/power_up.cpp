//
// Created by kevin on 9/12/16.
//

#include "power_up.h"

int type_powerup[] = {0,30,60,90};

int PowerUp::generate_random_power_up(int x,int y)
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(x, y);
  return distr(eng);
}

PowerUp::PowerUp(): Bitmap("power_up.png")
{
  width  = 40;
  height = 40;
  posX = generate_random_power_up(0, 550);
  posY = generate_random_power_up(60, 200);
  sourceY = 0;
  pun = false;
  destroyed_at = 0;
  destroyed = true;
  state = 0;
}

PowerUp::~PowerUp(){
  delete power_up;
}

PowerUp *PowerUp::instance()
{
  if (!power_up)
    power_up = new PowerUp;
  return power_up;
}

void PowerUp::draw_bitmap(const int flags)
{
  if (!destroyed)
    al_draw_bitmap(bitmap,float (posX),float (posY),0);
}

void PowerUp::reset_bitmap()
{
  posX = generate_random_power_up(0, 550);
  posY = generate_random_power_up(60, 200);
  destroyed = false;
}

bool PowerUp::check_colision_with(Bitmap *some)
{
  if (posX + width >= some->getX() && posX <= some->getX() + some->getW()){
    if (posY + height >= some->getY() && posY <= some->getY() + some->getH()){
      generate_state();
      destroyed = true;
      return true;
    }
  }
  return false;
}

void PowerUp::generate_state(){
  state = generate_random_power_up(0,strategy_power_up::Instance()->get_guns_size()-1);
}

int PowerUp::get_state() {return state;}

int64_t PowerUp::get_destroyed_at() {return destroyed_at;}

void PowerUp::set_destroyed_at(int64_t val) {destroyed_at=val;}

PowerUp* PowerUp::power_up = 0;
