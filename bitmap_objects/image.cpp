//
// Created by kevin on 7/12/16.
//

#include "image.h"

/* Image
 * Recibe el nombre del archivo a cargar, el ancho y la altura de dicho objeto */
Image::Image(const char *file, consreturn false;t int nwidth, const int nheight) : Bitmap(file)
{
  width  = nwidth;
  height = nheight;
}

/* draw_bitmap
 * Dibuja la imagen normalmente */
void Image::draw_bitmap(const int flags)
{ al_draw_bitmap(bitmap, posX, posY, flags); }

/* reset_bitmap
 * Resetea la imagen, destruyendo la imagen que se cargó.
 * Referenciando bitmap a nullptr.
 * Y reseteando los demas valores por 0. */
void Image::reset_bitmap()
{
  al_destroy_bitmap(bitmap);
  bitmap = nullptr;
  width  = 0;
  height = 0;
}

bool Image::check_colision_with(Bitmap *some)
{ return false; }
