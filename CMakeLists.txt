cmake_minimum_required(VERSION 3.13)
project(NCursesConnectN C)

set(CMAKE_C_STANDARD 11)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses)


add_executable(NCursesConnectN main.c move.c move.h input_validation.c input_validation.h win.c win.h board.c board.h CurseTrackedWindow.c CurseTrackedWindow.h)

target_compile_options(NCursesConnectN PRIVATE -Wall -Werror)

target_link_libraries(NCursesConnectN PRIVATE ${CURSES_LIBRARIES})

target_include_directories(NCursesConnectN  PRIVATE ${CURSES_INCLUDE_DIRS})

set_target_properties(NCursesConnectN
        PROPERTIES
        OUTPUT_NAME "NCursesConnectN"
        SUFFIX ".out")
