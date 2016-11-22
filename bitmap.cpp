#include "bitmap.h"
///Constructor
BITMAP::BITMAP(const char* file){
    bitmap = al_load_bitmap(file);
}
///// Constructor
//BITMAP::BITMAP(int sz, bool img): width(sz), height(sz) {
//  if (!img) bitmap = al_create_bitmap(width,height);
//}
//
///// Constructor
//BITMAP::BITMAP(int w, int h, bool img): width(w), height(h) {
//  if (!img) bitmap = al_create_bitmap(width,height);
//}
//
///// Constructor
//BITMAP::BITMAP(coor_t nx, coor_t ny, bool img): x(nx), y(ny) {
//  if (!img) bitmap = al_create_bitmap(width,height);
//}
//
///// Constructor
//BITMAP::BITMAP(coor_t nx, coor_t ny, int sz, bool img): x(nx), y(ny), width(sz), height(sz) {
//  if (!img) bitmap = al_create_bitmap(width,height);
//}
//
///// Constructor
//BITMAP::BITMAP(coor_t nx, coor_t ny, int w, int h, bool img): x(nx), y(ny), width(w), height(h) {
//  if (!img) bitmap = al_create_bitmap(width,height);
//}

/// Destructor
BITMAP::~BITMAP() { al_destroy_bitmap(bitmap); }

/// Modifica 'x'
void BITMAP::setX(coor_t nx) { x = nx; }

/// Modifica 'y'
void BITMAP::setY(coor_t ny) { y = ny; }

/// Aumenta/disminuye 'x'
void BITMAP::moveX(float dx) { x += dx; }

/// Aumenta/disminuye 'y'
void BITMAP::moveY(float dy) { y += dy; }

/// Devuelve el valor de 'x'
coor_t BITMAP::getX() { return x; }

/// Devuelve el valor de 'y'
coor_t BITMAP::getY() { return y; }

/// Modifica 'width'
void BITMAP::set_width(int w) { width = w; }

/// Modifica 'height'
void BITMAP::set_height(int h) { height = h; }

/// Devuelve 'width'
int BITMAP::get_width() { return width; }

/// Devuelve 'height'
int BITMAP::get_height() { return height; }

/// Colorea el bitmap
void BITMAP::set_bitmap_color(int r, int g, int b, GAME &main) {
  al_set_target_bitmap(bitmap);
  al_clear_to_color(al_map_rgb(r,g,b));
  al_set_target_bitmap(al_get_backbuffer(main.get_display()));
}

/// Dibuja el bitmap
void BITMAP::draw_bitmap(int flags) { al_draw_bitmap(bitmap, x, y, flags); }




