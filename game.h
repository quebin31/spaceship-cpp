#ifndef GAME_H
#define GAME_H

#include "types.h"
#include <cstdio>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

typedef struct SCREEN {
  int width;      /// Ancho
  int height;     /// Alto
  float fps;      /// FPS (Frames Per Second)
} SCREEN;

SCREEN* create_screen(const int w, const int h, const float fps);
void destroy_screen(SCREEN*);

class GAME {
  private:
    ALLEGRO_DISPLAY       *display;               /// ALLEGRO_DISPLAY
    ALLEGRO_EVENT_QUEUE   *event_queue;           /// ALLEGRO_EVENT_QUEUE
    ALLEGRO_TIMER         *timer;                 /// ALLEGRO_TIMER
    SCREEN                *screen;                /// SCREEN
  public:
    ALLEGRO_FONT          *font1;                 /// FONT FOR MAIN TITLE
    ALLEGRO_FONT          *font2;                 /// FONT FOR INSTRUCCIONS
    bool                  redraw;                 /// Redibuja (bool), controla si se esta listo para redibujar
    bool                  game_over;              /// Game Over (bool), controla el while principal del jueg
    int                   vidas;                  /// Vidas del juego

    GAME(SCREEN* nscreen);                        /// Constructor de GAME en base a la pantalla
    ~GAME();                                      /// Destructor

    void set_display_color(int r, int g, int b);  /// Colorea el display
    void start_timer();                           /// Empieza el timer (FPS)
    bool event_queue_is_empty();                  /// Verifica si la lista de eventos ya esta vacia

    ALLEGRO_DISPLAY*      get_display();          /// Devuelve la direccion del display
    ALLEGRO_EVENT_QUEUE*  get_event_queue();      /// Devuelve la direccion del event queue
    ALLEGRO_TIMER*        get_timer();            /// Devuelve la direccion del timer
    SCREEN*               get_screen();           /// Devuelve la direccion del screen template
    ALLEGRO_FONT*         get_font1();            /// Devuelve la fuente del titulo principal
    ALLEGRO_FONT*         get_font2();            /// Devuelve la fuente de los titulos para instrucciones
    int64_t               get_timer_count();
};

#endif // GAME_H
