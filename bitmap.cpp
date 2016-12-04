#include "bitmap.h"
#include "game.h"

/* Constructor default
 * bitmap es null ya que no se cargo ninguna imagen, o creo algun bitmap
 * posX, posY  representan las coordenadas x e y, dentro del juego
 * sourceX, sourceY representan las coordenadas x e y, que se usaran para cargar imagenes por regiones */
BITMAP::BITMAP(): bitmap(nullptr), posX(0), posY(0), sourceX(0), sourceY(0) {}

/* Constructor con imagen
 * bitmap, ahora carga una imagen
 * posX, posY, sourceX, sourceY seran 0 hasta que se modifiquen sus valores */
BITMAP::BITMAP(const char* file)
{
  bitmap = al_load_bitmap(file);
  posX = 0;
  posY = 0;
  sourceX = 0;
  sourceY = 0;
  destroyed = false;
}

/* Destructor de la clase bitmap, llama una funcion del add-on Allegro
 * para eliminar el espacio dinamico que se creo para el bitmap */
BITMAP::~BITMAP() { al_destroy_bitmap(bitmap); }


/* Metodos para el manejo de las coordenadas dentro del juego
 * setX, setY: Configura los valores de x o y
 * moveX, moveY: Aumenta o disminuyes los valores de x o y
 * getX, getY: Devuelve los valores de x o y */
void BITMAP::setX(coor_t nx) { posX = nx; }
void BITMAP::setY(coor_t ny) { posY = ny; }
void BITMAP::moveX(float dx) { posX += dx; }
void BITMAP::moveY(float dy) { posY += dy; }
coor_t BITMAP::getX() { return posX; }
coor_t BITMAP::getY() { return posY; }


/* Metodos para el manejor del ancho y altura del bitmap
 * setW, setH: Configura los valores del ancho o altura
 * getW, getH: Devuelve los valores del ancho o altura */
void BITMAP::setW(const int _w) { width = _w; }
void BITMAP::setH(const int _h) { height = _h; }
int BITMAP::getW() { return width; }
int BITMAP::getH() { return height; }


/* Metodo para dibujar el bitmap con una funcion del add-on Allegro
 * que recibe como argumentos el bitmap a dibujar
 * las coordenadas x e y donde sera dibujado
 * y si es que sera dibujado a modo de espejo horizontal o vertical (flags) */
void BITMAP::draw_bitmap(int flags) { al_draw_bitmap(bitmap, posX, posY, flags); }


/* Metodo para detectar la colision entre bitmaps
 * true: si ambos objetos chocan entre si
 * false: si es que no chocaron */
bool BITMAP::check_colision(const BITMAP &obj) const
{
  if (this->posX + this->width >= obj.posX && this->posX <= obj.posX + obj.width)
    if (this->posY + this->height >= obj.posY && this->posY <= obj.posY + obj.height)
      return true;
  return false;
}
bool BITMAP::check_colision(const BITMAP &obj)
{
  if (this->posX + this->width >= obj.posX && this->posX <= obj.posX + obj.width)
    if (this->posY + this->height >= obj.posY && this->posY <= obj.posY + obj.height)
      return true;
  return false;
}
bool BITMAP::check_colision(const BITMAP *obj) const
{
  if (this->posX + this->width >= obj->posX && this->posX <= obj->posX + obj->width)
    if (this->posY + this->height >= obj->posY && this->posY <= obj->posY + obj->height)
      return true;
  return false;
}
bool BITMAP::check_colision(const BITMAP *obj)
{
  if (this->posX + this->width >= obj->posX && this->posX <= obj->posX + obj->width)
    if (this->posY + this->height >= obj->posY && this->posY <= obj->posY + obj->height)
      return true;
  return false;
}