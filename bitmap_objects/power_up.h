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
    int64_t destroyed_at;

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
    int64_t get_destroyed_at();
    void set_destroyed_at(int64_t );
    bool pun;
};


#endif //SPACESHIP2_POWER_UP_H
