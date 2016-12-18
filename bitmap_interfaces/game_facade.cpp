//
// Created by kevin on 8/12/16.
//

#include "game_facade.h"
#include "../game_interfaces/keyboard.h"
#include "../game_interfaces/main_game.h"

ObjectsInterface::ObjectsInterface():
                            hearts(new Hearts),
                            frame(new Image("marco.png",600,440)),
                            score("0"),
                            title_font(al_load_font("PressStart2P.ttf",30,0)),
                            options_font(al_load_font("Joystick.otf",20,0)),
                            score_font(al_load_font("PressStart2P.ttf", 12,0))
{
  BulletInterface::createBulletObjPool();
  AsteroidInterface::createAsteroidObjPool();
  Nave::Instance()->setX((const float) (frame->getW() / 2.0 - Nave::Instance()->getW() / 2.0));
  Nave::Instance()->setY((const float) (frame->getH() / 2.0 - Nave::Instance()->getH() / 2.0 + 200));
}

ObjectsInterface::~ObjectsInterface()
{
  Nave::deleteNave();
  BulletInterface::deleteBulletObjPool();
  AsteroidInterface::deleteAsteroidObjPool();
  delete hearts;
  delete frame;
  al_destroy_font(title_font);
  al_destroy_font(options_font);
  al_destroy_font(score_font);
}

void ObjectsInterface::show_menu()
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

void ObjectsInterface::check_bullets_with_asteroids()
{
  for (BulletObjPool::Iterator bullet_itr = BulletInterface::getBegin(), bullet_end = BulletInterface::getEnd(); bullet_itr != bullet_end + 1; bullet_itr++)
  {

    if ((*bullet_itr)->getY() <= 0)
    {
      BulletInterface::eraseBullet(bullet_itr);
      bullet_end = BulletInterface::getEnd();
      continue;
    }

    for (AsteroidObjPool::Iterator aster_itr = AsteroidInterface::getBegin(), aster_end = AsteroidInterface::getEnd(); aster_itr != aster_end + 1; aster_itr++)
      if ((*bullet_itr)->check_colision_with(*aster_itr))
      {
        BulletInterface::incGunScoreIn();
        AsteroidInterface::eraseAsteroid(aster_itr);
        aster_end = AsteroidInterface::getEnd();
        continue;
      }
  }

  if (MainGame::get()->get_timer_count()%150 == 0)
    BulletInterface::decGunScoreIn();
}

void ObjectsInterface::check_nave_with_asteroids()
{
  if (Nave::Instance()->getDestroyed() && (Nave::Instance()->getWhenDestroyed() + 90 == MainGame::get()->get_timer_count()) )
      Nave::Instance()->make_vulnerable();

  else
    for (AsteroidObjPool::Iterator aster_itr = AsteroidInterface::getBegin(), aster_end = AsteroidInterface::getEnd(); aster_itr != aster_end; aster_itr++)
    {
      if ((*aster_itr)->getY() >= 480)
      {
        AsteroidInterface::eraseAsteroid(aster_itr);
        aster_end = AsteroidInterface::getEnd();
        continue;
      }

      if ((*aster_itr)->check_colision_with(Nave::Instance()))
      {
        std::cout << "Nave: Haciendo invulnerable\n";
        AsteroidInterface::eraseAsteroid(aster_itr);
        Nave::Instance()->make_invulnerable(MainGame::get()->get_timer_count());
        hearts->lost_heart();
        return;
      }
    }
}

void ObjectsInterface::check_nave_with_powerups()
{
  if (!PowerUp::instance()->pun)
    if (PowerUp::instance()->check_colision_with(Nave::Instance()))
    {
      std::cout << "PUN!" << MainGame::get()->get_timer_count() << std::endl;
      PowerUp::instance()->set_destroyed_at(MainGame::get()->get_timer_count());
      PowerUp::instance()->pun = true;
    }
  if (MainGame::get()->get_timer_count() == PowerUp::instance()->get_destroyed_at()+800)
  {
    PowerUp::instance()->reset_bitmap();
    std::cout << MainGame::get()->get_timer_count() << std::endl;
    PowerUp::instance()->pun = false;
  }
}

void ObjectsInterface::receive_score()
{ score = int_to_string(BulletInterface::getScore()); }

void ObjectsInterface::update_objects()
{
  if ((*KEYBOARD::get())[UP] && Nave::Instance()->getY() >= 4.3 + 76)
  {
    Nave::Instance()->moveY(-4.3);
    Nave::Instance()->setSourceX(NAVE_UP);
  }
  else if ((*KEYBOARD::get())[DOWN] && Nave::Instance()->getY() <= frame->getH() - Nave::Instance()->getH() - 4.3)
  {
    Nave::Instance()->moveY(4.3);
    Nave::Instance()->setSourceX(NAVE_UP);
  }
  else if ((*KEYBOARD::get())[LEFT] && Nave::Instance()->getX() >= 4.3 + 40)
  {
    Nave::Instance()->moveX(-4.3);
    Nave::Instance()->setSourceX(NAVE_LEFT);
  }
  else if ((*KEYBOARD::get())[RIGHT] && Nave::Instance()->getX() <= frame->getW() - Nave::Instance()->getW() - 4.3 )
  {
    Nave::Instance()->moveX(4.3);
    Nave::Instance()->setSourceX(NAVE_RIGHT);
  }
  else
  {
    Nave::Instance()->setSourceX(NAVE_UP);
  }

  if ((*KEYBOARD::get())[CHAR_A] && MainGame::get()->get_timer_count()%13 == 0)
  {
    Nave::Instance()->shootGun();
  }

  Nave::Instance()->draw_bitmap(0);
  BulletInterface::updateBullets();
  AsteroidInterface::updateAsteroids(MainGame::get()->get_timer_count());
  PowerUp::instance()->draw_bitmap(0);
}

void ObjectsInterface::draw_objects()
{ update_objects(); }

void ObjectsInterface::draw_information()
{
  receive_score();
  frame->draw_bitmap(0);
  al_draw_text(score_font,al_map_rgb(110,110,100),400,45,0,"SCORE:");
  al_draw_text(score_font,al_map_rgb(110,110,100),500,45,0,score.c_str());
  hearts->draw_hearts();
}

bool ObjectsInterface::no_hearts()
{ return hearts->empty(); }
