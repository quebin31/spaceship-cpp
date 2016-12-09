//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_BULLET_H
#define SPACESHIP2_BULLET_H


#include "bitmap.h"

class BULLET : public BITMAP
{
  public:
    BULLET();

    bool check_colision_with(BITMAP *some) override;
    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};


#endif //SPACESHIP2_BULLET_H
