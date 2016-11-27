//
// Created by kevin on 22/11/16.
//

#ifndef SPACESHIP_BULLETS_H
#define SPACESHIP_BULLETS_H

#include "allegro_includes.h"
#include "bullet.h"

using namespace std;

class GUN : public Bullet{
private:
  int munition;
  int actual_munition;
  vector<Bullet*> bullets;
public:
  GUN();
  void wasted_bullet();
  const int get_actual_m() const;
  const int get_munition() const;
  void get_info();
};


#endif //SPACESHIP_BULLETS_H
