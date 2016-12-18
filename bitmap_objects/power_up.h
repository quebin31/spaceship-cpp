//
// Created by kevin on 9/12/16.
//

#ifndef SPACESHIP2_POWER_UP_H
#define SPACESHIP2_POWER_UP_H

#include "../bitmap_objects/nave.h"

extern int type_powerup[];

class PowerUp : public Bitmap
{
  private:
    int generate_random_power_up(int, int);
    static PowerUp* power_up;
    int64_t destroyed_at;
    int state;
  public:
    PowerUp();
    ~PowerUp();

    static PowerUp* instance();

    bool check_colision_with(Bitmap *some) override;
    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
    int64_t get_destroyed_at();
    void set_destroyed_at(int64_t );
    bool pun;
    int get_state();
    void generate_state();
};


#endif //SPACESHIP2_POWER_UP_H
