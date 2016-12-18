//
// Created by kevin on 7/12/16.
//

#include "heart.h"

/* Heart
 * Carga una imagen al bitmap que contiene los sprites de corazones y selecciona la coordenada que corresponde al corazon con vida. */
Heart::Heart(): Bitmap("lifes.png")
{
  width = 30;
  height = 30;
  sourceX = HEART_ALIVE;
  sourceY = 0;
}

/* broken_heart
 * Modifica el valor de sourceX (coordenada x de la imagen) para que coincida con el corazon muerto.
 * Cambia el valor de destroyed por true */
void Heart::broken_heart()
{
  sourceX = HEART_DEAD;
  destroyed = true;
}

/* draw_bitmap
 * Dibuja el bitmap por regiones (sourceX, sourceY) */
void Heart::draw_bitmap(const int flags)
{ al_draw_bitmap_region(bitmap,sourceX,sourceY,width,height,float (posX),float (posY),flags); }

/* reset_bitmap
 * Resetea Heart, elige la coordenada x de la imagen que coincide con la imagen del corazon vivo.
 * Cambia el valor de destroyed por false */
void Heart::reset_bitmap()
{
  sourceX = HEART_ALIVE;
  destroyed = false;
}

bool Heart::check_colision_with(Bitmap *some)
{ return false; }
