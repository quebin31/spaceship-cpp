//
// Created by kevin on 22/11/16.
//

#ifndef SPACESHIP_SET_OF_ASTEROIDS_H
#define SPACESHIP_SET_OF_ASTEROIDS_H

#include <vector>
#include <random>
#include "game.h"
#include "asteroid.h"

class SetOfAsteroids {
private:
  vector<ASTEROID*> Asters;
  int no_asteroids;
public:
  SetOfAsteroids();
  SetOfAsteroids(const char* file);

  void move_asteroids();
  void draw_asteroids();
};


#endif //SPACESHIP_SET_OF_ASTEROIDS_H
