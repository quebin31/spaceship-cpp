//
// Created by kevin on 19/12/16.
//

#ifndef SPACESHIP2_POWER_UP_INTERFACE_H
#define SPACESHIP2_POWER_UP_INTERFACE_H

#include "../bitmap_objects/power_up.h"


class PowerUpInterface
{
  private:
    static int fps_to_gen;
    static int moveDX;
  private:
    static int generate_random_type_except(const int excpt);

  public:
    static void createPowerUpInstance();
    static void deletePowerUpInstance();

    static void updatePowerUp(const int64_t actual_count_frames);
    static void changeType();

    static PowerUp* Instance();
};


#endif //SPACESHIP2_POWER_UP_INTERFACE_H
