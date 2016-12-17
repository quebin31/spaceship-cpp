//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_BITMAP_H
#define SPACESHIP2_BITMAP_H

#include "../tools_and_headers/spaceship_includes.h"

class Bitmap
{
  protected:
    AllegroBitmap  *bitmap;
    int             width;
    int             height;
    double          posX;
    double          posY;
    int             sourceX;
    int             sourceY;
    bool            destroyed;

  public:
    Bitmap(const char* file);
    virtual ~Bitmap();

    double getX() const;
    double getY() const;
    void setX(const double x);
    void setY(const double y);

    void moveX(const double dx);
    void moveY(const double dy);

    int getW() const;
    int getH() const;

    void setSourceX(const int sourceX);
    void setSourceY(const int sourceY);

    void setDestroyed(const bool destroyed);
    bool getDestroyed() const;

    virtual bool check_colision_with(Bitmap *some);         /// Not pure
    virtual void draw_bitmap(const int flags) = 0;          /// Pure
    virtual void reset_bitmap() = 0;                        /// Pure
};


#endif //SPACESHIP2_BITMAP_H
