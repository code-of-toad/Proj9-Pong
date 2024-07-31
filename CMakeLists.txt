cmake_minimum_required(VERSION 3.28)
project(Proj9_Pong)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proj9_Pong
        src/main.cpp
        src/GLOBALS.hpp
)

############# SFML #############
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS REQUIRED
        system
        window
        graphics
        audio
        network
)
target_link_libraries(Proj9_Pong
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
)
################################