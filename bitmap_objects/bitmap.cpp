//
// Created by kevin on 7/12/16.
//

#include "bitmap.h"

/* Bitmap
 * Constructor para cargar imagenes */
Bitmap::Bitmap(const char* file)
{
  bitmap = al_load_bitmap(file);
  posX = 0;
  posY = 0;
  sourceX = 0;
  sourceY = 0;
  destroyed = false;
}


/* Bitmap (virtual)
 * Puede ser sobreescrito, pero no es una obligacion.
 * Destruye la imagen cargada.*/
Bitmap::~Bitmap()
{ if (bitmap != nullptr) al_destroy_bitmap(bitmap); }

/* getX, getY
 * Devuelve posX / posY */
double Bitmap::getX() const
{ return posX; }
double Bitmap::getY() const
{ return posY; }

/* setX, setY
 * Modifica posX / posY */
void Bitmap::setX(const double x)
{ posX = x; }
void Bitmap::setY(const double y)
{ posY = y; }

/* moveX, moveY
 * Aumenta/disminuye el valor de posX / posY, dependiendo del parametro que reciba (double) */
void Bitmap::moveX(const double dx)
{ posX += dx; }
void Bitmap::moveY(const double dy)
{ posY += dy; }

/* getW, getH
 * Devuelve width/height */
int Bitmap::getW() const
{ return width; }
int Bitmap::getH() const
{ return height; }

/* setSourceX, setSourceY
 * Modifica el valor de x / y para dibujar la imagen por regiones */
void Bitmap::setSourceX(const int sourceX)
{ this->sourceX = sourceX; }
void Bitmap::setSourceY(const int sourceY)
{ this->sourceY = sourceY; }

/* setDestroyed
 * Modifica el valor de destroyed */
void Bitmap::setDestroyed(const bool destroyed)
{ this->destroyed = destroyed; }

/* getDestroyed
 * Devuelve el valor de destroyed */
bool Bitmap::getDestroyed() const
{ return destroyed; }

/* check_colision_with -> Bitmap
 * Verifica si hay o no colision entre this y el bitmap del parametro */
bool Bitmap::check_colision_with(Bitmap* some)
{
  if (this->posX + this->width >= some->posX && this->posX <= some->posX + some->width)
    if (this->posY + this->height >= some->posY && this->posY <= some->posY + some->height)
      return true;
  return false;
}




