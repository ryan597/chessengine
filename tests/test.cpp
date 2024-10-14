#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <string>

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

TEST_CASE("Board initialization", "[board]") {
  Board chessboard;
  std::stringstream ss;
  // redirect cout to ss
  auto oldBuf = std::cout.rdbuf(ss.rdbuf());

  chessboard.display();
  std::string expectedOutput{"r n b q k b n r \n"
                             "p p p p p p p p \n"
                             ". . . . . . . . \n"
                             ". . . . . . . . \n"
                             ". . . . . . . . \n"
                             ". . . . . . . . \n"
                             "P P P P P P P P \n"
                             "R N B Q K B N R \n"};

  // reset now, causes a segfault if done after the require
  std::cout.rdbuf(oldBuf);

  REQUIRE(expectedOutput == ss.str());
}