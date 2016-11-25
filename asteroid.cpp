//
// Created by kevin on 21/11/16.
//

#include "asteroid.h"

int myAster[] = {NO_1, NO_2, NO_3, NO_4, NO_5};
vector<int> type_of_asters(myAster, myAster+5);

ASTEROID::ASTEROID(const int _no_asteroid): BITMAP("asteroides.png") {
  width = 45;
  height = 45;
  posX = 0;
  posY = 0;
  sourceX = _no_asteroid;
  sourceY = 0;
}

void ASTEROID::draw_asteroid(const int _asteroid_no) const {
  al_draw_bitmap_region(bitmap, _asteroid_no, sourceY, 45, 45, posX, posY, 0);
}

void ASTEROID::draw_asteroid() const {
  al_draw_bitmap_region(bitmap, sourceX, sourceY, 45, 45, posX, posY, 0);
}





