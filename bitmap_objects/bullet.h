//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_BULLET_H
#define SPACESHIP2_BULLET_H


#include "bitmap.h"

#define BULLET_TYPE 0
#define LASER_TYPE  1

class BulletConverter;

class BaseBullet : public Bitmap
{
  protected:
    int type;

    friend class BulletConverter;
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


class BulletConverter
{
  public:
    static BaseBullet* convert_to(BaseBullet* baseB, const int new_type);
};

#endif //SPACESHIP2_BULLET_H
