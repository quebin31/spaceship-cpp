//
// Created by kevin on 7/12/16.
//

#include "bullet_interface.h"
/* =======================================================================================================================================================================*/

int BulletFactory::actual_type = LASER_TYPE;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "missing_default_case"
BaseBullet *BulletFactory::check_for_store(BulletObjPool *setofbullets)
{
  if (!setofbullets->store.empty())
  {
    BaseBullet* pBullet = setofbullets->store.back();
    setofbullets->store.pop_back();
    return pBullet;
  }

  switch (BulletFactory::actual_type)
  {
    case BULLET_TYPE:
      std::cout << "Generando balas normales" << std::endl;
      return new Bullet;
    case LASER_TYPE:
      std::cout << "Generando balas laser" << std::endl;
      return new Laser;
  }
}
#pragma clang diagnostic pop

void BulletFactory::changeFactoryType(const int new_type)
{ BulletFactory::actual_type = new_type; }

int BulletFactory::returnFactoryType()
{ return BulletFactory::actual_type; }

BaseBullet *BulletFactory::generateBulletFor(BulletObjPool *setofbullets)
{
  BaseBullet* pBaseBullet = check_for_store(setofbullets);
  return pBaseBullet;
}

/* =======================================================================================================================================================================*/

BulletObjPool::Iterator::Iterator(BulletObjPool &_bp): bp(&_bp), index(0) {}
BulletObjPool::Iterator::Iterator(BulletObjPool *_bp): bp(_bp), index (0) {}
BulletObjPool::Iterator::Iterator(const BulletObjPool::Iterator &itr): bp(itr.bp), index (itr.index) {}

BulletObjPool::Iterator &BulletObjPool::Iterator::operator++()
{
  index++;
  return (*this);
}

BulletObjPool::Iterator BulletObjPool::Iterator::operator++(int)
{
  Iterator temp_itr = *this;
  ++(*this);
  return temp_itr;
}

BulletObjPool::Iterator BulletObjPool::Iterator::operator+(const int sum)
{
  Iterator temp_itr = *this;
  temp_itr.index += sum;
  return temp_itr;
}

bool BulletObjPool::Iterator::operator==(const BulletObjPool::Iterator &itr)
{ return (this->index == itr.index); }

bool BulletObjPool::Iterator::operator!=(const BulletObjPool::Iterator &itr)
{ return (this->index != itr.index); }

BaseBullet *BulletObjPool::Iterator::operator*()
{ return bp->bullets_on_use[index]; }

int BulletObjPool::Iterator::getIndex()
{ return index; }

/* =======================================================================================================================================================================*/

BulletObjPool::BulletObjPool() {}

BulletObjPool::~BulletObjPool()
{
  for (unsigned i = 0; i < bullets_on_use.size(); i++)
    delete bullets_on_use[i];
  for (unsigned i = 0; i < store.size(); i++)
    delete store[i];
}

BaseBullet *BulletObjPool::at(const int index)
{ return bullets_on_use.at((unsigned long) index);}

BaseBullet *BulletObjPool::operator[](const int index)
{ return bullets_on_use[index]; }

std::size_t BulletObjPool::size()
{ return bullets_on_use.size(); }

void BulletObjPool::erase(BulletObjPool::Iterator &itr)
{
  BaseBullet* bbullet = (*itr);
  bbullet->reset_bitmap();
  store.push_back(bbullet);
  bullets_on_use.erase(bullets_on_use.begin() + itr.index);
  itr.index -= 1;
}

BulletObjPool::Iterator BulletObjPool::begin()
{
  Iterator temp(this);
  temp.index = 0;
  return temp;
}

BulletObjPool::Iterator BulletObjPool::end()
{
  Iterator temp(this);
  temp.index = (int) (bullets_on_use.size() - 1);
  return temp;
}

/* =======================================================================================================================================================================*/

BulletObjPool* BulletInterface::bulletOP = 0;
int            BulletInterface::score = 0;

void BulletInterface::createBulletObjPool()
{ if (!bulletOP) bulletOP = new BulletObjPool; }

void BulletInterface::deleteBulletObjPool()
{ delete bulletOP; }

void BulletInterface::updateBullets()
{
  for (BulletObjPool::Iterator itr = bulletOP->begin(); itr != bulletOP->end() + 1; itr++)
    if (!(*itr)->getDestroyed())
    {
      (*itr)->moveY(-3.0);
      (*itr)->draw_bitmap(0);
    }
}

void BulletInterface::createBullet(const double naveX, const double naveY)
{
  BaseBullet* pBBullet = BulletFactory::generateBulletFor(bulletOP);
  pBBullet->setX(naveX+middle_nave_x);
  pBBullet->setY(naveY-middle_nave_y);
  bulletOP->bullets_on_use.push_back(pBBullet);
}

void BulletInterface::eraseBullet(BulletObjPool::Iterator &itr)
{ bulletOP->erase(itr); }

void BulletInterface::incGunScoreIn(const int incS)
{ score += incS; }

void BulletInterface::decGunScoreIn(const int decS)
{ score -= (score >= decS)? decS : score; }

void BulletInterface::resetGunScore()
{ score = 0; }

void BulletInterface::changeType(const int new_type)
{
  BulletFactory::changeFactoryType(new_type);
  for (unsigned i = 0; i < bulletOP->store.size(); i++)
    delete bulletOP->store[i];
  bulletOP->store.clear();
}

int BulletInterface::returnType()
{ return BulletFactory::returnFactoryType(); }

BulletObjPool::Iterator BulletInterface::getBegin()
{ return bulletOP->begin(); }

BulletObjPool::Iterator BulletInterface::getEnd()
{ return bulletOP->end(); }

int BulletInterface::getScore()
{ return score; }

BulletObjPool *BulletInterface::getBOP()
{ return bulletOP; }

/* =======================================================================================================================================================================*/