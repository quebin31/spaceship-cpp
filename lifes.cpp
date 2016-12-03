#include "lifes.h"

using namespace std;

LIFE::LIFE(): BITMAP("lifes.png"){
  this->status=false;
}

void LIFE::draw_life() {
  check_life();
  al_draw_bitmap_region(bitmap, sourceX, sourceY, 30, 30, posX, posY, 0);
}

void LIFE::change_state(bool stat){
  this->status=stat;
}

void LIFE::check_life(){
  if (this->status==true){
    sourceX=30;
  }
}
