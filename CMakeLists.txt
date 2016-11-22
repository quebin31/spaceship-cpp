cmake_minimum_required(VERSION 3.6)
project(SpaceShip)

#Flags c++14
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp game.cpp game.h keyboard.cpp keyboard.h bitmap.cpp bitmap.h nave.cpp nave.h types.h asteroid.cpp asteroid.h set_of_asteroids.cpp set_of_asteroids.h gun.cpp gun.h)
add_executable(SpaceShip ${SOURCE_FILES})

#Includes
include_directories(usr/include/allegro5)

#Linking Allegro 5 libs
link_directories(usr/lib)

target_link_libraries(SpaceShip allegro_acodec
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

