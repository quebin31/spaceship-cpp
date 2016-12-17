//
// Created by kevin on 9/12/16.
//

#ifndef SPACESHIP2_POWER_UP_H
#define SPACESHIP2_POWER_UP_H

#include "bitmap.h"

extern int type_powerup[];

class POWER_UP : public Bitmap
{
  private:
    int generate_random_power_up();

  public:
    POWER_UP();

    bool check_colision_with(Bitmap *some) override;
    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};


#endif //SPACESHIP2_POWER_UP_H
