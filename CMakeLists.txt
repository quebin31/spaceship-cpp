cmake_minimum_required(VERSION 3.5)
project(SpaceShip)

set(CMAKE_CXX_STANDARD 14)

file(GLOB RESOURCES "src/resources/*")
file(GLOB HEADERS   "src/inc/*.h")
file(GLOB SOURCES   "src/*.cc")

add_executable(SpaceShip ${HEADERS} ${SOURCES})

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
