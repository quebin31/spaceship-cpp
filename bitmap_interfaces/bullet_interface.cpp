//
// Created by kevin on 7/12/16.
//

#include "bullet_interface.h"
//
//BULLET *NaveGun::check_for_store()
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

NaveGun::NaveGun(const char* _archivo, int _width, int _height): score(0), archivo(_archivo), width(_width), height(_height){
  store_bullets = new BULLETS_STORE(archivo, width, height);
}

NaveGun::~NaveGun()
{
  for (unsigned i = 0; i < bullets.size(); i++)
    delete bullets[i];
  delete store_bullets;
}

void NaveGun::create_bullet(const double naveX, const double naveY)
{
  BULLET* new_bullet = store_bullets->check_for_store();
  new_bullet->setX(naveX+middle_nave_x);
  new_bullet->setY(naveY-middle_nave_y);
  bullets.push_back(new_bullet);
}

void NaveGun::update_bullets()
{
  for (unsigned i = 0; i < bullets.size(); i++)
    if (!bullets[i]->getDestroyed())
    {
      bullets[i]->moveY(-3.0);
      bullets[i]->draw_bitmap(0);
    }
}

BULLET *NaveGun::operator[](std::size_t index)
{ return bullets[index]; }

BULLET *NaveGun::at(std::size_t index)
{ return bullets.at(index); }

void NaveGun::erase(std::size_t index)
{
  BULLET *temp = bullets[index];
  store_bullets->put_on_store(temp);
  bullets.erase(bullets.begin() + index);
}

std::size_t NaveGun::size()
{ return bullets.size(); }

bool NaveGun::empty()
{ return bullets.empty(); }

void NaveGun::incScore()
{ score += 5; }

void NaveGun::decScore()
{
  score -= (score >= 2)? 2 : score;
}

void NaveGun::incScorein(const int incS)
{ score += incS; }

void NaveGun::decScorein(const int decS)
{
  score -= (score >= 30)? 30 : score;
}

int NaveGun::getScore()
{ return score; }

BULLETS_STORE::BULLETS_STORE(const char*_archivo, int _width, int _height): archivo(_archivo), width(_width), height(_height) {}

BULLETS_STORE::~BULLETS_STORE()
{
  for (unsigned i = 0; i < store.size(); i++)
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
  return new BULLET(archivo, width, height);
}

void BULLETS_STORE::put_on_store(BULLET *bullet)
{
  bullet->reset_bitmap();
  store.push_back(bullet);
}

