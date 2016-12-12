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
    static std::vector<BULLET*> store;
  public:
    BULLETS_STORE() {}
    ~BULLETS_STORE();

    static BULLET* check_for_store();
    static void put_on_store(BULLET* bullet);
};

class NAVE_GUN
{
  private:
    std::vector<BULLET*> bullets;
    int                  score;

  public:
    NAVE_GUN();
    ~NAVE_GUN();

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


#endif //SPACESHIP2_BULLET_INTERFACE_H
