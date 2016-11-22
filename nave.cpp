#include "nave.h"


using namespace std;

NAVE::NAVE(const char *file): BITMAP(file){
  cout << "NAVE: Instanciando el objeto nave" << endl;
  width   = 32;
  height  = 32;
  posX    = 0;
  posY    = 0;
  sourceX = 0;
  sourceY = 0;
  cout << "NAVE: All done." << endl;
}

void NAVE::draw_nave(const int _nave_no){
  al_draw_bitmap_region(bitmap, _nave_no, sourceY, 32, 32, posX, posY, 0);
}

