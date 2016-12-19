cmake_minimum_required(VERSION 3.6)
project(SpaceShip2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp
        tools_and_headers/spaceship_includes.h
        tools_and_headers/int_to_string.h
        tools_and_headers/int_to_string.cpp
        bitmap_objects/bitmap.cpp
        bitmap_objects/bitmap.h
        bitmap_objects/nave.cpp
        bitmap_objects/nave.h
        bitmap_objects/asteroid.cpp
        bitmap_objects/asteroid.h
        bitmap_objects/bullet.cpp
        bitmap_objects/bullet.h
        bitmap_objects/heart.cpp
        bitmap_objects/heart.h
        bitmap_objects/image.cpp
        bitmap_objects/image.h
        bitmap_objects/power_up.cpp
        bitmap_objects/power_up.h
        bitmap_interfaces/hearts_interface.cpp
        bitmap_interfaces/hearts_interface.h
        bitmap_interfaces/asteroids_interface.cpp
        bitmap_interfaces/asteroids_interface.h
        bitmap_interfaces/bullet_interface.cpp
        bitmap_interfaces/bullet_interface.h
        bitmap_interfaces/game_facade.cpp
        bitmap_interfaces/game_facade.h
        game_interfaces/keyboard.cpp
        game_interfaces/keyboard.h
        game_interfaces/main_game.cpp
        game_interfaces/main_game.h bitmap_interfaces/power_up_interface.cpp bitmap_interfaces/power_up_interface.h)

add_executable(SpaceShip2 ${SOURCE_FILES})

include_directories(usr/include/allegro5)

link_directories(usr/lib)

target_link_libraries(SpaceShip2 allegro_acodec
        allegro_audio
        allegro_color
        allegro_dialog
        allegro_image
        allegro_main
        allegro_memfile
        allegro_physfs
        allegro_primitives
        allegro_ttf
        allegro_font
        allegro)