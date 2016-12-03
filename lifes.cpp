#include "lifes.h"

LIFE::LIFE(): BITMAP("lifes.png"), status(false) {}

void LIFE::draw_life() {
  al_draw_bitmap_region(bitmap, sourceX, sourceY, 30, 30, posX, posY, 0);
}


