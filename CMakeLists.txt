cmake_minimum_required(VERSION 3.5)
project(Pacman)

if (UNIX)
    message("UNIX System")
else(WIN32)
    message("Windows System")
endif()

# setting SFML directory path
include_directories(/usr/include)
set(SFML_DIR /usr/lib/x86_64-linux-gnu/cmake/SFML)

# setting and adding sources
set(SOURCES src/main.cpp 
            headers/Pacman/Pacman.hpp
            headers/Pacman/Pacman.cpp
            headers/GridMap/GridMap.hpp
            headers/GridMap/GridMap.cpp
            headers/Monster/Monster.hpp
            headers/Monster/Monster.cpp 
            headers/Score/Score.hpp
            headers/Score/Score.cpp

            headers/math/Math.hpp
            headers/math/Math.cpp
)

add_executable(Pacman ${SOURCES})

# targeting SFML components
target_link_libraries(Pacman
    PUBLIC
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)
