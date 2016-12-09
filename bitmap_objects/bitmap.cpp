//
// Created by kevin on 7/12/16.
//

#include "bitmap.h"

BITMAP::BITMAP(const char* file)
{
  bitmap = al_load_bitmap(file);
  posX = 0;
  posY = 0;
  sourceX = 0;
  sourceY = 0;
  destroyed = false;
}

BITMAP::~BITMAP() { if (bitmap != nullptr) al_destroy_bitmap(bitmap); }

double BITMAP::getX() const { return posX; }

double BITMAP::getY() const { return posY; }

void BITMAP::setX(const double x) { posX = x; }

void BITMAP::setY(const double y) { posY = y; }

void BITMAP::moveX(const float dx) { posX += dx; }

void BITMAP::moveY(const float dy) { posY += dy; }

void BITMAP::setW(const int width) { this->width = width; }

void BITMAP::setH(const int height) { this->height = height; }

int BITMAP::getW() const { return width; }

int BITMAP::getH() const { return height; }

void BITMAP::setSourceX(const int sourceX) { this->sourceX = sourceX; }

void BITMAP::setSourceY(const int sourceY) { this->sourceY = sourceY; }

void BITMAP::setDestroyed(const bool destroyed) { this->destroyed = destroyed; }

bool BITMAP::getDestroyed() const { return destroyed; }

bool BITMAP::check_colision_with(BITMAP* some)
{
  if (this->posX + this->width >= some->posX && this->posX <= some->posX + some->width)
    if (this->posY + this->height >= some->posY && this->posY <= some->posY + some->height)
      return true;
  return false;
}




