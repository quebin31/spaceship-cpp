//
// Created by kevin on 22/11/16.
//

#include "set_of_asteroids.h"

using namespace std;

ASTEROIDS::ASTEROIDS() {
  no_asteroids = 0;
  coor_t coorX = 10;
  for (int i = 0; i < 5; i++){
    ASTEROID* new_aster = new ASTEROID(type_of_asters[i]);
    new_aster->setX(coorX);
    new_aster->setY(10);
    Asters.push_back(new_aster);
    no_asteroids += 1;
    coorX += 45*2;
  }
}

void ASTEROIDS::move_asteroids() {
  for (int i = 0; i != no_asteroids; i++){
    Asters.at(i)->moveY(1.0);
  }
}

void ASTEROIDS::draw_asteroids() {
  for (int i = 0; i < 5; i++){
    Asters.at(i)->draw_asteroid();
  }
}

