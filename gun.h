//
// Created by kevin on 22/11/16.
//

#ifndef SPACESHIP_BULLETS_H
#define SPACESHIP_BULLETS_H

#include "allegro_includes.h"
#include "bullet.h"

using namespace std;

class GUN {
private:
  int munition;
  int actual_munition;                  /// At the reserve
  int bullet_in_screen;                 /// In the screen
  vector<BULLET*> bullets;
public:
  GUN();
  ~GUN();

  void wasted_bullet();
  const int get_actual_m() const;
  const int get_munition() const;
  void get_info();
  void shoot_gun(int X, int Y, int middle_nave_X, int middle_nave_Y);
  void check_gun();
  void draw_bullets();
  void manage_gun();
};


#endif //SPACESHIP_BULLETS_H
