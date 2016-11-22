#include "nave.h"

NAVE::NAVE(const char *file): BITMAP(file){
  posX = 0;
  posY = 0;
  sourceX=0;
  sourceY=0;
}

void NAVE::change_sourceX(int _sourceX){
  sourceX=_sourceX;
}

void NAVE::change_sourceY(int _sourceY){
  sourceY=_sourceY;
}

void NAVE::draw_nave(void){
  al_draw_bitmap_region(bitmap,sourceX, sourceY * al_get_bitmap_height(bitmap)/4, 96, 96, posX, posY, 0);
}

void NAVE::refresh_sourceX(void){
  sourceX += al_get_bitmap_width(bitmap)/3;
}

int NAVE::get_sourceX(void){ return sourceX; }
int NAVE::get_sourceY(void){ return sourceY; }
ALLEGRO_BITMAP* NAVE::get_bitmap(void){ return bitmap; }
