#include "nave.h"


using namespace std;

/* Constructor NAVE:
 * "nave1.png" (char*): direccion de la imagen de la nave
 * width, height (32): valores del ancho y el alto, para detectar futuras colisiones
 * posX, posY (0): Ambas inicializadas en 0 para luego modificar sus valores
 * sourceX, sourceY (NAVE_UP, 0) : sourceX con el valor para que la nave empiece mirando hacia arriba */
NAVE::NAVE(): BITMAP("nave1.png")
{
  cout << "NAVE: Instanciando el objeto nave (" << this << ")" <<  endl;
  destroyed = false;
  width   = 32;
  height  = 32;
  cout << "NAVE: Dimensiones del objeto nave " << width << "x" << height << endl;
  posX    = 0;
  posY    = 0;
  sourceX = NAVE_UP;
  sourceY = 0;
  cout << "GUN: Instanciando el objeto nave_gun (" << (&this->nave_gun) << ")" << endl;
  cout << "NAVE: All done." << endl;
}

/* Metodos para administracion de la orientacion y dibujado de la nave
 * select_nave: utiliza macros, para saber en que posicion debe mirar la nave
 * draw_nave: dibuja la nave, agilizando el proceso */
void NAVE::select_nave(const int direction) { sourceX = direction; }
void NAVE::draw_nave(){ al_draw_bitmap_region(bitmap, sourceX, sourceY, width, height, posX, posY, 0); }


/* Metodo shoot
 * Llama al metodo de nave_gun que se encarga de crear y dibujar una nueva bala en pantalla */
void NAVE::shoot() { nave_gun.shoot_gun(posX, posY, middle_nave_x, -middle_nave_y); }

/* Metodo check_colisions
 * Verifica colisiones entre nave y asteroides
 * Y tambien entre balas y asteroides */
void NAVE::check_colisions(ASTEROIDS_ENG &obj)
{
  obj.check_asteroids(this);
}

void NAVE::move_and_draw_bullets()
{
  nave_gun.move_bullets();
  nave_gun.draw_bullets();
}

GUN* NAVE::get_gun() {
  return &(this->nave_gun);
}

