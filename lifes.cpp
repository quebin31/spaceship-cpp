#include "lifes.h"

LIFE::LIFE(): BITMAP("hearts.png"), status(false) {}

SET_OF_HEARTS::SET_OF_HEARTS() {
  for (unsigned int i=0;i<this->HEARTS.size();i++){
    LIFE* life = new LIFE;
    life->setH(450);
    life->setW(600+movex);
    this->HEARTS.push_back(life);
  }
}

SET_OF_HEARTS::~SET_OF_HEARTS(){
  for (unsigned int i=0;i<this->HEARTS.size();i++){
    delete this->HEARTS[i];
    cout << "Heart deleted" << endl;
  }
}