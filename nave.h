#ifndef NAVE_H
#define NAVE_H

#include "game.h"
#include "bitmap.h"

class NAVE: public BITMAP {
  private:
  public:
    NAVE(const char* file, const float nx, const float ny, const int w, const int h);
    NAVE(const char* file);
    void change_sourceX(int _sourceX);
    void change_sourceY(int _sourceY);
    void draw_nave(void);
    void refresh_sourceX(void);
    void refresh_sourceY(void);
    int get_sourceX(void);
    int get_sourceY(void);
    ALLEGRO_BITMAP* get_bitmap(void);
};

#endif // NAVE_H
