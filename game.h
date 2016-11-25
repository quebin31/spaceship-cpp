#ifndef GAME_H
#define GAME_H

#include "allegro_includes.h"

class KEYBOARD;
class NAVE;
class ASTEROIDS;

typedef struct SCREEN {
  int width;      /// Ancho
  int height;     /// Alto
  float fps;      /// FPS (Frames Per Second)
} SCREEN;

SCREEN* create_screen(const int w, const int h, const float fps);
void destroy_screen(SCREEN*);

class GAME {
  private:
    SCREEN                *screen;                                                                /// SCREEN
    ALLEGRO_DISPLAY       *display;                                                               /// ALLEGRO_DISPLAY
    ALLEGRO_EVENT_QUEUE   *event_queue;                                                           /// ALLEGRO_EVENT_QUEUE
    ALLEGRO_TIMER         *timer;                                                                 /// ALLEGRO_TIMER
    ALLEGRO_FONT          *font1;                                                                 /// Fuente para el titulo principal
    ALLEGRO_FONT          *font2;                                                                 /// Fuente para las instrucciones
    ALLEGRO_SAMPLE        *move_sound;                                                            /// Audio al mover la nave
  public:
    bool                  done;                                                                   /// Done (bool), controla el while del programa
    bool                  game_over_or_pause;                                                     /// Game Over Or Pause (bool), controla el while del juego
    int                   vidas;                                                                  /// Vidas del juego

    GAME(SCREEN* nscreen);                                                                        /// Constructor de GAME en base a la pantalla
    ~GAME();                                                                                      /// Destructor

    void set_display_color(int r, int g, int b);                                                  /// Colorea el display
    void start_timer();                                                                           /// Empieza el timer (FPS)
    void wait_for_event(ALLEGRO_EVENT& ev);                                                       /// Esperar por un evento
    void manage_events(ALLEGRO_EVENT& ev, KEYBOARD& keyboard, NAVE& nave, ASTEROIDS& asters);     /// Administrador de eventos
    void show_menu();                                                                             /// Muestra el menu del juego
    void event_timer(KEYBOARD& keyboard, NAVE& nave, ASTEROIDS& asters);                          /// Administrador de evento timer
    void play_move_sound();                                                                       /// Reproduce move_sound
    bool event_queue_is_empty();                                                                  /// Verifica si la lista de eventos ya esta vacia

    ALLEGRO_DISPLAY*      get_display();                                                          /// Devuelve la direccion del display
    ALLEGRO_EVENT_QUEUE*  get_event_queue();                                                      /// Devuelve la direccion del event queue
    ALLEGRO_TIMER*        get_timer();                                                            /// Devuelve la direccion del timer
    SCREEN*               get_screen();                                                           /// Devuelve la direccion del screen template
    ALLEGRO_FONT*         get_font1();                                                            /// Devuelve la fuente del titulo principal
    ALLEGRO_FONT*         get_font2();                                                            /// Devuelve la fuente de los titulos para instrucciones
    int64_t               get_timer_count();                                                      /// Devuelve la cantidad de frames desde que se inicio el timer
};

#endif // GAME_H
