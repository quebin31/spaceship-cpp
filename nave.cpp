#include "nave.h"


using namespace std;

NAVE::NAVE(): BITMAP("nave1.png"){
  cout << "NAVE: Instanciando el objeto nave" << endl;
  width   = 32;
  height  = 32;
  posX    = 0;
  posY    = 0;
  sourceX = 0;
  sourceY = 0;
  cout << "GUN: Instanciando el objeto nave_gun" << endl;
  nave_gun.get_info();
  cout << "NAVE: All done." << endl;
}

void NAVE::shoot() {
  nave_gun.wasted_bullet();
}

void NAVE::draw_nave(const int _nave_no){
  al_draw_bitmap_region(bitmap, _nave_no, sourceY, 32, 32, posX, posY, 0);
}

void NAVE::get_ammo_info() {
  nave_gun.get_info();
}

