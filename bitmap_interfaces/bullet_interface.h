//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_BULLET_INTERFACE_H
#define SPACESHIP2_BULLET_INTERFACE_H

#define middle_nave_x 11
#define middle_nave_y 10

#define BULLET_TYPE 0
#define LASER_TYPE  1

#include "../bitmap_objects/bullet.h"

class BulletFactory;
class BulletObjPool;
class BulletInterface;

class BulletFactory
{
  private:
    static int actual_type;

  private:
    static BaseBullet* check_for_store(BulletObjPool* setofbullets);

  public:
    static void        changeFactoryType(const int new_type);
    static int         returnFactoryType();
    static BaseBullet* generateBulletFor(BulletObjPool *setofbullets);

};

class BulletObjPool
{
  private:
    std::vector<BaseBullet*> bullets_on_use;
    std::vector<BaseBullet*> store;

  private:
    friend class BulletFactory;
    friend class BulletInterface;

  public:
    class Iterator
    {
      private:
        BulletObjPool* bp;
        int index;

      private:
        friend class BulletObjPool;

      public:
        Iterator(BulletObjPool& _bp);
        Iterator(BulletObjPool* _bp);
        Iterator(const Iterator& itr);

        Iterator& operator++();
        Iterator  operator++(int);
        Iterator  operator+(const int sum);
        bool      operator==(const Iterator& itr);
        bool      operator!=(const Iterator& itr);
        BaseBullet*   operator*();
    };

    BulletObjPool();
    ~BulletObjPool();

    BaseBullet* at(const int index);
    BaseBullet* operator[](const int index);
    std::size_t size();
    void        erase(Iterator& itr);

    Iterator begin();
    Iterator end();
};

class BulletInterface
{
  private:
    static BulletObjPool *bulletOP;
    static int            score;

  public:
    static void createBulletObjPool();
    static void deleteBulletObjPool();

    static void updateBullets();
    static void createBullet(const double naveX, const double naveY);
    static void eraseBullet(BulletObjPool::Iterator &itr);

    static void incGunScoreIn(const int incS = 5);
    static void decGunScoreIn(const int decS = 2);
    static void resetGunScore();

    static void changeType(const int new_type);
    static int  returnType();

    static int                     getScore();
    static BulletObjPool::Iterator getBegin();
    static BulletObjPool::Iterator getEnd();
    static BulletObjPool*          getBOP();
};

#endif //SPACESHIP2_BULLET_INTERFACE_H
