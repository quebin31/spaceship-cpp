//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_ASTEROIDS_INTERFACE_H
#define SPACESHIP2_ASTEROIDS_INTERFACE_H

#include "../bitmap_objects/asteroid.h"

class AsteroidFactory;
class AsteroidObjPool;
class AsteroidInterface;

class AsteroidFactory
{
  private:
    static int fps_to_gen;

  private:
    static int generate_random_num_of_asters();
    static int generate_random_fps_count();
    static Asteroid* check_store(AsteroidObjPool* setofasters);

  public:
    static int  getFpsToGen();
    static void generateRowFor(AsteroidObjPool *setofasters);
};

class AsteroidObjPool
{
  private:
    std::vector<Asteroid*> asters_on_use;
    std::vector<Asteroid*> store;

  private:
    friend class AsteroidFactory;
    friend class AsteroidInterface;

  public:
    class Iterator
    {
      private:
        AsteroidObjPool* ap;
        int index;

      private:
        friend class AsteroidObjPool;

      public:
        Iterator(AsteroidObjPool& _ap);
        Iterator(AsteroidObjPool* _ap);
        Iterator(const Iterator& itr);

        Iterator&  operator++();
        Iterator   operator++(int);
        Iterator   operator+(const int sum);
        bool       operator==(const Iterator& itr);
        bool       operator!=(const Iterator& itr);
        Asteroid*  operator*();

        int getIndex();
    };

    AsteroidObjPool();
    ~AsteroidObjPool();

    Asteroid*   at(const int index);
    Asteroid*   operator[](const int index);
    std::size_t size();
    void        erase(Iterator& itr);

    Iterator begin();
    Iterator end();
};

class AsteroidInterface
{
  private:
    static AsteroidObjPool *asteroidOP;

  public:
    static void createAsteroidObjPool();
    static void deleteAsteroidObjPool();

    static void updateAsteroids(int64_t actual_frames_count);
    static void eraseAsteroid(AsteroidObjPool::Iterator &itr);

    static AsteroidObjPool::Iterator getBegin();
    static AsteroidObjPool::Iterator getEnd();
    static AsteroidObjPool*          getAOP();
};


#endif //SPACESHIP2_ASTEROIDS_INTERFACE_H
