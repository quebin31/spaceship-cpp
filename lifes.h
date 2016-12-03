#ifndef LIFES_H
#define LIFES_H

#include "allegro_includes.h"
#include "bitmap.h"
#define n_hearts 3
using namespace std;

class LIFE: public BITMAP{
  protected:
    bool status;
  public:
    LIFE();
    void draw_life();
};

#endif // LIFES_H
