//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_NAVE_H
#define SPACESHIP2_NAVE_H

#include "bitmap.h"

#define NAVE_UP    0
#define NAVE_RIGHT 32
#define NAVE_LEFT  64

class NAVE_GUN;

class NAVE : public BITMAP
{
  private:
    NAVE_GUN   *nave_gun;
    int64_t     destroyed_at;
  public:
    NAVE();
    ~NAVE() override;

    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;

    void shoot_gun();
    void update_bullets();
    void make_invulnerable(const int64_t fps_count);
    void make_vulnerable();
    int64_t getWhenDestroyed();


    NAVE_GUN* getGun();
};


#endif //SPACESHIP2_NAVE_H
