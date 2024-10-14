#include "board.hpp"
#include "player.hpp"

auto main(int argc, char **argv) -> int {

  Player player1{"White", 1500.0, 'w'};
  Player player2{"Black", 1600.0, 'b'};

  Board board;
  board.display();

  board.makeMove(12, 28);
  board.display();
}