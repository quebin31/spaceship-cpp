//
// Created by kevin on 9/12/16.
//

#ifndef SPACESHIP2_POWER_UP_H
#define SPACESHIP2_POWER_UP_H

#include "../bitmap_interfaces/bullet_interface.h"
#include "bitmap.h"

class PowerUp;
class PowerUpInterface;

class PowerUp : public Bitmap
{
  private:
    double generate_random_coord(const int x, const int y);
    int    generate_random_fps_count(const int i, const int j);

  private:
    static PowerUp* _instance;
    PowerUp();

  private:
    friend class PowerUpInterface;

  public:
    bool check_colision_with(Bitmap *some) override;
    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};

class PowerUpInterface
{
  private:
    static int fps_to_gen;
  private:
    static int generate_random_type_except(const int excpt);

  public:
    static void createPowerUpInstance();
    static void deletePowerUpInstance();

    static void updatePowerUp(const int64_t actual_count_frames);
    static void changeType();

    static PowerUp* Instance();
};

#endif //SPACESHIP2_POWER_UP_H
