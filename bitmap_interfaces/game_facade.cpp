//
// Created by kevin on 8/12/16.
//

#include "game_facade.h"
#include "../game_interfaces/keyboard.h"
#include "../game_interfaces/main_game.h"

<<<<<<< HEAD
ObjectsFacade::ObjectsFacade(): nave(new Nave),
                            nave_gun(nave->getGun()),
                            hearts(new Hearts),
                            frame(new Image("marco.png",600,440)),
=======
OBJS_FACADE::OBJS_FACADE(): //nave(new NAVE),
                            nave_gun(NAVE::instance()->getGun()),
                            asteroids(new ASTEROIDS),
                            hearts(new HEARTS),
                            frame(new IMAGE("marco.png",600,440)),
>>>>>>> 27e201519406282de8a3c267430e611e08b76ca1
                            score("0"),
                            title_font(al_load_font("PressStart2P.ttf",30,0)),
                            options_font(al_load_font("Joystick.otf",20,0)),
                            score_font(al_load_font("PressStart2P.ttf", 12,0))
{
<<<<<<< HEAD
  AsteroidInterface::createAsteroidObjectPool();
  nave->setX((const float) (frame->getW() / 2.0 - nave->getW() / 2.0));
  nave->setY((const float) (frame->getH() / 2.0 - nave->getH() / 2.0 + 200));
=======
  NAVE::instance()->setX((const float) (frame->getW() / 2.0 - NAVE::instance()->getW() / 2.0));
  NAVE::instance()->setY((const float) (frame->getH() / 2.0 - NAVE::instance()->getH() / 2.0 + 200));
>>>>>>> 27e201519406282de8a3c267430e611e08b76ca1
}

ObjectsFacade::~ObjectsFacade()
{
<<<<<<< HEAD
  delete nave;
  AsteroidInterface::deleteAsteroidObjectPool();
=======
  //delete nave;
  delete asteroids;
>>>>>>> 27e201519406282de8a3c267430e611e08b76ca1
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
  if (NAVE::instance()->getDestroyed())
  {
<<<<<<< HEAD
    if (nave->getWhenDestroyed() + 90 == MainGame::get()->get_timer_count())
    {
      std::cout << "Nave: Haciendo vulnerable\n";
      nave->make_vulnerable();
=======
    if (NAVE::instance()->getWhenDestroyed() + 90 == MAIN_GAME::get()->get_timer_count())
    {
      std::cout << "NAVE: Haciendo vulnerable\n";
      NAVE::instance()->make_vulnerable();
>>>>>>> 27e201519406282de8a3c267430e611e08b76ca1
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


<<<<<<< HEAD
      if ((*aster_itr)->check_colision_with(nave))
      {
        nave->make_invulnerable(MainGame::get()->get_timer_count());
=======
      if ((*asteroids)[i]->check_colision_with(NAVE::instance()))
      {
        NAVE::instance()->make_invulnerable(MAIN_GAME::get()->get_timer_count());
>>>>>>> 27e201519406282de8a3c267430e611e08b76ca1
        hearts->lost_heart();

        std::cout << "Nave: Haciendo invulnerable\n";
        return;
      }
    }
  }
}

void ObjectsFacade::check_nave_with_powerups()
{
  if (POWER_UP::instance()->pun == false){
    if (POWER_UP::instance()->check_colision_with(NAVE::instance()) == true){
      std::cout << "PUN!" << MAIN_GAME::get()->get_timer_count() << std::endl;
      POWER_UP::instance()->set_destroyed_at(MAIN_GAME::get()->get_timer_count());
      POWER_UP::instance()->pun = true;
    }
  }
  if (MAIN_GAME::get()->get_timer_count() == POWER_UP::instance()->get_destroyed_at()+800){
    POWER_UP::instance()->reset_bitmap();
    std::cout << MAIN_GAME::get()->get_timer_count() << std::endl;
    POWER_UP::instance()->pun = false;
  }
}

void ObjectsFacade::receive_score() { score = int_to_string(nave_gun->getScore()); }

void ObjectsFacade::update_objects()
{
  if ((*KEYBOARD::get())[UP] && NAVE::instance()->getY() >= 4.3 + 76)
  {
    NAVE::instance()->moveY(-4.3);
    NAVE::instance()->setSourceX(NAVE_UP);
  }
  else if ((*KEYBOARD::get())[DOWN] && NAVE::instance()->getY() <= frame->getH() - NAVE::instance()->getH() - 4.3)
  {
    NAVE::instance()->moveY(4.3);
    NAVE::instance()->setSourceX(NAVE_UP);
  }
  else if ((*KEYBOARD::get())[LEFT] && NAVE::instance()->getX() >= 4.3 + 40)
  {
    NAVE::instance()->moveX(-4.3);
    NAVE::instance()->setSourceX(NAVE_LEFT);
  }
  else if ((*KEYBOARD::get())[RIGHT] && NAVE::instance()->getX() <= frame->getW() - NAVE::instance()->getW() - 4.3 )
  {
    NAVE::instance()->moveX(4.3);
    NAVE::instance()->setSourceX(NAVE_RIGHT);
  }
  else
  {
    NAVE::instance()->setSourceX(NAVE_UP);
  }

  if ((*KEYBOARD::get())[CHAR_A] && MainGame::get()->get_timer_count()%13 == 0)
  {
    NAVE::instance()->shoot_gun();
  }

<<<<<<< HEAD
  nave->draw_bitmap(0);
  nave->update_bullets();
  AsteroidInterface::updateAsteroids(MainGame::get()->get_timer_count());
=======
  NAVE::instance()->draw_bitmap(0);
  NAVE::instance()->update_bullets();
  POWER_UP::instance()->draw_bitmap(0);
  asteroids->update_asteroids(MAIN_GAME::get()->get_timer_count());
>>>>>>> 27e201519406282de8a3c267430e611e08b76ca1
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
