#ifndef LIFES_H
#define LIFES_H

#include "allegro_includes.h"
#include "bitmap.h"

#define NO_OF_HEARTS 3

#define HEART_ALIVE 0
#define HEART_DEAD  30

using namespace std;

class LIFE: public BITMAP
{
  public:
    LIFE();
    void draw_life();
    void lost_life();
    void recovery_life();
};

class LIFES
{
  private:
    vector<LIFE*> lifes;
  public:
    LIFES();
    ~LIFES();

    void draw_lifes();
    void lost_a_life();
};

#endif // LIFES_H
