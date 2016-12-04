//
// Created by kevin on 22/11/16.
//

#ifndef SPACESHIP_BULLETS_H
#define SPACESHIP_BULLETS_H

#include "allegro_includes.h"
#include "bullet.h"
#include "asteroids_engine.h"

using namespace std;

class GUN {
  private:
    int munition;                                                                   /// Municion del arma
    int actual_munition;                                                            /// Municion disponible
    int bullets_in_screen;                                                           /// Balas en pantalla
    vector<BULLET*> bullets;                                                        /// Vector que guarda todas las balas que han sido creadas

  public:
    GUN();                                                                          /// Constructor
    ~GUN();                                                                         /// Destructor
    int score;
    void shoot_gun(coor_t X, coor_t Y, int middle_nave_X, int middle_nave_Y);       /// Disparar una bala

    void check_bullets(BITMAP& obj);                                                /// Verifica el estado de las balas
    void move_bullets();                                                            /// Mueve las balas
    void draw_bullets();                                                            /// Dibuja las balas
};


#endif //SPACESHIP_BULLETS_H
