cmake_minimum_required(VERSION 3.10)
project(ExO_C99 C)

add_library(bitutils STATIC ${PROJECT_SOURCE_DIR}/src/bitutils.c)
target_include_directories(bitutils PUBLIC include)

add_library(board STATIC ${PROJECT_SOURCE_DIR}/src/board.c)
target_link_libraries(board PUBLIC bitutils)
target_include_directories(board PUBLIC include)

add_library(game STATIC ${PROJECT_SOURCE_DIR}/src/game.c)
target_link_libraries(game PUBLIC board)
target_include_directories(game PUBLIC include)

add_library(exoc99 INTERFACE)
target_link_libraries(exoc99 INTERFACE game)

add_executable(
  exoc99_main
  ${PROJECT_SOURCE_DIR}/app/main.c
)
target_link_libraries(exoc99_main game)
