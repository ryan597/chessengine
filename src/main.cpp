#include "board.cpp"
#include "player.cpp"


auto main(int argc, char** argv) -> int {

    Player player1{"White", 1500.0, 'w'};
    Player player2{"Black", 1600.0, 'b'};

    Board board{};

    board.print();

    board.move("d4");
    board.move("d5");

    board.print();
}