//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_NAVE_H
#define SPACESHIP2_NAVE_H

#include "bitmap.h"
#include "../bitmap_interfaces/bullet_interface.h"

#define NAVE_UP    0
#define NAVE_RIGHT 32
#define NAVE_LEFT  64


class Nave : public Bitmap
{
  private:
    int64_t destroyed_at;

  private:
    static Nave *_instance;
    Nave();

  public:
    static Nave* Instance();
    static void  deleteNave();

  public:
    void shootGun();

    void    make_invulnerable(const int64_t fps_count);
    void    make_vulnerable();
    int64_t getWhenDestroyed();

    bool check_colision_with(Bitmap *some) override;
    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};


#endif //SPACESHIP2_NAVE_H
