#ifndef BULLET_H
#define BULLET_H

#include "bitmap.h"

class BULLET: public BITMAP{
public:
  bool destroyed;
  bool colision;
  BULLET();
};

#endif // BULLET_H
