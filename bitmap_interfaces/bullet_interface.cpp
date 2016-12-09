//
// Created by kevin on 7/12/16.
//

#include "bullet_interface.h"

BULLET *NAVE_GUN::check_for_store()
{
  if (not store.empty())
  {
    BULLET* bullet = store.back();
    store.pop_back();
    bullet->reset_bitmap();
    return bullet;
  }
  return new BULLET;
}

NAVE_GUN::NAVE_GUN(): score(0) {}

NAVE_GUN::~NAVE_GUN()
{
  for (int i = 0; i < bullets.size(); i++)
    delete bullets[i];
  for (int i = 0; i < store.size(); i++)
    delete store[i];
}

void NAVE_GUN::create_bullet(const float naveX, const float naveY)
{
  BULLET* new_bullet = check_for_store();
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

BULLET *NAVE_GUN::operator[](std::size_t index) { return bullets[index]; }

void NAVE_GUN::put_on_store(std::size_t index)
{
  store.push_back(bullets[index]);
  bullets.erase(bullets.begin()+index);
}

std::size_t NAVE_GUN::size() { return bullets.size(); }
bool NAVE_GUN::empty() { return bullets.empty(); }


int NAVE_GUN::getScore() { return score; }

void NAVE_GUN::inc_score() { score += 5; }
