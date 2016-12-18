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
    static BulletObjPool* bulletOP;
    static int score;

  public:
    static void createBulletObjPool();
    static void deleteBulletObjPool();

    static void updateBullets();
    static void createBullet(const double naveX, const double naveY);
    static void eraseBullet(BulletObjPool::Iterator &itr);

    static void incGunScoreIn(const int incS = 5);
    static void decGunScoreIn(const int decS = 2);
    static void resetGunScore();

    static int                     getScore();
    static BulletObjPool::Iterator getBegin();
    static BulletObjPool::Iterator getEnd();
    static BulletObjPool*          getBOP();
};

//class BULLETS_STORE
//{
//  private:
//    std::vector<BaseBullet*> store;
//    const char* archivo;
//    int width;
//    int height;
//  public:
//    BULLETS_STORE(const char*, int, int);
//    ~BULLETS_STORE();
//
//    BaseBullet* check_for_store();
//    void put_on_store(BaseBullet* bullet);
//};
//
//class NaveGun
//{
//  private:
//    std::vector<BaseBullet*> bullets;
//    static int           score;
//    BULLETS_STORE* store_bullets;
//    const char* archivo;
//    int width;
//    int height;
//  public:
//    NaveGun(const char*, int, int);
//    ~NaveGun();
//
//    void erase(std::size_t index);
//
//    void create_bullet(const double naveX, const double naveY);
//    void update_bullets();
//
//    BaseBullet* operator[](std::size_t index);
//    BaseBullet* at(std::size_t index);
//    std::size_t size();
//    bool empty();
//
//    void incScore();
//    void decScore();
//    void resetScore();
//    void incScorein(const int incS);
//    void decScorein(const int decS);
//    int getScore();
//};

#endif //SPACESHIP2_BULLET_INTERFACE_H
