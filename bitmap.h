#ifndef BITMAP_H
#define BITMAP_H

#include "game.h"

class BITMAP {
protected:
  ALLEGRO_BITMAP *bitmap;                                     /// El bitmap en cuestión
  coor_t          posX;                                       /// Coordenada 'x'
  coor_t          posY;                                       /// Coordenada 'y'
  int             sourceX;                                    /// Coordenada 'x' de source
  int             sourceY;                                    /// Coordenada 'y' de source
public:
  BITMAP();                                                   /// Constructor default
  BITMAP(const char* file);                                   /// Constructor que recibe la imagen
  ~BITMAP();                                                  /// Destructor de BITMAP

  coor_t getX();                                              /// Devuelve el valor de 'x'
  coor_t getY();                                              /// Devuelve el valor 'y'
  void setX(coor_t nx);                                       /// Modifica el valor de 'x'
  void setY(coor_t ny);                                       /// Modifica el valor de 'y'
  void moveX(coor_t dx);                                      /// Modifica el valor de 'x' aumentandolo/disminuyendo su valor
  void moveY(coor_t dy);                                      /// Modifica el valor de 'y' aumentandolo/disminuyendo su valor

  int get_width();                                            /// Devuelve el valor del ancho
  int get_height();                                           /// Devuelve el valor de la altura

  void set_bitmap_color(int r, int g, int b, GAME& main);     /// Colorea el bitmap, y luego vuelve a seleccionar el display
  void draw_bitmap(int flags);                                /// Dibuja el bitmap
};

#endif // BITMAP_H
