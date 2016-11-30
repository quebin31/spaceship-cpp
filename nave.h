#ifndef NAVE_H
#define NAVE_H

#include "bitmap.h"
#include "gun.h"

#define middle_nave_x 11
#define middle_nave_y 10

#define NAVE_UP    0
#define NAVE_RIGHT 32
#define NAVE_LEFT  64

class NAVE : public BITMAP {
  private:
    GUN nave_gun;                                     /// Objeto para administrar el arma de la nave

  public:
    NAVE();                                           /// Constructor para la nave

    void select_nave(const int direction);            /// Seleccionar la posicion en la que mira la nave
    void draw_nave();                                 /// Metodo para simplificar el proceso de dibujo de la nave

    void shoot();                                     /// Accion de disparar
    void manage_gun(const ASTEROIDS_ENG &obj);        /// Metodo para administrar la el arma de la nave
};

#endif // NAVE_H
