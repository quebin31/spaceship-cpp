//
// Created by kevin on 22/11/16.
//

#include "gun.h"


using namespace std;

GUN::GUN(): munition(6), actual_munition(6), bullet_in_screen(0) {}

GUN::~GUN(){
  for(unsigned int i=0;i<this->bullets.size();i++){
    delete this->bullets.at(i);
    cout << "GUN: DELETED" << endl;
  }
}

void GUN::wasted_bullet() {
  this->actual_munition -= 1;
  ++this->bullet_in_screen;
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

void GUN::shoot_gun(int X, int Y, int middle_nave_X, int middle_nave_Y){
  if(this->bullet_in_screen < this->munition){
    BULLET* bullet = new BULLET;
    this->bullets.push_back(bullet);
    bullet->moveX(X+middle_nave_X);
    bullet->moveY(Y+middle_nave_Y);
    ++this->bullet_in_screen;
  }
}

void GUN::check_gun(){
  if (!this->bullets.empty()){
    for (unsigned int i=0;i<this->bullets.size();i++){
      if (this->bullets.at(i)->getY() < 0 && this->bullets.at(i)->destroyed!=true){
        this->bullets.at(i)->destroyed=true;
        --this->actual_munition;
        --this->bullet_in_screen;
      }
      if (this->bullets.at(i)->destroyed==false)
        this->bullets.at(i)->moveY(-1.0);
    }
  }
}

void GUN::draw_bullets(){
  if (!this->bullets.empty()){
    for (unsigned int i=0;i<this->bullets.size();i++){
      if (this->bullets.at(i)->destroyed==false)
        this->bullets.at(i)->draw_bitmap(0);
    }
  }
}

void GUN::managed_gun(){
  check_gun();
  draw_bullets();
}
