//
// Created by kevin on 7/12/16.
//

#include "asteroid.h"

/* Arreglo de enteros, que contienen las coordenadas X de donde empieza un tipo diferente de asteroide*/
int ASTEROID::type_asters[] = {0,45,90,135,180};

/* generate_random_type
 * Genera un numero aleatorio (int) del 0 al 4.
 * El numero generado representa el index en type_asters */
int ASTEROID::generate_random_type()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(0, 4);
  return distr(eng);
}

/* generate_random_X
 * Genera un numero aleatorio (double) del 30 al 490.
 * El numero generado representa la coordenada x donde sera dibujado inicialmente el asteroide */
double ASTEROID::generate_random_X()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_real_distribution<> distr(30, 490);
  return distr(eng);
}

/* generate_random_Y
 * Genera un numero aleatorio (double) del 0 al 30
 * El numero generado representa la coordenada y donde sera dibujado inicialmente el asteroide */
double ASTEROID::generate_random_Y()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_real_distribution<> distr(0,30);
  return distr(eng);
}

/* ASTEROID
 * Carga la imagen con los sprites de los asteroides.
 * Genera un tipo aleatorio, coordenada X aleatoria y coordenada Y aleatoria */
ASTEROID::ASTEROID(): BITMAP("asteroides.png")
{
  width    = 45;
  height   = 45;
  posX     = generate_random_X();
  posY     = generate_random_Y();
  int type = generate_random_type();
  sourceX  = type_asters[type];
}

/* check_colision_with -> BITMAP
 * Verifica si hay colision entre this y algun BITMAP.
 * Si es que si modifica los valores de destroyed de ambos bitmap por true.
 * Usado con nave.*/
bool ASTEROID::check_colision_with(BITMAP *some)
{
  if (this->posX + this->width >= some->getX() && this->posX <= some->getX() + some->getW())
    if (this->posY + this->height >= some->getY() && this->posY <= some->getY() + some->getH())
    {
      this->destroyed = true;
      some->setDestroyed(true);
      return true;
    }
  return false;
}

/* draw_bitmap
 * Dibuja el bitmap del asteroide por regiones. */
void ASTEROID::draw_bitmap(const int flags)
{ al_draw_bitmap_region(bitmap,sourceX,sourceY,width,height,float (posX), float (posY),flags); }

/* reset_bitmap
 * Resetea los valores del asteroide.
 * Todo generado aleatoriamente otra vez */
void ASTEROID::reset_bitmap()
{
  posX      = generate_random_X();
  posY      = generate_random_Y();
  int type  = generate_random_type();
  sourceX   = type_asters[type];
  destroyed = false;
}

