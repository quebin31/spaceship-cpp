#include "lifes.h"

LIFE::LIFE(): BITMAP("lifes.png"), status(false) {}

void LIFE::draw_life() {
  al_draw_bitmap_region(bitmap, sourceX, sourceY, 30, 30, posX, posY, 0);
}

SET_OF_HEARTS::SET_OF_HEARTS(){
  int add=10;
  for (int i=0; i < 3; i++){
    LIFE* life = new LIFE;
    life->setX(add+=30);
    life->setY(40);
    this->hearts.push_back(life);
  }
}

SET_OF_HEARTS::~SET_OF_HEARTS(){
  for (int i=0; i<3; i++){
    delete this->hearts[i];
    cout << "Delete heart" << endl;
  }
}

void SET_OF_HEARTS::draw_hearts(){
  for (int i=0; i<3; i++){
    this->hearts[i]->draw_life();
  }
}
