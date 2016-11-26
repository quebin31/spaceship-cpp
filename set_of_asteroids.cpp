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
  reached_limit = false;
  cout << "ROW_OF_ASTEROIDS: Tamaño de la fila " << this->no_of_asters << endl;
}

ROW_OF_ASTEROIDS::~ROW_OF_ASTEROIDS()
{
  for (int i = 0; i < no_of_asters; i++)
    delete row.at(i);
  cout << "ROW_OF_ASTEROIDS: All deleted." << endl;
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
  ASTEROID** aster = row.data();
  for (int i = 0; i < no_of_asters; i++)
  {
    if (!(*aster)->destroyed)
      (*aster)->moveY(1.8);
    *aster++;
  }
}

void ROW_OF_ASTEROIDS::check_asteroids(const BITMAP &obj)
{
  ASTEROID** aster = row.data();
  for (int i = 0; i < no_of_asters; i++)
  {
    if (!(*aster)->destroyed)
      if (obj.check_colision(**aster))
        (*aster)->destroyed = true;
    *aster++;
  }
}

void ROW_OF_ASTEROIDS::draw_asteroids()
{
  ASTEROID** aster = row.data();
  for (int i = 0; i < no_of_asters; i++)
  {
    if (!(*aster)->destroyed)
      (*aster)->draw_asteroid();
    *aster++;
  }
}

void ASTEROIDS_ENG::generate_asteroids()
{

}

void ASTEROIDS_ENG::move_asteroids() {

}

void ASTEROIDS_ENG::delete_asteroids(const BITMAP& obj) {

}

void ASTEROIDS_ENG::draw_asteroids() {

}



