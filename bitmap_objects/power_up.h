//
// Created by kevin on 9/12/16.
//

#ifndef SPACESHIP2_POWER_UP_H
#define SPACESHIP2_POWER_UP_H

#include "../bitmap_objects/nave.h"

extern int type_powerup[];

class POWER_UP : public BITMAP
{
  private:
    int generate_random_power_up();
    static POWER_UP* power_up;

  public:
    POWER_UP();
    ~POWER_UP();
    static POWER_UP* instance(){
      if(!power_up)
        power_up = new POWER_UP;
      return power_up;
    }
    bool check_colision_with(BITMAP *some) override;
    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
    bool aprove(int64_t)
};


#endif //SPACESHIP2_POWER_UP_H
