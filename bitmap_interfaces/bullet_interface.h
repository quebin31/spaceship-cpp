//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_BULLET_INTERFACE_H
#define SPACESHIP2_BULLET_INTERFACE_H

#define middle_nave_x 11
#define middle_nave_y 10

#include "../bitmap_objects/bullet.h"

class BULLETS_STORE
{
  private:
    std::vector<BULLET*> store;
    const char* archivo;
    int width;
    int height;
  public:
    BULLETS_STORE(const char*, int, int);
    ~BULLETS_STORE();

    BULLET* check_for_store();
    void put_on_store(BULLET* bullet);
};

class NaveGun
{
  private:
    std::vector<BULLET*> bullets;
    int                  score;
    BULLETS_STORE* store_bullets;
    const char* archivo;
    int width;
    int height;
  public:
    NaveGun(const char*, int, int);
    ~NaveGun();

    void erase(std::size_t index);

    void create_bullet(const double naveX, const double naveY);
    void update_bullets();

    BULLET* operator[](std::size_t index);
    BULLET* at(std::size_t index);
    std::size_t size();
    bool empty();

    void incScore();
    void decScore();
    void incScorein(const int incS);
    void decScorein(const int decS);
    int getScore();
};

class AbstractFactory{

};


#endif //SPACESHIP2_BULLET_INTERFACE_H
