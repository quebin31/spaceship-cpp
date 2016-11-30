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
    new_aster->setY(generate_random_coorY());
    row.push_back(new_aster);
  }
  cout << "ROW_OF_ASTEROIDS: Tamaño de la fila " << row.size() << endl;
}

ROW_OF_ASTEROIDS::~ROW_OF_ASTEROIDS()
{
  for (int i = 0; i < row.size(); i++)
    delete row[i];
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
  uniform_int_distribution<> distr(30, 600);
  return distr(eng);
}

coor_t ROW_OF_ASTEROIDS::generate_random_coorY()
{
  random_device randomDevice;
  mt19937 eng(randomDevice());
  uniform_int_distribution<> distr(0, 30);
  return distr(eng);
}

bool ROW_OF_ASTEROIDS::empty_row()
{
  return row.empty();
}

bool ROW_OF_ASTEROIDS::reached_limit()
{
  int count = 0;
  for (unsigned int i = 0; i < row.size(); i++)
  {
    if (row[i]->getY() >= 480) count++;
  }
  return (count == row.size());
}

void ROW_OF_ASTEROIDS::move_asteroids()
{
  for (unsigned int i = 0; i < row.size(); i++)
  {
    row[i]->moveY(1.8);
  }
}

void ROW_OF_ASTEROIDS::check_asteroids(BITMAP* obj)
{
  for (unsigned int i = 0; i < row.size(); i++)
  {
    if (row[i]->getY() == 480)
    {
      delete row[i];
      row.erase(row.begin()+i);
//      cout << "ROA: Deleted an asteroid, alcanzo el limite" << endl;
    }
    else if (!row[i]->destroyed)
    {
      if (obj->check_colision(*row[i]))
      {
        row[i]->destroyed = true;
        obj->destroyed = true;
      }
    }
    else
    {
      delete row[i];
      row.erase(row.begin()+i);
//      cout << "ROA: Deleted an asteroid, colision" << endl;
    }
  }
}

void ROW_OF_ASTEROIDS::draw_asteroids()
{
  for (unsigned int i = 0; i < row.size(); i++)
  {
    row[i]->draw_asteroid();
  }
}

void ROW_OF_ASTEROIDS::manage_asteroids(BITMAP* obj)
{
  check_asteroids(obj);
  move_asteroids();
  draw_asteroids();
}


ASTEROIDS_ENG::ASTEROIDS_ENG()
{
  generate_row();
  fps_to_gen = generate_random_fps();
}

ASTEROIDS_ENG::~ASTEROIDS_ENG()
{
  for (int i = 0; i < rows_of_asters.size(); i++)
  {
    delete_row(rows_of_asters[i]);
  }
  cout << "ASTEROIDS_ENG: Deleted all rows" << endl;
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

int ASTEROIDS_ENG::generate_random_fps()
{
  random_device randomDevice;
  mt19937 eng(randomDevice());
  uniform_int_distribution<> distr(100, 120);
  return distr(eng);
}

void ASTEROIDS_ENG::check_asteroids(BITMAP* obj)const
{
  for (unsigned int i = 0; i < rows_of_asters.size(); i++)
  {
    rows_of_asters[i]->check_asteroids(obj);
  }
}

void ASTEROIDS_ENG::manage_asteroids(BITMAP *obj, const GAME* game) {
  int64_t frames = game->get_timer_count();
  if (frames % fps_to_gen == 0)
  {
//    cout << "ASTEROIDS_ENG: frames = " << frames << endl;
    generate_row();
    fps_to_gen = generate_random_fps();
  }
  for (unsigned int i = 0; i < rows_of_asters.size(); i++)
  {
    if (rows_of_asters[i]->empty_row())
    {
      delete_row(rows_of_asters[i]);
      rows_of_asters.erase(rows_of_asters.begin()+i);
//      cout << "ASTEROIDS_ENG: Deleted a row, empty" << endl;
    }
    else if (rows_of_asters[i]->reached_limit())
    {
      delete_row(rows_of_asters[i]);
      rows_of_asters.erase(rows_of_asters.begin()+i);
//      cout << "ASTEROIDS_ENG: Deleted a row, alcanzo el limite" << endl;
    }
    else
      rows_of_asters[i]->manage_asteroids(obj);
  }
}
