//
// Created by kevin on 7/12/16.
//

#include "bullet_interface.h"
//
//BULLET *NAVE_GUN::check_for_store()
//{
//  if (!store.empty())
//  {
//    BULLET* bullet = store.back();
//    store.pop_back();
//    bullet->reset_bitmap();
//    return bullet;
//  }
//  return new BULLET;
//}

NAVE_GUN::NAVE_GUN(): score(0) {}

NAVE_GUN::~NAVE_GUN()
{
  for (int i = 0; i < bullets.size(); i++)
    delete bullets[i];
}

void NAVE_GUN::create_bullet(const double naveX, const double naveY)
{
  BULLET* new_bullet = BULLETS_STORE::check_for_store();
  new_bullet->setX(naveX+middle_nave_x);
  new_bullet->setY(naveY-middle_nave_y);
  bullets.push_back(new_bullet);
}

void NAVE_GUN::update_bullets()
{
  for (int i = 0; i < bullets.size(); i++)
    if (!bullets[i]->getDestroyed())
    {
      bullets[i]->moveY(-3.0);
      bullets[i]->draw_bitmap(0);
    }
}

BULLET *NAVE_GUN::operator[](std::size_t index)
{ return bullets[index]; }

BULLET *NAVE_GUN::at(std::size_t index)
{ return bullets.at(index); }

void NAVE_GUN::erase(std::size_t index)
{
  BULLET *temp = bullets[index];
  BULLETS_STORE::put_on_store(temp);
  bullets.erase(bullets.begin() + index);
}

std::size_t NAVE_GUN::size()
{ return bullets.size(); }

bool NAVE_GUN::empty()
{ return bullets.empty(); }

void NAVE_GUN::incScore()
{ score += 5; }

void NAVE_GUN::decScore()
{
  score -= (score >= 2)? 2 : score;
}

void NAVE_GUN::incScorein(const int incS)
{ score += incS; }

void NAVE_GUN::decScorein(const int decS)
{
  score -= (score >= 30)? 30 : score;
}

int NAVE_GUN::getScore()
{ return score; }


std::vector<BULLET*> BULLETS_STORE::store;

BULLETS_STORE::~BULLETS_STORE()
{
  for (int i = 0; i < store.size(); i++)
    delete store[i];
}

BULLET *BULLETS_STORE::check_for_store()
{
  if (!store.empty())
  {
    BULLET* bullet = store.back();
    store.pop_back();
    return bullet;
  }
  return new BULLET;
}

void BULLETS_STORE::put_on_store(BULLET *bullet)
{
  bullet->reset_bitmap();
  store.push_back(bullet);
}

