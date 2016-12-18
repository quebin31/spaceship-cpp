//
// Created by kevin on 9/12/16.
//

#ifndef SPACESHIP2_POWER_UP_H
#define SPACESHIP2_POWER_UP_H

#include "../bitmap_interfaces/bullet_interface.h"
#include "bitmap.h"

class PowerUp;
class PowerUpInterface;

class PowerUp : public Bitmap
{
  private:
    double generate_random_coord(const int x, const int y);

  private:
    static PowerUp* _instance;
    PowerUp();

  private:
    friend class PowerUpInterface;

  public:
    bool check_colision_with(Bitmap *some) override;
    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};

class PowerUpInterface
{
  private:
    static int generate_random_type_except(const int excpt);

  public:
    static void createPowerUpInstance();
    static void deletePowerUpInstance();

    static void updatePowerUp(int64_t actual_count_frames);
    static void changeType();

    static PowerUp* Instance();
};

//class PowerUpOld : public Bitmap
//{
//  private:
//    int generate_random_power_up(int, int);
//    static PowerUpOld* power_up;
//    int64_t destroyed_at;
//    int state;
//
//  public:
//    PowerUpOld();
//    ~PowerUpOld();
//
//    static PowerUpOld* instance();
//
//    bool check_colision_with(Bitmap *some) override;
//    void draw_bitmap(const int flags) override;
//    void reset_bitmap() override;
//    int64_t get_destroyed_at();
//    void set_destroyed_at(int64_t );
//    bool pun;
//    int get_state();
//    void generate_state();
//};


#endif //SPACESHIP2_POWER_UP_H
