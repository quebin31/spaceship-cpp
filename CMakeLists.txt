cmake_minimum_required(VERSION 3.5)
project(SpaceShip)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/resources)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

set(SOURCE_FILES ${PROJECT_SOURCE_DIR}/main.cpp
        ${PROJECT_SOURCE_DIR}/tools_and_headers/spaceship_includes.h
        ${PROJECT_SOURCE_DIR}/tools_and_headers/int_to_string.h
        ${PROJECT_SOURCE_DIR}/tools_and_headers/int_to_string.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_objects/bitmap.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_objects/bitmap.h
        ${PROJECT_SOURCE_DIR}/bitmap_objects/nave.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_objects/nave.h
        ${PROJECT_SOURCE_DIR}/bitmap_objects/asteroid.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_objects/asteroid.h
        ${PROJECT_SOURCE_DIR}/bitmap_objects/bullet.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_objects/bullet.h
        ${PROJECT_SOURCE_DIR}/bitmap_objects/heart.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_objects/heart.h
        ${PROJECT_SOURCE_DIR}/bitmap_objects/image.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_objects/power_up.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_objects/image.h
        ${PROJECT_SOURCE_DIR}/bitmap_objects/power_up.h
        ${PROJECT_SOURCE_DIR}/bitmap_interfaces/hearts_interface.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_interfaces/hearts_interface.h
        ${PROJECT_SOURCE_DIR}/bitmap_interfaces/asteroids_interface.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_interfaces/asteroids_interface.h
        ${PROJECT_SOURCE_DIR}/bitmap_interfaces/bullet_interface.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_interfaces/bullet_interface.h
        ${PROJECT_SOURCE_DIR}/bitmap_interfaces/game_facade.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_interfaces/game_facade.h
        ${PROJECT_SOURCE_DIR}/bitmap_interfaces/power_up_interface.cpp
        ${PROJECT_SOURCE_DIR}/bitmap_interfaces/power_up_interface.h
        ${PROJECT_SOURCE_DIR}/game_interfaces/keyboard.cpp
        ${PROJECT_SOURCE_DIR}/game_interfaces/keyboard.h
        ${PROJECT_SOURCE_DIR}/game_interfaces/main_game.cpp
        ${PROJECT_SOURCE_DIR}/game_interfaces/main_game.h)

add_executable(SpaceShip ${SOURCE_FILES})

include_directories(${PROJECT_SOURCE_DIR}/allegro5)
link_directories(${PROJECT_SOURCE_DIR}/libs)

target_link_libraries(SpaceShip
  allegro_acodec
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
