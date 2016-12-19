//
// Created by kevin on 7/12/16.
//

#include "hearts_interface.h"

/* =======================================================================================================================================================================*/

HeartsContainer::HeartsContainer()
{
  float posX = 50.0;
  for (int i = 0; i < NO_OF_HEARTS; i++)
  {
    Heart* new_heart = new Heart;
    new_heart->setX(posX);
    new_heart->setY(35.0);
    hearts.push_back(new_heart);
    posX += 35.0;
  }
}

HeartsContainer::~HeartsContainer()
{
  for (int i = 0; i < NO_OF_HEARTS; i++)
    delete hearts[i];
}

/* =======================================================================================================================================================================*/

HeartsContainer* HeartsInterface::heartsC = 0;

void HeartsInterface::createHeartsContainer()
{ if (!heartsC) heartsC = new HeartsContainer; }

void HeartsInterface::deleteHeartsContainer()
{ delete heartsC; }

void HeartsInterface::draw_hearts()
{
  for (int i = 0; i < NO_OF_HEARTS; i++)
    heartsC->hearts[i]->draw_bitmap(0);
}

void HeartsInterface::lost_heart()
{
  for (int i = NO_OF_HEARTS - 1; i >= 0; i--)
    if (!heartsC->hearts[i]->getDestroyed())
    {
      heartsC->hearts[i]->broken_heart();
      return;
    }
}

void HeartsInterface::reset_hearts()
{
  for (int i = 0; i < NO_OF_HEARTS; i++)
    heartsC->hearts[i]->reset_bitmap();
}

bool HeartsInterface::empty()
{ return heartsC->hearts.front()->getDestroyed(); }

/* =======================================================================================================================================================================*/
