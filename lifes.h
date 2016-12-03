#ifndef LIFES_H
#define LIFES_H

#include "bitmap.h"

using namespace std;

class LIFE: public BITMAP{
  protected:
    bool status;
  public:
    LIFE();
    void draw_life();
};

#endif // LIFES_H
