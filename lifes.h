#ifndef LIFES_H
#define LIFES_H

#include <vector>
#include "bitmap.h"
#define movex 20

using namespace std;

class LIFE:public BITMAP{
protected:
  bool status;
public:
  LIFE();
};

class SET_OF_HEARTS:public LIFE{
protected:
  vector<LIFE*> HEARTS;
public:
  SET_OF_HEARTS();
  ~SET_OF_HEARTS();
};

#endif // LIFES_H
