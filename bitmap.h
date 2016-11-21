#ifndef BITMAP_H
#define BITMAP_H

#include "game.h"

class BITMAP {
  protected:
    ALLEGRO_BITMAP *bitmap;                         /// El bitmap en cuestión
    coor_t          x;                              /// Coordenada 'x'
    coor_t          y;                              /// Coordenada 'y'
    int             width;                          /// Ancho del bitmap
    int             height;                         /// Altura del bitmap
    int sourceX;
    int sourceY;
  public:
    BITMAP();
    BITMAP(const char* file);
    BITMAP(int sz, bool img = false);                               /// Constructor que solo recibe un elemento, donde la altura y el ancho son iguales
    BITMAP(int w, int h, bool img = false);                         /// Constructor que recibe la altura y el ancho
    BITMAP(coor_t nx, coor_t ny, bool img = false);                 /// Constructor que solo recibe coordenadas 'x' y 'y'
    BITMAP(coor_t nx, coor_t ny, int sz, bool img = false);         /// Constructor al igual que el primero, solo que este recibe coordenadas 'x' y 'y'
    BITMAP(coor_t nx, coor_t ny, int w, int h, bool img = false);   /// Constructor al igual que el segundo, solo que este recibe coordenadas 'x' y 'y'
    ~BITMAP();                                                      /// Destructor de BITMAP

    void setX(coor_t nx);                                            /// Modifica el valor de 'x'
    void setY(coor_t ny);                                            /// Modifica el valor de 'y'
    void moveX(coor_t dx);                                           /// Modifica el valor de 'x' aumentandolo/disminuyendo su valor
    void moveY(coor_t dy);                                           /// Modifica el valor de 'y' aumentandolo/disminuyendo su valor
    coor_t getX();                                                   /// Devuelve el valor de 'x'
    coor_t getY();                                                   /// Devuelve el valor de 'y'

    void set_width(int w);                                          /// Modifica el valor del ancho
    void set_height(int h);                                         /// Modifica el valor de la altura
    int get_width();                                                /// Devuelve el valor del ancho
    int get_height();                                               /// Devuelve el valor de la altura

    void set_bitmap_color(int r, int g, int b, GAME& main);         /// Colorea el bitmap, y luego vuelve a seleccionar el display
    void draw_bitmap(int flags);                                    /// Dibuja el bitmap
};

#endif // BITMAP_H
