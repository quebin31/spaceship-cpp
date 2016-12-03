#ifndef LIFES_H
#define LIFES_H

#include "bitmap.h"
#include <vector>
using namespace std;

class LIFE: public BITMAP{
  protected:
    bool status;
  public:
    LIFE();
    void draw_life();
};

class SET_OF_HEARTS: public LIFE{
private:
  vector<LIFE*> hearts;
public:
  SET_OF_HEARTS();
  ~SET_OF_HEARTS();
  void draw_hearts();
};

#endif // LIFES_H
