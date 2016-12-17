//
// Created by kevin on 8/12/16.
//

#include "game_facade.h"
#include "../game_interfaces/keyboard.h"
#include "../game_interfaces/main_game.h"

ObjectsFacade::ObjectsFacade(): nave(new Nave),
                            nave_gun(nave->getGun()),
                            hearts(new Hearts),
                            frame(new Image("marco.png",600,440)),
                            score("0"),
                            title_font(al_load_font("PressStart2P.ttf",30,0)),
                            options_font(al_load_font("Joystick.otf",20,0)),
                            score_font(al_load_font("PressStart2P.ttf", 12,0))
{
  AsteroidInterface::createAsteroidObjectPool();
  nave->setX((const float) (frame->getW() / 2.0 - nave->getW() / 2.0));
  nave->setY((const float) (frame->getH() / 2.0 - nave->getH() / 2.0 + 200));
}

ObjectsFacade::~ObjectsFacade()
{
  delete nave;
  AsteroidInterface::deleteAsteroidObjectPool();
  delete hearts;
  delete frame;
  al_destroy_font(title_font);
  al_destroy_font(options_font);
  al_destroy_font(score_font);
}

void ObjectsFacade::show_menu()
{
  int64_t frames_when = MainGame::get()->get_timer_count();
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
  MainGame::get()->set_display_color(26,26,26);
  al_draw_text(title_font, al_map_rgb(200,10,50), MainGame::get()->getW()/2, MainGame::get()->getH()/2, ALLEGRO_ALIGN_CENTRE, title.c_str());
  al_draw_text(options_font, al_map_rgb(20,30,60), MainGame::get()->getW()/2, MainGame::get()->getH()/2 + 60, ALLEGRO_ALIGN_CENTRE, options.c_str());
  al_draw_text(options_font, al_map_rgb(20,30,60), MainGame::get()->getW()/2, MainGame::get()->getH()/2 + 120, ALLEGRO_ALIGN_CENTRE,"SALIR (PRESIONA ESCAPE)");
  al_flip_display();
}

void ObjectsFacade::check_bullets_with_asteroids()
{
  for (std::size_t i = 0; i < nave_gun->size(); i++)
  {

    if ((*nave_gun)[i]->getY() <= 0)
    {
      (*nave_gun)[i]->setDestroyed(true);
      nave_gun->erase(i);
    }
    if ((*nave_gun)[i]->getDestroyed())
    {
      nave_gun->erase(i);
    }
    for (AsteroidObjectPool::Iterator aster_itr = AsteroidInterface::getBegin(), aster_end = AsteroidInterface::getEnd(); aster_itr != aster_end + 1; aster_itr++)
    {

//      if ((*aster_itr)->getDestroyed())
//      {
//        AsteroidInterface::eraseAsteroid(aster_itr);
//        aster_end = AsteroidInterface::getEnd();
//        continue;
//      }

      if ((*nave_gun)[i]->check_colision_with(*aster_itr))
      {
        nave_gun->incScore();
        AsteroidInterface::eraseAsteroid(aster_itr);
        aster_end = AsteroidInterface::getEnd();
        continue;
      }
    }
  }
  if (MainGame::get()->get_timer_count()%150 == 0)
    nave_gun->decScore();
}

void ObjectsFacade::check_nave_with_asteroids()
{
  if (nave->getDestroyed())
  {
    if (nave->getWhenDestroyed() + 90 == MainGame::get()->get_timer_count())
    {
      std::cout << "Nave: Haciendo vulnerable\n";
      nave->make_vulnerable();
    }
  }
  else
  {
    for (AsteroidObjectPool::Iterator aster_itr = AsteroidInterface::getBegin(); aster_itr != AsteroidInterface::getEnd(); aster_itr++)
    {

      if ((*aster_itr)->getDestroyed())
      {
        AsteroidInterface::eraseAsteroid(aster_itr);
        break;
      }
      if ((*aster_itr)->getY() >= 480)
        (*aster_itr)->setDestroyed(true);


      if ((*aster_itr)->check_colision_with(nave))
      {
        nave->make_invulnerable(MainGame::get()->get_timer_count());
        hearts->lost_heart();

        std::cout << "Nave: Haciendo invulnerable\n";
        return;
      }
    }
  }
}

void ObjectsFacade::check_nave_with_powerups()
{

}

void ObjectsFacade::receive_score() { score = int_to_string(nave_gun->getScore()); }

void ObjectsFacade::update_objects()
{
  if ((*KEYBOARD::get())[UP] && nave->getY() >= 4.3 + 76)
  {
    nave->moveY(-4.3);
    nave->setSourceX(NAVE_UP);
  }
  else if ((*KEYBOARD::get())[DOWN] && nave->getY() <= frame->getH() - nave->getH() - 4.3)
  {
    nave->moveY(4.3);
    nave->setSourceX(NAVE_UP);
  }
  else if ((*KEYBOARD::get())[LEFT] && nave->getX() >= 4.3 + 40)
  {
    nave->moveX(-4.3);
    nave->setSourceX(NAVE_LEFT);
  }
  else if ((*KEYBOARD::get())[RIGHT] && nave->getX() <= frame->getW() - nave->getW() - 4.3 )
  {
    nave->moveX(4.3);
    nave->setSourceX(NAVE_RIGHT);
  }
  else
  {
    nave->setSourceX(NAVE_UP);
  }

  if ((*KEYBOARD::get())[CHAR_A] && MainGame::get()->get_timer_count()%13 == 0)
  {
    nave->shoot_gun();
  }

  nave->draw_bitmap(0);
  nave->update_bullets();
  AsteroidInterface::updateAsteroids(MainGame::get()->get_timer_count());
}

void ObjectsFacade::draw_objects()
{ update_objects(); }

void ObjectsFacade::draw_information()
{
  receive_score();
  frame->draw_bitmap(0);
  al_draw_text(score_font,al_map_rgb(110,110,100),400,45,0,"SCORE:");
  al_draw_text(score_font,al_map_rgb(110,110,100),500,45,0,score.c_str());
  hearts->draw_hearts();
}

bool ObjectsFacade::no_hearts()
{ return hearts->empty(); }
