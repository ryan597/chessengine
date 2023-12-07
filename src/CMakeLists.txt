set(SOURCES main.cpp piece.cpp)
add_library(nginlib SHARED
    piece.hpp
    player.hpp
    board.hpp
    piece.cpp
    player.cpp
    board.cpp
)

add_executable(NGin ${SOURCES})
