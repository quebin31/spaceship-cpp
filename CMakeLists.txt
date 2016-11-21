cmake_minimum_required(VERSION 3.6)
project(GameNave)

# Version number
set(GameNave_VERSION_MAJOR 1)
set(GameNave_VERSION_MAJOR 0)


#Flags c++14
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp GAME.cpp GAME.h KEYBOARD.cpp KEYBOARD.h BITMAP.cpp BITMAP.h NAVE.cpp NAVE.h types.h asteroid.cpp asteroid.h)
add_executable(GameNave ${SOURCE_FILES})

#Includes
include_directories(usr/include/allegro5)

#Linking Allegro 5 libs
link_directories(usr/lib)

target_link_libraries(GameNave allegro_acodec
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

