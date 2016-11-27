//
// Created by kevin on 22/11/16.
//

#include "gun.h"


using namespace std;

GUN::GUN(): munition(6), actual_munition(6) {
  for (int i=0;i<this->actual_munition;i++){
    Bullet* bullet = new Bullet;
    this->bullets.push_back(bullet);
  }
}

void GUN::wasted_bullet() {
  actual_munition -= 1;
}

const int GUN::get_actual_m() const {
  return actual_munition;
}

const int GUN::get_munition() const {
  return munition;
}

void GUN::get_info() {
  cout << "Cargador con capacidad para " << munition << " balas, actualmente tiene " << actual_munition << " balas" << endl;
}

