#include "bitmap.h"
#include "game.h"

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

/// Devuelve el valor del ancho/alura del bitmap
int BITMAP::getW() { return width; }
int BITMAP::getH() { return height; }

/// Modifica el valor del ancho/altura del bitmap
void BITMAP::setW(const int _w) { width = _w; }
void BITMAP::setH(const int _h) { height = _h; }

/// Colorea el bitmap
void BITMAP::set_bitmap_color(int r, int g, int b, GAME &main) {
  al_set_target_bitmap(bitmap);
  al_clear_to_color(al_map_rgb(r,g,b));
  al_set_target_bitmap(al_get_backbuffer(main.get_display()));
}

/// Dibuja el bitmap
void BITMAP::draw_bitmap(int flags) { al_draw_bitmap(bitmap, posX, posY, flags); }

// fixme: siempre devuelve true, en el caso de comparar la nave y los asteroides
bool BITMAP::check_colision(const BITMAP &obj)const {
  if (this->posX + this->width >= obj.posX || this->posX <= obj.posX + obj.width)
    if (this->posY >= obj.posY + obj.height || this->posY + this->height <= obj.posY)
      return true;
  return false;
}

ALLEGRO_BITMAP *BITMAP::get_bitmap() {
  return bitmap;
}




