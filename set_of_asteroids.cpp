//
// Created by kevin on 22/11/16.
//

#include "set_of_asteroids.h"

using namespace std;



int ROW_OF_ASTEROIDS::generate_random_no_of_asteroids()
{
  random_device randomDevice;
  mt19937 eng(randomDevice());
  uniform_int_distribution<> distr(3, 7);
  return distr(eng);
}

int ROW_OF_ASTEROIDS::generate_random_type_of_asteroid()
{
  random_device randomDevice;
  mt19937 eng(randomDevice());
  uniform_int_distribution<> distr(0, 5);
  return distr(eng);
}

coor_t ROW_OF_ASTEROIDS::generate_random_coorX()
{
  random_device randomDevice;
  mt19937 eng(randomDevice());
  uniform_int_distribution<> distr(10, 625);
  return distr(eng);
}

void ASTEROIDS::generate_asteroids()
{

}

void ASTEROIDS::move_asteroids() {

}

void ASTEROIDS::delete_asteroids() {

}

void ASTEROIDS::draw_asteroids() {

}



