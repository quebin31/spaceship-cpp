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
    bool destroyed;                                             /// Bool para saber si un bitmap, ha sido destruido

    BITMAP();                                                   /// Constructor default
    BITMAP(const char* file);                                   /// Constructor que recibe una imagen
    ~BITMAP();                                                  /// Destructor de BITMAP

    coor_t getX();                                              /// Devuelve el valor de 'x'
    coor_t getY();                                              /// Devuelve el valor 'y'
    void setX(coor_t nx);                                       /// Modifica el valor de 'x'
    void setY(coor_t ny);                                       /// Modifica el valor de 'y'
    void moveX(coor_t dx);                                      /// Modifica el valor de 'x' aumentandolo/disminuyendo su valor
    void moveY(coor_t dy);                                      /// Modifica el valor de 'y' aumentandolo/disminuyendo su valor

    void setW(const int _w);                                    /// Cambia el valor del ancho
    void setH(const int _h);                                    /// Cambia el valor de la altura
    int getW();                                                 /// Devuelve el ancho del bitmap
    int getH();                                                 /// Devuelve la altura del bitmap

    void draw_bitmap(int flags);                                /// Dibuja el bitmap
    bool check_colision(const BITMAP& obj) const;               /// Chequea si es que hay una colision o no
    bool check_colision(const BITMAP& obj);                     /// Chequea si es que hay una colision o no
    bool check_colision(const BITMAP* obj) const;               /// Chequea si es que hay una colision o no
    bool check_colision(const BITMAP* obj);                     /// Chequea si es que hay una colision o no
};

#endif // BITMAP_H
