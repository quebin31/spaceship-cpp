//
// Created by kevin on 7/12/16.
//


#include "main_game.h"
#include "keyboard.h"


#pragma clang diagnostic push
#pragma ide diagnostic ignored "CannotResolve"
MAIN_GAME::MAIN_GAME()
{
  std::cout << "GAME_ENGINE: Iniciando Allegro" << std::endl;
  if (!al_init())
  {
    al_show_native_message_box(display,"Ups!","Vaya...","Algo salió mal al iniciar Allegro",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    std::cout << "GAME_ENGINE: Allegro falló al iniciarse, puede deberse a que no tiene allegro instalado" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "GAME_ENGINE: Iniciando Allegro Image" << std::endl;
  if (!al_init_image_addon())
  {
    al_show_native_message_box(display,"Ups!","Vaya...","Algo salió mal al iniciar Allegro Image",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    std::cout << "GAME_ENGINE: Allegro Image falló al iniciarse, puede deberse a que no tiene allegro instalado" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "GAME_ENGINE: Iniciando Allegro Font" << std::endl;
  if (!al_init_font_addon())
  {
    al_show_native_message_box(display,"Ups!","Vaya...","Algo salió mal al iniciar Allegro Font",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    std::cout << "GAME_ENGINE: Allegro Font falló al iniciarse, puede deberse a que no tiene allegro instalado" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "GAME_ENGINE: Iniciando Allegro TTF" << std::endl;
  if (!al_init_ttf_addon())
  {
    al_show_native_message_box(display,"Ups!","Vaya...","Algo salió mal al iniciar Allegro TTF",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    std::cout << "GAME_ENGINE: Allegro TTF falló al iniciarse, puede deberse a que no tiene allegro instalado" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "GAME_ENGINE: Iniciando Allegro Acodec" << std::endl;
  if (!al_init_acodec_addon())
  {
    al_show_native_message_box(display,"Ups!","Vaya...","Algo salió mal al iniciar Allegro Acodec",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    std::cout << "GAME_ENGINE: Allegro Acodec falló al iniciarse, puede deberse a que no tiene allegro instalado" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "GAME_ENGINE: Iniciando Allegro Audio" << std::endl;
  if (!al_install_audio())
  {
    al_show_native_message_box(display,"Ups!","Vaya...","Algo salió mal al iniciar Allegro Audio",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    std::cout << "GAME_ENGINE: Allegro Audio falló al iniciarse, puede deberse a que no tiene allegro instalado" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "GAME_ENGINE: Instanciando el teclado" << std::endl;
  if (!al_install_keyboard())
  {
    al_show_native_message_box(display,"Ups!","Vaya...","Algo salió mal al iniciar Allegro Keyboard",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    std::cout << "GAME_ENGINE: Allegro Keyboard falló al iniciarse, puede deberse a que no tiene allegro instalado" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "GAME_ENGINE: Configurando los valores para la pantalla " << std::endl;

  std::cout << "GAME_ENGINE: Creando el display" << std::endl;
  display = al_create_display(640,480);
  if (!display)
  {
    al_show_native_message_box(display,"Ups!","Vaya...","Algo salió mal mientras creaba el display",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    std::cout << "GAME_ENGINE: Informar de este error" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "GAME_ENGINE: Display creado correctamente @(" << display << ")" << std::endl;

  std::cout << "GAME_ENGINE: Creando la cola de eventos" << std::endl;
  event_queue = al_create_event_queue();
  if (!event_queue)
  {
    al_show_native_message_box(display,"Ups!","Vaya...","Algo salió mal mientras creaba la cola de eventos",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    std::cout << "GAME_ENGINE: Informar de este error" << std::endl;
    al_destroy_display(display);
    exit(EXIT_FAILURE);
  }
  std::cout << "GAME_ENGINE: Cola de eventos creada correctamente @(" << event_queue << ")" << std::endl;

  std::cout << "GAME_ENGINE: Creando el timer" << std::endl;
  timer = al_create_timer(1.0/60);
  if (!timer)
  {
    al_show_native_message_box(display,"Ups!","Vaya...","Algo salió mal mientras creaba el timer",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    std::cout << "GAME_ENGINE: Informar de este error" << std::endl;
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    exit(EXIT_FAILURE);
  }
  std::cout << "GAME_ENGINE: Timer creado correctamente @(" << timer << ")" << std::endl;

  objects = new OBJS_FACADE;
  done_main = false;
  gameover_or_pause = false;

  std::cout << "GAME_ENGINE: Registrando todos los eventos" << std::endl;
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  al_set_window_title(display, "Asteroid Game");
  al_set_window_position(display,350,180);
  set_display_color(26,26,26);
  std::cout << "GAME_ENGINE: Motor de juego correctamente inicializado (unica instancia)" << std::endl;
}
#pragma clang diagnostic pop

MAIN_GAME::~MAIN_GAME()
{
  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
  delete objects;
}

void MAIN_GAME::set_display_color(unsigned char r, unsigned char g, unsigned char b)
{
  al_set_target_bitmap(al_get_backbuffer(display));
  al_clear_to_color(al_map_rgb(r,g,b));
}

bool MAIN_GAME::get_main_activity_state() { return done_main; }

bool MAIN_GAME::get_game_activity_state() { return gameover_or_pause; }

void MAIN_GAME::set_main_activity_state(const bool state) { done_main = state; }

void MAIN_GAME::set_game_activity_state(const bool state) { gameover_or_pause = state; }

void MAIN_GAME::show_menu() { objects->show_menu(); }

void MAIN_GAME::wait_for_event(ALLEGRO_EVENT &event) { al_wait_for_event(event_queue, &event); }

void MAIN_GAME::start_timer()
{
  if (get_timer_count() == 0)
    al_start_timer(timer);

  gameover_or_pause = false;
  (*KEYBOARD::get()).set_state_to(ESC, false);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "CannotResolve"
void MAIN_GAME::manage_event(ALLEGRO_EVENT &event)
{
  if (event.type == ALLEGRO_EVENT_TIMER)
    event_timer();
  else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    KEYBOARD::get()->key_dw_event(event);
  else if (event.type == ALLEGRO_EVENT_KEY_UP)
    KEYBOARD::get()->key_up_event(event);
  else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    exit(EXIT_SUCCESS);
}

#pragma clang diagnostic pop

void MAIN_GAME::event_timer()
{
  if ((*KEYBOARD::get())[ESC])
  {
    gameover_or_pause = true;
    return;
  }

  if (objects->no_hearts())
  {
    gameover_or_pause = true;
    return;
  }

  set_display_color(26,26,26);
  objects->check_nave_with_asteroids();
  objects->check_bullets_with_asteroids();
  objects->draw_objects();
  objects->draw_information();
  objects->check_nave_with_powerups();

  al_flip_display();
}

int64_t MAIN_GAME::get_timer_count() { return al_get_timer_count(timer); }

MAIN_GAME *MAIN_GAME::get()
{
  if (!main_game_instance)
    main_game_instance = new MAIN_GAME;
  return main_game_instance;
}

MAIN_GAME *MAIN_GAME::main_game_instance = 0;

int MAIN_GAME::getW() const { return 640; }

int MAIN_GAME::getH() const { return 480; }

void MAIN_GAME::del()
{ delete main_game_instance; }
