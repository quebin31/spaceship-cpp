#ifndef NAVE_H
#define NAVE_H

#include "game.h"
#include "bitmap.h"

class NAVE: public BITMAP {
public:
  NAVE(const char* file);
  ALLEGRO_BITMAP* get_bitmap(void);
  void draw_nave(const int _number);
  void select(const int _election);

};

#endif // NAVE_H
