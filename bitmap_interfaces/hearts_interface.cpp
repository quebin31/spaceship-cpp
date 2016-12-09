//
// Created by kevin on 7/12/16.
//

#include "hearts_interface.h"

HEARTS::HEARTS()
{
  float posX = 50.0;
  for (int i = 0; i < NO_OF_HEARTS; i++)
  {
    HEART* new_heart = new HEART;
    new_heart->setX(posX);
    new_heart->setY(35.0);
    hearts.push_back(new_heart);
    posX += 35.0;
  }
}

HEARTS::~HEARTS()
{
  for (int i = 0; i < NO_OF_HEARTS; i++)
    delete hearts[i];
}

void HEARTS::draw_hearts()
{
  for (int i = 0; i < NO_OF_HEARTS; i++)
    hearts[i]->draw_bitmap(0);
}

void HEARTS::lost_heart()
{
  for (int i = NO_OF_HEARTS - 1; i >= 0; i--)
    if (!hearts[i]->getDestroyed())
    {
      hearts[i]->broken_heart();
      return;
    }
}

bool HEARTS::empty()
{
  return hearts.front()->getDestroyed();
}
