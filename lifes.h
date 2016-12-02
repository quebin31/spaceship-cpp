#ifndef LIFES_H
#define LIFES_H

#include "bitmap.h"
#define dead 200

class LIFE:public BITMAP{
protected:
  bool status;
public:
  LIFE();
  ~LIFE();
};

#endif // LIFES_H
