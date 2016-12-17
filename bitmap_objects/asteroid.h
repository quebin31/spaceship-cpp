//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_ASTEROID_H
#define SPACESHIP2_ASTEROID_H

#include "bitmap.h"

//extern int type_asters[];

class Asteroid : public Bitmap
{
  private:
    static int type_asters[];

  private:
    int generate_random_type();
    double generate_random_X();
    double generate_random_Y();

  public:
    Asteroid();

    bool check_colision_with(Bitmap *some) override;
    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};



#endif //SPACESHIP2_ASTEROID_H
