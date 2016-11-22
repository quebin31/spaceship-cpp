//
// Created by kevin on 22/11/16.
//

#ifndef SPACESHIP_BULLETS_H
#define SPACESHIP_BULLETS_H


#include "bitmap.h"

class GUN: public BITMAP {
private:
  int munition;
  int actual_munition;
public:
  GUN();

  void wasted_bullet();
  const int get_actual_m() const;
  const int get_munition() const;
  void get_info();
};


#endif //SPACESHIP_BULLETS_H
