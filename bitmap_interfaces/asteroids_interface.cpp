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

Asteroid *AsteroidFactory::check_store(AsteroidObjectPool *setofasters)
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

void AsteroidFactory::createRow(AsteroidObjectPool *setofasters)
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
AsteroidObjectPool::Iterator::Iterator(AsteroidObjectPool &_ap): ap(&_ap), index(0) {}
AsteroidObjectPool::Iterator::Iterator(AsteroidObjectPool *_ap): ap(_ap), index(0) {}
AsteroidObjectPool::Iterator::Iterator(const AsteroidObjectPool::Iterator &itr): ap(itr.ap), index(itr.index) {}

AsteroidObjectPool::Iterator &AsteroidObjectPool::Iterator::operator++()
{
  index++;
  return (*this);
}

AsteroidObjectPool::Iterator AsteroidObjectPool::Iterator::operator++(int)
{
  Iterator temp_itr = *this;
  ++(*this);
  return temp_itr;
}

AsteroidObjectPool::Iterator AsteroidObjectPool::Iterator::operator+(const int sum)
{
  Iterator temp_itr = *this;
  temp_itr.index += sum;
  return temp_itr;
}

bool AsteroidObjectPool::Iterator::operator==(const AsteroidObjectPool::Iterator &itr)
{ return (this->index == itr.index); }

bool AsteroidObjectPool::Iterator::operator!=(const AsteroidObjectPool::Iterator &itr)
{ return (this->index != itr.index); }

Asteroid *AsteroidObjectPool::Iterator::operator*()
{ return ap->asters_on_use[index]; }

/* =======================================================================================================================================================================*/

AsteroidObjectPool::AsteroidObjectPool()
{ AsteroidFactory::createRow(this); }

AsteroidObjectPool::~AsteroidObjectPool()
{
  for (unsigned i = 0; i < asters_on_use.size(); i++)
    delete asters_on_use[i];
  for (unsigned i = 0; i < store.size(); i++)
    delete store[i];
}

Asteroid *AsteroidObjectPool::at(int index)
{ return asters_on_use.at(index); }

Asteroid *AsteroidObjectPool::operator[](int index)
{ return asters_on_use[index]; }

std::size_t AsteroidObjectPool::size()
{ return asters_on_use.size(); }

void AsteroidObjectPool::erase(AsteroidObjectPool::Iterator &itr)
{
  Asteroid* asteroid = (*itr);
  asteroid->reset_bitmap();
  store.push_back(asteroid);
  asters_on_use.erase(asters_on_use.begin() + itr.index);
  itr.index -= 1;
}

AsteroidObjectPool::Iterator AsteroidObjectPool::begin()
{
  Iterator temp(this);
  temp.index = 0;
  return temp;
}

AsteroidObjectPool::Iterator AsteroidObjectPool::end()
{
  Iterator temp(this);
  temp.index = asters_on_use.size() - 1;
  return temp;
}

/* =======================================================================================================================================================================*/

AsteroidObjectPool* AsteroidInterface::asteroidOP = 0;

void AsteroidInterface::createAsteroidObjectPool()
{ if (!asteroidOP) asteroidOP = new AsteroidObjectPool; }

void AsteroidInterface::deleteAsteroidObjectPool()
{ delete asteroidOP; }

void AsteroidInterface::updateAsteroids(int64_t actual_frames_count)
{
  if (actual_frames_count % AsteroidFactory::getFpsToGen() == 0)
    AsteroidFactory::createRow(asteroidOP);

  for (AsteroidObjectPool::Iterator itr = asteroidOP->begin(); itr != asteroidOP->end() + 1; itr++)
    if (!(*itr)->getDestroyed())
    {
      (*itr)->moveY(2.5);
      (*itr)->draw_bitmap(0);
    }
}

void AsteroidInterface::eraseAsteroid(AsteroidObjectPool::Iterator &itr)
{ asteroidOP->erase(itr); }

AsteroidObjectPool::Iterator AsteroidInterface::getBegin()
{ return asteroidOP->begin(); }

AsteroidObjectPool::Iterator AsteroidInterface::getEnd()
{ return asteroidOP->end(); }

AsteroidObjectPool *AsteroidInterface::getAOP()
{ return asteroidOP; }

/* =======================================================================================================================================================================*/
