#include "set_of_hearts.h"

SET_OF_HEARTS::SET_OF_HEARTS() {}

void SET_OF_HEARTS::init_hearts(){
  int add = 40;
  for (int i=0;i < times; i++){
    LIFE* life = new LIFE;
    hearts.push_back(life);
    life->setY(40);
    life->setX(add+=30);
  }
}

SET_OF_HEARTS::~SET_OF_HEARTS(){
  for (int i=0;i < times; i++){
    delete this->hearts[i];
    cout << "Delete hearts" << endl;
  }
}

void SET_OF_HEARTS::draw_hearts(){
  for (unsigned int i=0; i < this->hearts.size(); i++){
    this->hearts[i]->draw_life();
  }
}
