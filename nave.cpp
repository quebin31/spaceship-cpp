#include "nave.h"

NAVE::NAVE(const char *file): BITMAP(file){
  width   = 32;
  height  = 32;
  posX    = 0;
  posY    = 0;
  sourceX = 0;
  sourceY = 0;
}

void NAVE::select(int _election) {
  sourceX = _election;
}

void NAVE::draw_nave(const int _number){
  al_draw_bitmap_region(bitmap, _number, sourceY, 32, 32, posX, posY, 0);
}

ALLEGRO_BITMAP* NAVE::get_bitmap(void){ return bitmap; }

