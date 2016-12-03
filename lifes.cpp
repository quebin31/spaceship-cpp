#include "lifes.h"

using namespace std;

LIFE::LIFE(): BITMAP("lifes.png"){
  this->status=false;
}

void LIFE::draw_life() {
  al_draw_bitmap_region(bitmap, sourceX, sourceY, 30, 30, posX, posY, 0);
}
