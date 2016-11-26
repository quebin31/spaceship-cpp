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
  unsigned long no_of_asters;
  bool reached_limit;
public:
  ROW_OF_ASTEROIDS();
  ~ROW_OF_ASTEROIDS();
  int generate_random_no_of_asteroids();
  int generate_random_type_of_asteroid();
  coor_t generate_random_coorX();
  unsigned long get_no_of_asters();
  void move_asteroids();
  void check_asteroids(const BITMAP &obj);
  void draw_asteroids();
  void manage_asteroids(const BITMAP& obj);
};


class ASTEROIDS_ENG
{
private:
  vector<ROW_OF_ASTEROIDS*> rows_of_asters;
public:
  ASTEROIDS_ENG();

  void generate_asteroids();
  void move_asteroids();
  void delete_asteroids(const BITMAP& obj);
  void draw_asteroids();

};


#endif //SPACESHIP_SET_OF_ASTEROIDS_H
