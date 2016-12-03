#include "lifes.h"

LIFE::LIFE(): BITMAP("hearts.png"), status(false) {}

void LIFE::draw_life() {
  al_draw_bitmap_region(bitmap, sourceX, sourceY, 32, 32, posX, posY, 0);
}


