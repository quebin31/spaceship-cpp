#include "bitmap.h"

///Constructor
BITMAP::BITMAP(): bitmap(nullptr), posX(0), posY(0), sourceX(0), sourceY(0) {}

///Constructor
BITMAP::BITMAP(const char* file){
  bitmap = al_load_bitmap(file);
  posX = 0;
  posY = 0;
  sourceX = 0;
  sourceY = 0;
}

/// Destructor
BITMAP::~BITMAP() { al_destroy_bitmap(bitmap); }

/// Modifican 'x' o 'y'
void BITMAP::setX(coor_t nx) { posX = nx; }
void BITMAP::setY(coor_t ny) { posY = ny; }

/// Aumenta/disminuye 'x' o 'y'
void BITMAP::moveX(float dx) { posX += dx; }
void BITMAP::moveY(float dy) { posY += dy; }

/// Devuelve el valor de 'x' o 'y'
coor_t BITMAP::getX() { return posX; }
coor_t BITMAP::getY() { return posY; }

/// Devuelve 'width' o 'height'
int BITMAP::get_width() { return al_get_bitmap_width(bitmap); }
int BITMAP::get_height() { return al_get_bitmap_height(bitmap); }

/// Colorea el bitmap
void BITMAP::set_bitmap_color(int r, int g, int b, GAME &main) {
  al_set_target_bitmap(bitmap);
  al_clear_to_color(al_map_rgb(r,g,b));
  al_set_target_bitmap(al_get_backbuffer(main.get_display()));
}

/// Dibuja el bitmap
void BITMAP::draw_bitmap(int flags) { al_draw_bitmap(bitmap, posX, posY, flags); }




