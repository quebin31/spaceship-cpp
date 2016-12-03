#include "lifes.h"

<<<<<<< HEAD
LIFE::LIFE(): BITMAP("lifes.png"), status(false) {}
=======
using namespace std;
>>>>>>> 4c5ac0340952ef0053aef19789a101c5e53360c4

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
