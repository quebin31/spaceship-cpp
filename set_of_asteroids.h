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
public:
  bool reached_limit;
  bool all_destroyed;
  ROW_OF_ASTEROIDS();
  ~ROW_OF_ASTEROIDS();
  int generate_random_no_of_asteroids();
  int generate_random_type_of_asteroid();
  coor_t generate_random_coorX();

  void move_asteroids();
  void check_asteroids(const BITMAP &obj);
  void draw_asteroids();
  void manage_asteroids(const BITMAP& obj);
};


class ASTEROIDS_ENG
{
private:
  vector<ROW_OF_ASTEROIDS*> rows_of_asters;
  unsigned long no_of_rows;
public:
  ASTEROIDS_ENG();
  ~ASTEROIDS_ENG();

  void generate_row();
  void delete_row(ROW_OF_ASTEROIDS* obj);
  void move_asteroids();
  void check_asteroids(const BITMAP& obj);
  void draw_asteroids();
  void manage_asteroids(const BITMAP& obj, const GAME* game);

};


#endif //SPACESHIP_SET_OF_ASTEROIDS_H
