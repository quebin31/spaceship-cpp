//
// Created by kevin on 22/11/16.
//

#ifndef SPACESHIP_SET_OF_ASTEROIDS_H
#define SPACESHIP_SET_OF_ASTEROIDS_H

#include "asteroid.h"

class ROW_OF_ASTEROIDS
{
private:
  vector<ASTEROID*> row;
public:
  ROW_OF_ASTEROIDS();
  int generate_random_no_of_asteroids();
  int generate_random_type_of_asteroid();
  coor_t generate_random_coorX();
};

class ASTEROIDS
{
private:
  vector<ROW_OF_ASTEROIDS*> rows_of_asters;
public:
  ASTEROIDS();

  void generate_asteroids();
  void move_asteroids();
  void delete_asteroids();
  void draw_asteroids();

};


#endif //SPACESHIP_SET_OF_ASTEROIDS_H
