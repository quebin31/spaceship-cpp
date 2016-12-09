//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_BULLET_INTERFACE_H
#define SPACESHIP2_BULLET_INTERFACE_H

#define middle_nave_x 11
#define middle_nave_y 10

#include "../tools_and_headers/spaceship_includes.h"
#include "../bitmap_objects/bullet.h"

class NAVE_GUN
{
  private:
    std::vector<BULLET*> bullets;
    std::vector<BULLET*> store;
    int                  score;

    BULLET* check_for_store();

  public:
    NAVE_GUN();
    ~NAVE_GUN();

    void put_on_store(std::size_t index);

    void create_bullet(const float naveX, const float naveY);
    void update_bullets();
    void inc_score();

    std::size_t size();
    bool empty();

    BULLET* operator[](std::size_t index);

    int getScore();
};


#endif //SPACESHIP2_BULLET_INTERFACE_H
