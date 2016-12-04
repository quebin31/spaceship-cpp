#include "lifes.h"

using namespace std;

LIFE::LIFE(): BITMAP("lifes.png")
{
  width = 30;
  height = 30;
  sourceX = HEART_ALIVE;
  sourceY = 0;
  destroyed = false;
}

void LIFE::draw_life() { al_draw_bitmap_region(bitmap, sourceX, sourceY, width, height, posX, posY, 0); }

void LIFE::lost_life()
{
  sourceX = HEART_DEAD;
  destroyed = true;
}

void LIFE::recovery_life()
{
  sourceX = HEART_ALIVE;
  destroyed = false;
}



LIFES::LIFES()
{
  coor_t coorX = 50;
  for (unsigned int i = 0; i < NO_OF_HEARTS; i++)
  {
    LIFE* new_life = new LIFE;
    new_life->setY(35);
    new_life->setX(coorX);
    lifes.push_back(new_life);
    coorX += 35;
  }
  cout << "LIFES: Created" << endl;
}

LIFES::~LIFES()
{
  for (int i = 0; i < NO_OF_HEARTS; i++)
  {
    delete lifes[i];
  }
  cout << "LIFES: Deleted" << endl;
}

void LIFES::draw_lifes()
{
  for (int i = 0; i < NO_OF_HEARTS; i++)
    lifes[i]->draw_life();
}

void LIFES::lost_a_life()
{
  for (int i = NO_OF_HEARTS - 1; i >= 0; i--)
  {
    if (!lifes[i]->destroyed)
    {
      lifes[i]->lost_life();
      return;
    }
  }
}
