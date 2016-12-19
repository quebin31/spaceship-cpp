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

#endif //SPACESHIP2_POWER_UP_H
