//
// Created by kevin on 22/11/16.
//

#include "set_of_asteroids.h"

using namespace std;

ROW_OF_ASTEROIDS::ROW_OF_ASTEROIDS()
{
  int no_of_asters = generate_random_no_of_asteroids();
  for (int i = 0; i < no_of_asters; i++)
  {
    int type = generate_random_type_of_asteroid();
    ASTEROID* new_aster = new ASTEROID(type_of_asters[type]);
    new_aster->setX(generate_random_coorX());
    new_aster->setY(10);
    row.push_back(new_aster);
  }
  this->no_of_asters = row.size();
}

ROW_OF_ASTEROIDS::~ROW_OF_ASTEROIDS()
{
  for (int i = 0; i < no_of_asters; i++)
  {
    if (row.at(i) != nullptr)
      delete row.at(i);
  }
}

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
  uniform_int_distribution<> distr(10, 600);
  return distr(eng);
}

unsigned long ROW_OF_ASTEROIDS::get_no_of_asters() { return this->no_of_asters; }

void ROW_OF_ASTEROIDS::move_asteroids()
{
  for (int i = 0; i < no_of_asters; i++)
  {
    if (row.at(i) != nullptr || row.at(i)->was_destroyed())
    {
      row.at(i)->moveY(1.8);
    }
  }
}

void ROW_OF_ASTEROIDS::draw_asteroids()
{
  for (int i = 0; i < no_of_asters; i++)
  {
    if (row.at(i) != nullptr || row.at(i)->was_destroyed())
    {
      row.at(i)->draw_asteroid();
    }
  }
}

void ASTEROIDS_ENG::generate_asteroids()
{

}

void ASTEROIDS_ENG::move_asteroids() {

}

void ASTEROIDS_ENG::delete_asteroids() {

}

void ASTEROIDS_ENG::draw_asteroids() {

}



