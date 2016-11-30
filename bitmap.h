#ifndef BITMAP_H
#define BITMAP_H

#include "allegro_includes.h"

class GAME;

class BITMAP {
protected:
  ALLEGRO_BITMAP *bitmap;                                     /// El bitmap en cuestión
  int             width;                                      /// Ancho
  int             height;                                     /// Altura
  coor_t          posX;                                       /// Coordenada 'x'
  coor_t          posY;                                       /// Coordenada 'y'
  int             sourceX;                                    /// Coordenada 'x' de source
  int             sourceY;                                    /// Coordenada 'y' de source
public:
  bool destroyed;
  BITMAP();                                                   /// Constructor default
  BITMAP(const char* file);                                   /// Constructor que recibe la imagen
  ~BITMAP();                                                  /// Destructor de BITMAP

  coor_t getX();                                              /// Devuelve el valor de 'x'
  coor_t getY();                                              /// Devuelve el valor 'y'
  void setX(coor_t nx);                                       /// Modifica el valor de 'x'
  void setY(coor_t ny);                                       /// Modifica el valor de 'y'
  void moveX(coor_t dx);                                      /// Modifica el valor de 'x' aumentandolo/disminuyendo su valor
  void moveY(coor_t dy);                                      /// Modifica el valor de 'y' aumentandolo/disminuyendo su valor

  int getW();                                                 /// Devuelve el ancho del bitmap
  int getH();                                                 /// Devuelve la altura del bitmap
  void setW(const int _w);                                    /// Cambia el valor del ancho
  void setH(const int _h);                                    /// Cambia el valor de la altura

  void set_bitmap_color(int r, int g, int b, GAME& main);     /// Colorea el bitmap, y luego vuelve a seleccionar el display
  void draw_bitmap(int flags);                                /// Dibuja el bitmap
  bool check_colision(const BITMAP& obj) const;               /// Chequea si es que hay una colision o no
  ALLEGRO_BITMAP* get_bitmap();                               /// Devuelve la direccion del bitmap
};

#endif // BITMAP_H
