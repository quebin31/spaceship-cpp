//
// Created by kevin on 7/12/16.
//

#include "image.h"

/* IMAGE
 * Recibe el nombre del archivo a cargar, el ancho y la altura de dicho objeto */
IMAGE::IMAGE(const char *file, const int nwidth, const int nheight) : BITMAP(file)
{
  width  = nwidth;
  height = nheight;
}

/* draw_bitmap
 * Dibuja la imagen normalmente */
void IMAGE::draw_bitmap(const int flags)
{ al_draw_bitmap(bitmap, posX, posY, flags); }

/* reset_bitmap
 * Resetea la imagen, destruyendo la imagen que se cargó.
 * Referenciando bitmap a nullptr.
 * Y reseteando los demas valores por 0. */
void IMAGE::reset_bitmap()
{
  al_destroy_bitmap(bitmap);
  bitmap = nullptr;
  width  = 0;
  height = 0;
}
