#include <catch2/catch_test_macros.hpp>
#include <sstream>

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


TEST_CASE("Board constructor", "[board]"){
    Board chessboard{};
    auto& piece_vector = chessboard.get_pieces();
    REQUIRE(piece_vector.size() == 32);
}

TEST_CASE("Board print", "[board]"){
    Board chessboard{};
    std::stringstream ss;
    //redirect cout to stringstream, save old buffer
    auto old_buf = std::cout.rdbuf(ss.rdbuf());

    chessboard.print();
    std::string expected_output{"PPPPPPPP\nPPPPPPPP\n--------\n--------\n--------\n--------\nPPPPPPPP\nPPPPPPPP\n"};
    REQUIRE(expected_output.compare(ss.str()) == 0);

    std::cout.rdbuf(old_buf); //reset
}
