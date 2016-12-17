//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_HEART_H
#define SPACESHIP2_HEART_H

#include "bitmap.h"

#define HEART_ALIVE 0
#define HEART_DEAD  30

class HEART : public Bitmap
{
  public:
    HEART();

    void broken_heart();

    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};


#endif //SPACESHIP2_HEART_H
