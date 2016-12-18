//
// Created by kevin on 7/12/16.
//

#include "nave.h"
#include "../bitmap_interfaces/bullet_interface.h"

Nave* Nave::_instance = 0;

/* Nave
 * Carga una imagen para nave.
 * Selecciona el sourceX.
 * Configura los valores de altura y ancho */
Nave::Nave(): Bitmap("nave1.png")
{
  nave_gun     = new NaveGun("bullet2.png", 10, 10);
  width        = 32;
  height       = 32;
  sourceX      = NAVE_UP;
}

/* Nave
 * Aparte de destruir la imagen que cargó, tambien destruye nave_gun */
Nave::~Nave()
{
  delete nave_gun;
  std::cout << "Destruyendo la nave" << std::endl;
}

Nave *Nave::Instance()
{
  if (!_instance)
    _instance = new Nave;
  return _instance;
}

/* shoot_gun
 * Invoca el metodo del arma (nave_gun) -> create_bullet.
 * Crea una nueva bala, de acuerdo a la posicion actual de la nave */
void Nave::shoot_gun()
{ nave_gun->create_bullet(posX, posY); }

/* update_bullets
 * Invoca el metodo del arma (nave_gun) -> update_bullets
 * Mueve y dibuja las balas.*/
void Nave::update_bullets()
{ nave_gun->update_bullets(); }

/* getGun
 * Devuelve por referencia nave_gun */
NaveGun *Nave::getGun()
{ return nave_gun; }

/* make_invulnerable
 * Vuelve invulnerable a la nave.
 * El valor de destroyed se cambia a true.
 * El valor de destroyed_at guarda el numero de fotogramas que se habian contado hasta ese momento
 * Ademas, reduce la puntacion en 30 (si es que se puede). */
void Nave::make_invulnerable(const int64_t fps_count)
{
  destroyed    = true;
  destroyed_at = fps_count;
  nave_gun->decScorein(30);
}

/* make_vulnerable
 * Vuelve vulnerable a la nave.
 * El valor de destroyed se cambia a false. */
void Nave::make_vulnerable()
{ destroyed = false; }

/* getWhenDestroyed
 * Devuelve destroyed_at (que marca el numero de fotogramas contandos al momento en el que la nave colisiono) */
int64_t Nave::getWhenDestroyed()
{ return destroyed_at; }

/* draw_bitmap
 * Dibuja la nave de acuerdo a sourceX, sourceY (dibujado por region) */
void Nave::draw_bitmap(const int flags)
{ al_draw_bitmap_region(bitmap, sourceX, sourceY, width, height, float (posX), float (posY), flags); }

/* reset_bitmap
 * Resetea todos los miembros datos de la clase Nave */
void Nave::reset_bitmap()
{
  posX         = 0;
  posY         = 0;
  sourceX      = NAVE_UP;
  sourceY      = 0;
  destroyed    = false;
  destroyed_at = 0;
}

