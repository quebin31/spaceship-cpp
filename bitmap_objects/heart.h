//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_HEART_H
#define SPACESHIP2_HEART_H

#include "bitmap.h"

#define HEART_ALIVE 0
#define HEART_DEAD  30

class Heart : public Bitmap
{
  public:
    Heart();

    void broken_heart();

    bool check_colision_with(Bitmap *some) override;

    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};


#endif //SPACESHIP2_HEART_H
