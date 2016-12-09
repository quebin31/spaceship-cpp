//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_IMAGE_H
#define SPACESHIP2_IMAGE_H


#include "bitmap.h"

class IMAGE : public BITMAP
{
  public:
    IMAGE(const char* file, const int nwidth, const int nheight);

    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};


#endif //SPACESHIP2_IMAGE_H
