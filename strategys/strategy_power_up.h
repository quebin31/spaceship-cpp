#ifndef STRATEGY_POWER_UP_H
#define STRATEGY_POWER_UP_H

#include "../bitmap_objects/power_up.h"
#include "../bitmap_objects/bullet.h"
#include "../bitmap_interfaces/bullet_interface.h"

#define n_files 3

typedef struct FILES{
  char* name_file;
  int width;
  int heigh;
}FILES;

class strategy_power_up{
  private:
    static strategy_power_up* _instance;
    static std::vector<FILES*> files;
  public:
    strategy_power_up();
    ~strategy_power_up();
    static strategy_power_up* Instance(){
      if (!_instance)
        _instance = new strategy_power_up;
      return _instance;
    }

#endif // STRATEGY_POWER_UP_H
