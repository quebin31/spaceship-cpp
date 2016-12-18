//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_BULLET_H
#define SPACESHIP2_BULLET_H


#include "bitmap.h"

class BaseBullet : public Bitmap
{
  public:
    BaseBullet(const char* file);
};

class Bullet: public BaseBullet
{
  public:
    Bullet();

    bool check_colision_with(Bitmap *some) override;
    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};

class Laser : public BaseBullet
{
  public:
    Laser();

    bool check_colision_with(Bitmap *some) override;
    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};

#endif //SPACESHIP2_BULLET_H
