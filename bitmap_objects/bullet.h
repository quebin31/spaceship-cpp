//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_BULLET_H
#define SPACESHIP2_BULLET_H


#include "bitmap.h"

class BULLET : public Bitmap
{
  public:
    BULLET(const char*, int, int);

    bool check_colision_with(Bitmap *some) override;
    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};


#endif //SPACESHIP2_BULLET_H
