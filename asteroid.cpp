//
// Created by kevin on 21/11/16.
//

#include "asteroid.h"

ASTEROID::ASTEROID(const char *file) : BITMAP(file) {
  width = 45;
  height = 45;
  posX = 0;
  posY = 0;
  sourceX = 0;
  sourceY = 0;
}

void ASTEROID::draw_asteoid(const int _asteroid_no) {
  al_draw_bitmap_region(bitmap, _asteroid_no, sourceY, 45, 45, posX, posY, 0);
}



