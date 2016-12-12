//
// Created by kevin on 7/12/16.
//

#include "bitmap.h"

/* BITMAP
 * Constructor para cargar imagenes */
BITMAP::BITMAP(const char* file)
{
  bitmap = al_load_bitmap(file);
  posX = 0;
  posY = 0;
  sourceX = 0;
  sourceY = 0;
  destroyed = false;
}


/* ~BITMAP (virtual)
 * Puede ser sobreescrito, pero no es una obligacion.
 * Destruye la imagen cargada.*/
BITMAP::~BITMAP()
{ if (bitmap != nullptr) al_destroy_bitmap(bitmap); }

/* getX, getY
 * Devuelve posX / posY */
double BITMAP::getX() const
{ return posX; }
double BITMAP::getY() const
{ return posY; }

/* setX, setY
 * Modifica posX / posY */
void BITMAP::setX(const double x)
{ posX = x; }
void BITMAP::setY(const double y)
{ posY = y; }

/* moveX, moveY
 * Aumenta/disminuye el valor de posX / posY, dependiendo del parametro que reciba (double) */
void BITMAP::moveX(const double dx)
{ posX += dx; }
void BITMAP::moveY(const double dy)
{ posY += dy; }

/* getW, getH
 * Devuelve width/height */
int BITMAP::getW() const
{ return width; }
int BITMAP::getH() const
{ return height; }

/* setSourceX, setSourceY
 * Modifica el valor de x / y para dibujar la imagen por regiones */
void BITMAP::setSourceX(const int sourceX)
{ this->sourceX = sourceX; }
void BITMAP::setSourceY(const int sourceY)
{ this->sourceY = sourceY; }

/* setDestroyed
 * Modifica el valor de destroyed */
void BITMAP::setDestroyed(const bool destroyed)
{ this->destroyed = destroyed; }

/* getDestroyed
 * Devuelve el valor de destroyed */
bool BITMAP::getDestroyed() const
{ return destroyed; }

/* check_colision_with -> BITMAP
 * Verifica si hay o no colision entre this y el bitmap del parametro */
bool BITMAP::check_colision_with(BITMAP* some)
{
  if (this->posX + this->width >= some->posX && this->posX <= some->posX + some->width)
    if (this->posY + this->height >= some->posY && this->posY <= some->posY + some->height)
      return true;
  return false;
}




