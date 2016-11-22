//
// Created by kevin on 21/11/16.
//

#ifndef GAMENAVE_ASTEROID_H
#define GAMENAVE_ASTEROID_H

#include "game.h"
#include "bitmap.h"

#define NO_1  0
#define NO_2  45
#define NO_3  90
#define NO_4  135
#define NO_5  180

class ASTEROID: public BITMAP {
private:
public:
  ASTEROID(const char* file);

  void draw_asteoid(const int _asteroid_no);
};


#endif //GAMENAVE_ASTEROID_H
