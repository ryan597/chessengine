#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <unordered_set>

#include "board.hpp"
#include "piece.hpp"
#include "player.hpp"

/**
 * How to use the Catch2 framework following
 * https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#test-cases-and-sections
 *
 * TEST_CASE("Short Description", "[Optional tags]") {
 *      Setup the test variables, these are created new for each section
 *      std::vector<int> v(5);
 *
 *      SECTION("resizing bigger changes size and capacity") {
 *          v.resize(10);
 *          REQUIRE(v.size() == 10);
 *          REQUIRE(v.capacity() >= 10);
 *      }
 *      SECTION("reserving bigger changes capacity but not size") {
*           v.reserve( 10 );  // v is re-initialized as v(5)
            REQUIRE( v.size() == 5 );  // reserve doesnt change size
            REQUIRE( v.capacity() >= 10 );
 *      }
 * }
 *
*/

TEST_CASE("Board constructor sets up pieces correctly", "[board]"){
    Board chessboard{};
    auto& piece_vector = chessboard.get_pieces();
    std::unordered_set<Square, Square::HashFunction> occupied;
    int num_white{};
    int num_black{};

    for (auto& piece: piece_vector){
        auto type = piece->get_type();
        auto colour = piece->get_colour();
        auto position = piece->get_square();

        REQUIRE(occupied.contains(position) == false);
        occupied.insert(position);
        // By doing this mirror, we automatically check that black pieces are on the 7th and 8th ranks
        // as the mirrors must be on the 1st and 2nd ranks to pass the checks below, just as with the white pieces.
        // The above check for occupied squares also ensures we cannot have 2 white rooks on a1 and 2 black rooks on h8 which would
        // otherwise pass the below checks
        if (colour == 'b'){
            position.mirror();
            num_black++;
        }
        else {
            num_white++;
        }

        switch(type){
        case 'P':
            REQUIRE(position.rank == '2');
            break;
        case 'R':
            REQUIRE(position.rank == '1');
            REQUIRE((position.file == 'a' || position.file == 'h'));
            break;
        case 'N':
            REQUIRE(position.rank == '1');
            REQUIRE((position.file == 'b' || position.file == 'g'));
            break;
        case 'B':
            REQUIRE(position.rank == '1');
            REQUIRE((position.file == 'c' || position.file == 'f'));
            break;
        case 'Q':
            REQUIRE(position.rank == '1');
            REQUIRE(position.file == 'd');
            break;
        case 'K':
            REQUIRE(position.rank == '1');
            REQUIRE(position.file == 'e');
            break;
        }
    }
    REQUIRE(num_white == 16);
    REQUIRE(num_black == 16);
}

TEST_CASE("Board print", "[board]"){
    Board chessboard{};
    std::stringstream ss;
    //redirect cout to stringstream, save old buffer
    auto old_buf = std::cout.rdbuf(ss.rdbuf());

    chessboard.print();
    std::string expected_output{"rnbqkbnr\npppppppp\n--------\n--------\n--------\n--------\nPPPPPPPP\nRNBQKBNR\n"};
    REQUIRE(expected_output == ss.str());

    std::cout.rdbuf(old_buf); //reset
}

TEST_CASE("Board move", "[board, piece]"){
    Board chessboard{};
    chessboard.move("d4");
    chessboard.move("e5");
    chessboard.move("dxe5");
    chessboard.move("Nc6");
    chessboard.move("Nf3");
    chessboard.move("d4");
    chessboard.move("d4");
    chessboard.move("d4");
}