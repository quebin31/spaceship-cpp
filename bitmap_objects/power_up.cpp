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

PowerUp::PowerUp(): Bitmap("power_up.png")
{
  width  = 40;
  height = 40;
  posX = generate_random_coord(40,440);
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
  posX = generate_random_coord(40,440);
  posY = generate_random_coord(0,100);
  destroyed = true;
}

/* =======================================================================================================================================================================*/



void PowerUpInterface::createPowerUpInstance()
{ if (!PowerUp::_instance) PowerUp::_instance = new PowerUp; }

int PowerUpInterface::generate_random_type_except(const int excpt)
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(0,1);

  int rand_type = distr(eng);
  while (rand_type == excpt)
    rand_type = distr(eng);

  return rand_type;
}

void PowerUpInterface::deletePowerUpInstance()
{ delete PowerUp::_instance; }

void PowerUpInterface::updatePowerUp(int64_t actual_count_frames)
{
  if (PowerUp::_instance->getDestroyed() && actual_count_frames%150 == 0)
    PowerUp::_instance->setDestroyed(false);

  if (!PowerUp::_instance->getDestroyed())
  {
    PowerUp::_instance->moveX(PowerUp::_instance->generate_random_coord(2, 6));
    PowerUp::_instance->moveY(PowerUp::_instance->generate_random_coord(2, 3));
  }
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "missing_default_case"
void PowerUpInterface::changeType()
{
  int type = BulletInterface::returnType();
  switch (type)
  {
    case BULLET_TYPE:
      BulletInterface::changeType(generate_random_type_except(BULLET_TYPE));
    case LASER_TYPE:
      BulletInterface::changeType(generate_random_type_except(LASER_TYPE));
  }
}
#pragma clang diagnostic pop

PowerUp *PowerUpInterface::Instance()
{ return PowerUp::_instance; }

/* =======================================================================================================================================================================*/

//
//
//int PowerUpOld::generate_random_power_up(int x,int y)
//{
//  std::random_device randomDevice;
//  std::mt19937 eng(randomDevice());
//  std::uniform_int_distribution<> distr(x, y);
//  return distr(eng);
//}
//
//PowerUpOld::PowerUpOld(): Bitmap("power_up.png")
//{
//  width  = 40;
//  height = 40;
//  posX = generate_random_power_up(0, 550);
//  posY = generate_random_power_up(60, 200);
//  sourceY = 0;
//  pun = false;
//  destroyed_at = 0;
//  destroyed = true;
//  state = 0;
//}
//
//PowerUpOld::~PowerUpOld(){
//  delete power_up;
//}
//
//PowerUpOld *PowerUpOld::instance()
//{
//  if (!power_up)
//    power_up = new PowerUpOld;
//  return power_up;
//}
//
//void PowerUpOld::draw_bitmap(const int flags)
//{
//  if (!destroyed)
//    al_draw_bitmap(bitmap,float (posX),float (posY),0);
//}
//
//void PowerUpOld::reset_bitmap()
//{
//  posX = generate_random_power_up(0, 550);
//  posY = generate_random_power_up(60, 200);
//  destroyed = false;
//}
//
//bool PowerUpOld::check_colision_with(Bitmap *some)
//{
//  if (posX + width >= some->getX() && posX <= some->getX() + some->getW())
//    if (posY + height >= some->getY() && posY <= some->getY() + some->getH())
//    {
//      generate_state();
//      destroyed = true;
//      return true;
//    }
//  return false;
//}
//
//void PowerUpOld::generate_state(){
//  state = generate_random_power_up(0,strategy_power_up::Instance()->get_guns_size()-1);
//}
//
//int PowerUpOld::get_state() {return state;}
//
//int64_t PowerUpOld::get_destroyed_at() {return destroyed_at;}
//
//void PowerUpOld::set_destroyed_at(int64_t val) {destroyed_at=val;}
//
//PowerUpOld* PowerUpOld::power_up = 0;
