//
// Created by kevin on 21/11/16.
//

#ifndef GAMENAVE_ASTEROID_H
#define GAMENAVE_ASTEROID_H

#include "bitmap.h"

#define NO_1  0
#define NO_2  45
#define NO_3  90
#define NO_4  135
#define NO_5  180

using namespace std;

extern int myAster[];
extern vector<int> type_of_asters;

class ASTEROID: public BITMAP
{
public:
  bool destroyed;

  ASTEROID(const int _no_asteroid);
  void draw_asteroid(const int _asteroid_no) const;
  void draw_asteroid() const;
};


#endif //GAMENAVE_ASTEROID_H
