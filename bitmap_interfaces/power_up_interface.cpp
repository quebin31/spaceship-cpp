//
// Created by kevin on 19/12/16.
//

#include "power_up_interface.h"
/* =======================================================================================================================================================================*/

int PowerUpInterface::fps_to_gen = PowerUp::_instance->generate_random_fps_count(400, 550);
int PowerUpInterface::moveDX = 3;

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
    fps_to_gen = PowerUp::_instance->generate_random_fps_count(400,500) + 1504;
  }

  if (PowerUp::_instance->getY() >= 480)
  {
    PowerUp::_instance->reset_bitmap();
    fps_to_gen = PowerUp::_instance->generate_random_fps_count(400,500) + 200;
    return;
  }

  if (!PowerUp::_instance->getDestroyed())
  {
    if (actual_count_frames%30 == 0)
      moveDX = -moveDX;
    PowerUp::_instance->moveX(moveDX);
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
      break;
    case LASER_TYPE:
      BulletInterface::changeType(generate_random_type_except(LASER_TYPE));
      break;
  }
}
#pragma clang diagnostic pop

PowerUp *PowerUpInterface::Instance()
{ return PowerUp::_instance; }

/* =======================================================================================================================================================================*/
