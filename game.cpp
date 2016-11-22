#include "game.h"

using namespace std;

SCREEN *create_screen(const int w, const int h, const float fps) {
  SCREEN* temp = new SCREEN;

  temp->width = w;
  temp->height = h;
  temp->fps = fps;

  return temp;
}
void destroy_screen(SCREEN *screen) { delete screen; }

/// Constructor con SCREEN
GAME::GAME(SCREEN *nscreen) {
  cout << "GAME: Iniciando allegro" << endl;
  if (!al_init()) {
    al_show_native_message_box(display,"Error","Error","Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando allegro image" << endl;
  if (!al_init_image_addon()) {
    al_show_native_message_box(display,"Error","Error","Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando el teclado" << endl;
  if (!al_install_keyboard()) {
    al_show_native_message_box(display,"Error","Error","Failed to initialize keyboard!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando el display" << endl;
  display = al_create_display(nscreen->width, nscreen->height);
  if (!display) {
    al_show_native_message_box(display,"Error","Error","Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    al_destroy_timer(timer);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando la cola de eventos" << endl;
  event_queue = al_create_event_queue();
  if (!event_queue) {
    al_show_native_message_box(display,"Error","Error","Failed to initialize bitmap!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    al_destroy_display(display);
    al_destroy_timer(timer);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando el timer" << endl;
  timer = al_create_timer(1.0 / nscreen->fps);
  if (!timer) {
    al_show_native_message_box(display,"Error","Error","Failed to initialize timer!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  screen = nscreen;
  cout << "GAME: La pantalla actual es de " << screen->width << "x" << screen->height << endl;

  redraw = false;
  game_over = true;
  vidas = 3;

  cout << "GAME: Registrando todos los eventos" << endl;
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  set_display_color(0,0,0);
  cout << "GAME: All done." << endl;
}

/// Destructor
GAME::~GAME() {
  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
  destroy_screen(screen);
}

/// Cambia el color del display, y borra lo que tenga
void GAME::set_display_color(int r, int g, int b) {
  al_set_target_bitmap(al_get_backbuffer(display));
  al_clear_to_color(al_map_rgb(r,g,b));
}

/// Inicia el timer
void GAME::start_timer() { al_start_timer(timer); }

/// Verifica si la cola de eventos esta vacia
bool GAME::event_queue_is_empty() { return al_is_event_queue_empty(event_queue); }

/// Devuelve la direccion del display
ALLEGRO_DISPLAY *GAME::get_display() { return display; }

/// Devuelve la direccion del event_queue
ALLEGRO_EVENT_QUEUE *GAME::get_event_queue() { return event_queue; }

/// Devuelve la direccion del timer
ALLEGRO_TIMER *GAME::get_timer() { return timer; }

/// Devuelve la direccion del screen
SCREEN *GAME::get_screen() { return screen; }
