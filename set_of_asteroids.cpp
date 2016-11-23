//
// Created by kevin on 22/11/16.
//

#include "game.h"
#include "set_of_asteroids.h"

using namespace std;

SetOfAsteroids::SetOfAsteroids() {
  no_asteroids = 0;
}

SetOfAsteroids::SetOfAsteroids(const char *file) {
  no_asteroids = 0;
  coor_t coorX = 10;
  for (int i = 0; i < 5; i++){
    ASTEROID* new_aster = new ASTEROID(file,type_of_asters[i]);
    new_aster->setX(coorX);
    new_aster->setY(10);
    Asters.push_back(new_aster);
    no_asteroids += 1;
    coorX += 45*2;
  }
}

void SetOfAsteroids::move_asteroids() {
  for (int i = 0; i != no_asteroids; i++){
    Asters.at(i)->moveY(1.0);
  }
}

void SetOfAsteroids::draw_asteroids() {
  for (int i = 0; i < 5; i++){
    Asters.at(i)->draw_asteroid();
  }
}
