//
// Created by kevin on 7/12/16.
//

#include "asteroids_interface.h"

ASTEROID *ASTEROIDS::check_for_store()
{
  if (!store.empty())
  {
    ASTEROID* aster = store.back();
    store.pop_back();
    aster->reset_bitmap();
    return aster;
  }
  return new ASTEROID;
}

int ASTEROIDS::generate_random_num_of_asters()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(3, 7);
  return distr(eng);
}

int ASTEROIDS::generate_random_fps_count()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(90, 110);
  return distr(eng);
}

void ASTEROIDS::create_new_row()
{
  int num_of_asters = generate_random_num_of_asters();
  for (int i = 0; i < num_of_asters; i++)
  {
    ASTEROID *new_aster = check_for_store();
    aster.push_back(new_aster);
  }
}

ASTEROIDS::ASTEROIDS()
{
  create_new_row();
  fps_to_gen = generate_random_fps_count();
}

ASTEROIDS::~ASTEROIDS()
{
  for (int i = 0; i < aster.size(); i++)
    delete aster[i];
  std::cout << "Asteroides eliminados \n";
  for (int i = 0; i < store.size(); i++)
    delete store[i];
  std::cout << "Almacen limpio\n";
}


void ASTEROIDS::update_asteroids(int64_t frame_count)
{
  if (frame_count%fps_to_gen == 0)
  {
    create_new_row();
    fps_to_gen = generate_random_fps_count();
  }

  for (int i = 0; i < aster.size(); i++)
  {
    if (!aster[i]->getDestroyed())
    {
      aster[i]->moveY(2.0);
      aster[i]->draw_bitmap(0);
    }
  }
}

ASTEROID *ASTEROIDS::operator[](std::size_t index) { return aster[index]; }
bool ASTEROIDS::empty() { return aster.empty(); }

std::size_t ASTEROIDS::size() { return aster.size(); }

ASTEROID *ASTEROIDS::at(std::size_t index) { return aster[index]; }

void ASTEROIDS::put_on_store(std::size_t index)
{
  store.push_back(aster[index]);
  aster.erase(aster.begin()+index);
}
