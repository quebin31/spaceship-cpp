//
// Created by kevin on 9/12/16.
//

#ifndef SPACESHIP2_POWER_UP_H
#define SPACESHIP2_POWER_UP_H

#include "bitmap.h"

extern int type_powerup[];

class POWER_UP : public BITMAP
{
  private:
    int generate_random_power_up();
    static POWER_UP* power_up;

  public:
    POWER_UP();
    static POWER_UP* instance();
    bool check_colision_with(BITMAP *some) override;
    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};


#endif //SPACESHIP2_POWER_UP_H
