#include "nave.h"


using namespace std;

NAVE::NAVE(): BITMAP("nave1.png"){
  cout << "NAVE: Instanciando el objeto nave" << endl;
  width   = 32;
  height  = 32;
  cout << "NAVE: Dimensiones del objeto nave " << width << "x" << height << endl;
  posX    = 0;
  posY    = 0;
  sourceX = 0;
  sourceY = 0;
  cout << "GUN: Instanciando el objeto nave_gun" << endl;
  nave_gun.get_info();
  cout << "NAVE: All done." << endl;
}

void NAVE::select_nave(const int direction) {
  sourceX = direction;
}

void NAVE::shoot() {
  nave_gun.shoot_gun(posX, posY, middle_nave_x, -middle_nave_y);
}

void NAVE::admi_gun(){
  nave_gun.manage_gun();
}

void NAVE::draw_nave(){
  al_draw_bitmap_region(bitmap, sourceX, sourceY, 32, 32, posX, posY, 0);
}

void NAVE::draw_nave(const int _nave_no){
  al_draw_bitmap_region(bitmap, _nave_no, sourceY, 32, 32, posX, posY, 0);
}

void NAVE::get_ammo_info() {
  nave_gun.get_info();
}

