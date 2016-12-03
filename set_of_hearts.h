#ifndef SET_OF_HEARTS_H
#define SET_OF_HEARTS_H
#include "lifes.h"
#define times 3

using namespace std;

class SET_OF_HEARTS: public LIFE{
private:
  vector<LIFE*> hearts;
public:
  SET_OF_HEARTS();
  ~SET_OF_HEARTS();
  void init_hearts();
  void draw_hearts();
};

#endif // SET_OF_HEARTS_H
