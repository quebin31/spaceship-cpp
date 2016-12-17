//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_HEARTS_INTERFACE_H
#define SPACESHIP2_HEARTS_INTERFACE_H


#include "../bitmap_objects/heart.h"

#define NO_OF_HEARTS 3

class Hearts
{
  private:
    std::vector<HEART*> hearts;

  public:
    Hearts();
    ~Hearts();

    void draw_hearts();
    void lost_heart();

    bool empty();
};


#endif //SPACESHIP2_HEARTS_INTERFACE_H
