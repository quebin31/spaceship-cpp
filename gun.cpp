//
// Created by kevin on 22/11/16.
//

#include "gun.h"


using namespace std;

GUN::GUN(): munition(6), actual_munition(6), bullet_in_screen(0) {}

GUN::~GUN()
{
  for(unsigned int i = 0; i < bullets.size(); i++){
    delete this->bullets[i];
    cout << "GUN: DELETED" << endl;
  }
}

void GUN::wasted_bullet() {
  this->actual_munition -= 1;
  ++this->bullet_in_screen;
}

void GUN::get_info() {
  cout << "Cargador con capacidad para " << munition << " balas, actualmente tiene " << actual_munition << " balas" << endl;
}

void GUN::shoot_gun(coor_t X, coor_t Y, int middle_nave_X, int middle_nave_Y){
  BULLET* bullet = new BULLET;
  this->bullets.push_back(bullet);
  bullet->setX(X+middle_nave_X);
  bullet->setY(Y+middle_nave_Y);
  ++this->bullet_in_screen;
}

void GUN::check_bullets(const ASTEROIDS_ENG& obj){
  if (!bullets.empty()){
    for (unsigned int i = 0; i < bullets.size(); i++) {
      if (bullets[i]->getY() <= 50)
      {
        delete bullets[i];
        bullets.erase(bullets.begin() + i);
        cout << "GUN: Deleted a bulllet, alcanzo el limite" << endl;
      }
      else if (!bullets[i]->destroyed)
      {
        obj.check_asteroids(bullets[i]);
      }
      else
      {
        delete bullets[i];
        bullets.erase(bullets.begin() + i);
        cout << "GUN: Deleted a bulllet, colisiono" << endl;
      }
    }
  }
}

void GUN::move_bullets() {
  if (!bullets.empty())
  {
    for (unsigned int i = 0; i < bullets.size(); i++)
    {
      bullets[i]->moveY(-3.0);
    }
  }

}

void GUN::draw_bullets(){
  if (!this->bullets.empty()){
    for (unsigned int i = 0; i < this->bullets.size(); i++)
    {
      if (!bullets[i]->destroyed)
        bullets[i]->draw_bitmap(0);
    }
  }
}

void GUN::manage_gun(const ASTEROIDS_ENG& obj){
  check_bullets(obj);
  move_bullets();
  draw_bullets();
}
