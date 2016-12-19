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

int PowerUpInterface::fps_to_gen = PowerUp::_instance->generate_random_fps_count(250, 350);

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

void PowerUpInterface::createPowerUpInstance()
{ if (!PowerUp::_instance) PowerUp::_instance = new PowerUp; }

void PowerUpInterface::deletePowerUpInstance()
{ delete PowerUp::_instance; }

void PowerUpInterface::updatePowerUp(const int64_t actual_count_frames)
{
  if (PowerUp::_instance->getDestroyed() && actual_count_frames%fps_to_gen== 0)
  {
    PowerUp::_instance->setDestroyed(false);
    fps_to_gen = PowerUp::_instance->generate_random_fps_count(350,400);
  }

  if (!PowerUp::_instance->getDestroyed())
  {
    if (actual_count_frames%8 == 0)
    {
      double randx = PowerUp::_instance->generate_random_coord(-3, 3);
      randx = (randx < 0) ? -8 : 8;
      PowerUp::_instance->moveX(randx);
    }
    PowerUp::_instance->moveY(PowerUp::_instance->generate_random_coord(2,3));
    PowerUp::_instance->draw_bitmap(0);
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
