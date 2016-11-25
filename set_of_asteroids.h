//
// Created by kevin on 22/11/16.
//

#ifndef SPACESHIP_SET_OF_ASTEROIDS_H
#define SPACESHIP_SET_OF_ASTEROIDS_H

#include "asteroid.h"

class ASTEROIDS {
private:
  vector<ASTEROID*> Asters;
  int no_asteroids;
public:
  ASTEROIDS();

  void move_asteroids();
  void draw_asteroids();
};


#endif //SPACESHIP_SET_OF_ASTEROIDS_H
