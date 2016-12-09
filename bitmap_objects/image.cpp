//
// Created by kevin on 7/12/16.
//

#include "image.h"

IMAGE::IMAGE(const char *file, const int nwidth, const int nheight) : BITMAP(file)
{
  width  = nwidth;
  height = nheight;
}

void IMAGE::draw_bitmap(const int flags)
{
  al_draw_bitmap(bitmap, posX, posY, flags);
}

void IMAGE::reset_bitmap()
{
  al_destroy_bitmap(bitmap);
  bitmap = nullptr;
  width  = 0;
  height = 0;
}
