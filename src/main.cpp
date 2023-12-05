#include "board.cpp"
#include "player.cpp"


auto main(int argc, char** argv) -> int {

    Player player1{"White", 1500.0, 'w'};
    Player player2{"Black", 1600.0, 'b'};

    Board board{};

    Pawn* apawn = new Pawn('w', Square{'a', '2'});
    std::cout << apawn->get_file();
    delete apawn;

    board.print_fen();
    board.print();

    board.move("d4");

    board.print();
}