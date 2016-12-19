//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_HEARTS_INTERFACE_H
#define SPACESHIP2_HEARTS_INTERFACE_H


#include "../bitmap_objects/heart.h"

#define NO_OF_HEARTS 3

class HeartsContainer;
class HeartsInterface;

class HeartsContainer
{
  private:
    std::vector<Heart*> hearts;

  private:
    friend class HeartsInterface;

    HeartsContainer();
    ~HeartsContainer();
};

class HeartsInterface
{
  private:
    static HeartsContainer* heartsC;

  public:
    static void createHeartsContainer();
    static void deleteHeartsContainer();

  public:

    static void draw_hearts();
    static void lost_heart();
    static void reset_hearts();

    static bool empty();
};


#endif //SPACESHIP2_HEARTS_INTERFACE_H
