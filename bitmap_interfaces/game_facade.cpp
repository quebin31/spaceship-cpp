//
// Created by kevin on 8/12/16.
//

#include "game_facade.h"
#include "../game_interfaces/keyboard.h"
#include "../game_interfaces/main_game.h"

OBJS_FACADE::OBJS_FACADE(): nave(new NAVE),
                            nave_gun(nave->getGun()),
                            asteroids(new ASTEROIDS),
                            hearts(new HEARTS),
                            frame(new IMAGE("marco.png",600,440)),
                            score("0"),
                            title_font(al_load_font("PressStart2P.ttf",30,0)),
                            options_font(al_load_font("Joystick.otf",20,0)),
                            score_font(al_load_font("PressStart2P.ttf", 12,0))
{
  nave->setX((const float) (frame->getW() / 2.0 - nave->getW() / 2.0));
  nave->setY((const float) (frame->getH() / 2.0 - nave->getH() / 2.0 + 200));
}

OBJS_FACADE::~OBJS_FACADE()
{
  delete nave;
  delete asteroids;
  delete hearts;
  delete frame;
  al_destroy_font(title_font);
  al_destroy_font(options_font);
  al_destroy_font(score_font);
}

void OBJS_FACADE::show_menu()
{
  int64_t frames_when = MAIN_GAME::get()->get_timer_count();
  std::string title;
  std::string options;
  if (frames_when == 0)
  {
    title = "ASTEROID GAME";
    options = "INICIAR (PRESIONA ENTER)";
  }
  else if (hearts->empty())
  {
    title = "GAME OVER";
    options = "REINICIAR (PRESIONA ENTER)";
  }
  else
  {
    title = "PAUSE";
    options = "RESUMIR (PRESIONA ENTER)";
  }
  MAIN_GAME::get()->set_display_color(26,26,26);
  al_draw_text(title_font, al_map_rgb(200,10,50), MAIN_GAME::get()->getW()/2, MAIN_GAME::get()->getH()/2, ALLEGRO_ALIGN_CENTRE, title.c_str());
  al_draw_text(options_font, al_map_rgb(20,30,60), MAIN_GAME::get()->getW()/2, MAIN_GAME::get()->getH()/2 + 60, ALLEGRO_ALIGN_CENTRE, options.c_str());
  al_draw_text(options_font, al_map_rgb(20,30,60), MAIN_GAME::get()->getW()/2, MAIN_GAME::get()->getH()/2 + 120, ALLEGRO_ALIGN_CENTRE,"SALIR (PRESIONA ESCAPE)");
  al_flip_display();
}

void OBJS_FACADE::check_bullets_with_asteroids()
{
  for (std::size_t i = 0; i < nave_gun->size(); i++)
  {

    if ((*nave_gun)[i]->getY() <= 0)
    {
      (*nave_gun)[i]->setDestroyed(true);
      nave_gun->put_on_store(i);
    }
    if ((*nave_gun)[i]->getDestroyed())
      nave_gun->put_on_store(i);

    for (std::size_t j = 0; j < asteroids->size(); j++)
    {
      if ((*nave_gun)[i]->check_colision_with((*asteroids)[j]))
        nave_gun->inc_score();
    }
  }
}

void OBJS_FACADE::check_nave_with_asteroids()
{
  if (nave->getDestroyed())
  {
    if (nave->getWhenDestroyed() + 90 == MAIN_GAME::get()->get_timer_count())
    {
      std::cout << "Haciendo vulnerable\n";
      nave->make_vulnerable();
    }
  }
  else
  {
    for (std::size_t i = 0; i < asteroids->size(); i++)
    {
      if (asteroids->at(i)->getY() >= 480)
      {
        (*asteroids)[i]->setDestroyed(true);
        asteroids->put_on_store(i);
      }

      if ((*asteroids)[i]->getDestroyed())
        asteroids->put_on_store(i);

      if ((*asteroids)[i]->check_colision_with(nave))
      {
        nave->make_invulnerable(MAIN_GAME::get()->get_timer_count());
        hearts->lost_heart();
        std::cout << "Haciendo invulnerable\n";
        return;
      }
    }
  }
}

void OBJS_FACADE::receive_score() { score = int_to_string(nave_gun->getScore()); }

void OBJS_FACADE::update_objects()
{
  if ((*KEYBOARD::get())[UP] and nave->getY() >= 4.5 + 76)
  {
    nave->moveY(-4.5);
    nave->setSourceX(NAVE_UP);
  }
  else if ((*KEYBOARD::get())[DOWN] and nave->getY() <= frame->getH() - nave->getH() - 4.5)
  {
    nave->moveY(4.5);
    nave->setSourceX(NAVE_UP);
  }
  else if ((*KEYBOARD::get())[LEFT] && nave->getX() >= 4.5 + 40)
  {
    nave->moveX(-4.5);
    nave->setSourceX(NAVE_LEFT);
  }
  else if ((*KEYBOARD::get())[RIGHT] && nave->getX() <= frame->getW() - nave->getW() - 4.5 )
  {
    nave->moveX(4.5);
    nave->setSourceX(NAVE_RIGHT);
  }
  else
  {
    nave->setSourceX(NAVE_UP);
  }

  if ((*KEYBOARD::get())[CHAR_A] && MAIN_GAME::get()->get_timer_count()%18 == 0)
  {
    nave->shoot_gun();
  }

  nave->draw_bitmap(0);
  nave->update_bullets();
  asteroids->update_asteroids(MAIN_GAME::get()->get_timer_count());
}

void OBJS_FACADE::draw_objects() {
  update_objects();
}

void OBJS_FACADE::draw_information()
{
  receive_score();
  frame->draw_bitmap(0);
  al_draw_text(score_font,al_map_rgb(110,110,100),400,45,0,"SCORE:");
  al_draw_text(score_font,al_map_rgb(110,110,100),500,45,0,score.c_str());
  hearts->draw_hearts();
}
