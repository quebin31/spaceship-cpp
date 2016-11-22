#ifndef NAVE_H
#define NAVE_H

#include "game.h"
#include "bitmap.h"

#define NAVE_UP    0
#define NAVE_RIGHT 32
#define NAVE_LEFT  64

class NAVE: public BITMAP {
public:
  NAVE(const char* file);

  void draw_nave(const int _nave_no);
};

#endif // NAVE_H
