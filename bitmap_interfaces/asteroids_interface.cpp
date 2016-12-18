//
// Created by kevin on 7/12/16.
//

#include "asteroids_interface.h"

/* =======================================================================================================================================================================*/

int AsteroidFactory::fps_to_gen = AsteroidFactory::generate_random_fps_count();

int AsteroidFactory::generate_random_num_of_asters()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(3, 7);
  return distr(eng);
}

int AsteroidFactory::generate_random_fps_count()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(90, 110);
  return distr(eng);
}

Asteroid *AsteroidFactory::check_store(AsteroidObjPool *setofasters)
{
  if (!setofasters->store.empty())
  {
    Asteroid* pAsteroid = setofasters->store.back();
    setofasters->store.pop_back();
    return pAsteroid;
  }
  return new Asteroid;
}

int AsteroidFactory::getFpsToGen()
{ return fps_to_gen; }

void AsteroidFactory::generateRowFor(AsteroidObjPool *setofasters)
{
  int number_of_asteroids = generate_random_num_of_asters();
  for (int i = 0; i < number_of_asteroids; i++)
  {
    Asteroid* asteroid = check_store(setofasters);
    setofasters->asters_on_use.push_back(asteroid);
  }
  fps_to_gen = generate_random_fps_count();
}

/* =======================================================================================================================================================================*/

AsteroidObjPool::Iterator::Iterator(AsteroidObjPool &_ap): ap(&_ap), index(0) {}
AsteroidObjPool::Iterator::Iterator(AsteroidObjPool *_ap): ap(_ap), index(0) {}
AsteroidObjPool::Iterator::Iterator(const AsteroidObjPool::Iterator &itr): ap(itr.ap), index(itr.index) {}

AsteroidObjPool::Iterator &AsteroidObjPool::Iterator::operator++()
{
  index++;
  return (*this);
}

AsteroidObjPool::Iterator AsteroidObjPool::Iterator::operator++(int)
{
  Iterator temp_itr = *this;
  ++(*this);
  return temp_itr;
}

AsteroidObjPool::Iterator AsteroidObjPool::Iterator::operator+(const int sum)
{
  Iterator temp_itr = *this;
  temp_itr.index += sum;
  return temp_itr;
}

bool AsteroidObjPool::Iterator::operator==(const AsteroidObjPool::Iterator &itr)
{ return (this->index == itr.index); }

bool AsteroidObjPool::Iterator::operator!=(const AsteroidObjPool::Iterator &itr)
{ return (this->index != itr.index); }

Asteroid *AsteroidObjPool::Iterator::operator*()
{ return ap->asters_on_use[index]; }

int AsteroidObjPool::Iterator::getIndex()
{ return index; }

/* =======================================================================================================================================================================*/

AsteroidObjPool::AsteroidObjPool()
{ AsteroidFactory::generateRowFor(this); }

AsteroidObjPool::~AsteroidObjPool()
{
  for (unsigned i = 0; i < asters_on_use.size(); i++)
    delete asters_on_use[i];
  for (unsigned i = 0; i < store.size(); i++)
    delete store[i];
}

Asteroid *AsteroidObjPool::at(const int index)
{ return asters_on_use.at((unsigned long) index); }

Asteroid *AsteroidObjPool::operator[](const int index)
{ return asters_on_use[index]; }

std::size_t AsteroidObjPool::size()
{ return asters_on_use.size(); }

void AsteroidObjPool::erase(AsteroidObjPool::Iterator &itr)
{
  Asteroid* asteroid = (*itr);
  asteroid->reset_bitmap();
  store.push_back(asteroid);
  asters_on_use.erase(asters_on_use.begin() + itr.index);
  itr.index -= 1;
}

AsteroidObjPool::Iterator AsteroidObjPool::begin()
{
  Iterator temp(this);
  temp.index = 0;
  return temp;
}

AsteroidObjPool::Iterator AsteroidObjPool::end()
{
  Iterator temp(this);
  temp.index = (int) (asters_on_use.size() - 1);
  return temp;
}

/* =======================================================================================================================================================================*/

AsteroidObjPool* AsteroidInterface::asteroidOP = 0;

void AsteroidInterface::createAsteroidObjPool()
{ if (!asteroidOP) asteroidOP = new AsteroidObjPool; }

void AsteroidInterface::deleteAsteroidObjPool()
{ delete asteroidOP; }

void AsteroidInterface::updateAsteroids(int64_t actual_frames_count)
{
  if (actual_frames_count % AsteroidFactory::getFpsToGen() == 0)
    AsteroidFactory::generateRowFor(asteroidOP);

  for (AsteroidObjPool::Iterator itr = asteroidOP->begin(); itr != asteroidOP->end() + 1; itr++)
    if (!(*itr)->getDestroyed())
    {
      (*itr)->moveY(2.5);
      (*itr)->draw_bitmap(0);
    }
}

void AsteroidInterface::eraseAsteroid(AsteroidObjPool::Iterator &itr)
{ asteroidOP->erase(itr); }

AsteroidObjPool::Iterator AsteroidInterface::getBegin()
{ return asteroidOP->begin(); }

AsteroidObjPool::Iterator AsteroidInterface::getEnd()
{ return asteroidOP->end(); }

AsteroidObjPool *AsteroidInterface::getAOP()
{ return asteroidOP; }

/* =======================================================================================================================================================================*/
