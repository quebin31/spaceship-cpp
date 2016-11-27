//
// Created by kevin on 22/11/16.
//

#include "set_of_asteroids.h"
#include "game.h"

using namespace std;

ROW_OF_ASTEROIDS::ROW_OF_ASTEROIDS()
{
  int no_of_asters = generate_random_no_of_asteroids();
  for (int i = 0; i < no_of_asters; i++)
  {
    int type = generate_random_type_of_asteroid();
    ASTEROID* new_aster = new ASTEROID(type_of_asters[type]);
    new_aster->setX(generate_random_coorX());
    new_aster->setY(-48);
    row.push_back(new_aster);
  }
  this->no_of_asters = row.size();
  all_destroyed = false;
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

void ROW_OF_ASTEROIDS::move_asteroids()
{
  if (all_destroyed){
    return;
  }
  for (int i = 0; i < no_of_asters; i++)
  {
    if (!row.at(i)->destroyed)
      row.at(i)->moveY(1.5);
  }
}

void ROW_OF_ASTEROIDS::check_asteroids(const BITMAP &obj)
{
  if (all_destroyed){
    return;
  }
  int no_of_destroyed = 0;
  for (int i = 0; i < no_of_asters; i++)
  {
    if (!row.at(i)->destroyed)
    {
      if (obj.check_colision(*row.at(i)))
        row.at(i)->destroyed = true;
    }
    else
    {
      no_of_destroyed += 1;
    }
  }
  if (no_of_destroyed == no_of_asters)
  {
    all_destroyed = true;
    cout << "ROW_OF_ASTEROID: All destroyed = true" << endl;
  }
}

void ROW_OF_ASTEROIDS::draw_asteroids()
{
  if (all_destroyed){
    return;
  }
  for (int i = 0; i < no_of_asters; i++)
  {
    if (!row.at(i)->destroyed)
      row.at(i)->draw_asteroid();
  }
}

void ROW_OF_ASTEROIDS::manage_asteroids(const BITMAP& obj)
{
  check_asteroids(obj);
  move_asteroids();
  draw_asteroids();
}


ASTEROIDS_ENG::ASTEROIDS_ENG()
{
  generate_row();
}

ASTEROIDS_ENG::~ASTEROIDS_ENG() {

}

void ASTEROIDS_ENG::generate_row()
{
  cout << "ASTEROID_ENG: New row" << endl;
  ROW_OF_ASTEROIDS* new_row = new ROW_OF_ASTEROIDS;
  rows_of_asters.push_back(new_row);
  no_of_rows = rows_of_asters.size();
  cout << "ASTEROID_ENG: Tamaño del vector " << no_of_rows << endl;
}

void ASTEROIDS_ENG::delete_row(ROW_OF_ASTEROIDS* obj)
{
  delete obj;
}

void ASTEROIDS_ENG::move_asteroids() {
  for (int i = 0; i < no_of_rows; i++)
  {
    rows_of_asters.at(i)->move_asteroids();
  }
}

void ASTEROIDS_ENG::check_asteroids(const BITMAP& obj)
{
  ROW_OF_ASTEROIDS** row = rows_of_asters.data();
  for (int i = 0; i < no_of_rows; i++)
  {
    rows_of_asters.at(i)->move_asteroids();
  }
}

void ASTEROIDS_ENG::draw_asteroids()
{
  ROW_OF_ASTEROIDS** row = rows_of_asters.data();
  for (int i = 0; i < no_of_rows; i++)
  {
    rows_of_asters.at(i)->draw_asteroids();
  }
}

void ASTEROIDS_ENG::manage_asteroids(const BITMAP &obj, const GAME* game) {
  int64_t frames = game->get_timer_count();
  if (frames % 120 == 0)
  {
    cout << "ASTEROIDS_ENG: frames = " << frames << endl;
    generate_row();
  }
  for (int i = 0; i < no_of_rows; i++)
  {
    rows_of_asters.at(i)->manage_asteroids(obj);
  }
}
