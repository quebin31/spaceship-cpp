#include "bitmap.h"

///Constructor
BITMAP::BITMAP() {

}

///Constructor
BITMAP::BITMAP(const char* file){
    bitmap = al_load_bitmap(file);
}

/// Destructor
BITMAP::~BITMAP() { al_destroy_bitmap(bitmap); }

/// Modifica 'x'
void BITMAP::setX(coor_t nx) { posX = nx; }

/// Modifica 'y'
void BITMAP::setY(coor_t ny) { posY = ny; }

/// Aumenta/disminuye 'x'
void BITMAP::moveX(float dx) { posX += dx; }

/// Aumenta/disminuye 'y'
void BITMAP::moveY(float dy) { posY += dy; }

/// Devuelve el valor de 'x'
coor_t BITMAP::getX() { return posX; }

/// Devuelve el valor de 'y'
coor_t BITMAP::getY() { return posY; }

/// Devuelve 'width'
int BITMAP::get_width() { return al_get_bitmap_width(bitmap); }

/// Devuelve 'height'
int BITMAP::get_height() { return al_get_bitmap_height(bitmap); }

/// Colorea el bitmap
void BITMAP::set_bitmap_color(int r, int g, int b, GAME &main) {
  al_set_target_bitmap(bitmap);
  al_clear_to_color(al_map_rgb(r,g,b));
  al_set_target_bitmap(al_get_backbuffer(main.get_display()));
}

/// Dibuja el bitmap
void BITMAP::draw_bitmap(int flags) { al_draw_bitmap(bitmap, x, y, flags); }




