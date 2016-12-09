//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_BITMAP_H
#define SPACESHIP2_BITMAP_H

#include "../tools_and_headers/spaceship_includes.h"

class BITMAP
{
  protected:
    ALLEGRO_BITMAP *bitmap;
    int             width;
    int             height;
    double           posX;
    double           posY;
    int             sourceX;
    int             sourceY;
    bool            destroyed;

  public:
    BITMAP(const char* file);
    virtual ~BITMAP();

    double getX() const;
    double getY() const;
    void setX(const double x);
    void setY(const double y);

    void moveX(const float dx);
    void moveY(const float dy);

    void setW(const int width);
    void setH(const int height);
    int getW() const;
    int getH() const;

    void setSourceX(const int sourceX);
    void setSourceY(const int sourceY);

    void setDestroyed(const bool destroyed);
    bool getDestroyed() const;

    virtual bool check_colision_with(BITMAP *some);         /// Not pure
    virtual void draw_bitmap(const int flags) = 0;          /// Pure
    virtual void reset_bitmap() = 0;                        /// Pure
};


#endif //SPACESHIP2_BITMAP_H
