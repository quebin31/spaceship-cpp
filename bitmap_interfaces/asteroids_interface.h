//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_ASTEROIDS_INTERFACE_H
#define SPACESHIP2_ASTEROIDS_INTERFACE_H

#include "../bitmap_objects/asteroid.h"

class AsteroidFactory;
class AsteroidObjectPool;
class AsteroidInterface;

class AsteroidFactory
{
  private:
    static int fps_to_gen;

  private:
    static int generate_random_num_of_asters();
    static int generate_random_fps_count();
    static Asteroid* check_store(AsteroidObjectPool* setofasters);

  public:
    static int  getFpsToGen();
    static void createRow(AsteroidObjectPool* setofasters);
};

class AsteroidObjectPool
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
        AsteroidObjectPool* ap;
        int index;

      private:
        friend class AsteroidObjectPool;

      public:
        Iterator(AsteroidObjectPool& _ap);
        Iterator(AsteroidObjectPool* _ap);
        Iterator(const Iterator& itr);

        Iterator&  operator++();
        Iterator   operator++(int);
        Iterator   operator+(const int sum);
        bool       operator==(const Iterator& itr);
        bool       operator!=(const Iterator& itr);
        Asteroid*  operator*();


    };

    AsteroidObjectPool();
    ~AsteroidObjectPool();

    Asteroid*   at(int index);
    Asteroid*   operator[](int index);
    std::size_t size();
    void        erase(Iterator& itr);

    Iterator begin();
    Iterator end();
};

class AsteroidInterface
{
  private:
    static AsteroidObjectPool *asteroidOP;

  public:
    static void createAsteroidObjectPool();
    static void deleteAsteroidObjectPool();

    static void updateAsteroids(int64_t actual_frames_count);
    static void eraseAsteroid(AsteroidObjectPool::Iterator &itr);

    static AsteroidObjectPool::Iterator getBegin();
    static AsteroidObjectPool::Iterator getEnd();
    static AsteroidObjectPool* getAOP();

};


#endif //SPACESHIP2_ASTEROIDS_INTERFACE_H
