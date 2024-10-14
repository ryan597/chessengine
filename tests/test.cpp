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

TEST_CASE("Making moves", "[board]") {
  Board chessboard;
  std::stringstream ss;
  // redirect cout to ss
  auto oldBuf = std::cout.rdbuf(ss.rdbuf());

  SECTION("Check pawn moves") {
    int from = parseSquare("e2");
    int to = parseSquare("e4");
    chessboard.makeMove(from, to);
    chessboard.display();
    std::string expectedOutput{"r n b q k b n r \n"
                               "p p p p p p p p \n"
                               ". . . . . . . . \n"
                               ". . . . . . . . \n"
                               ". . . . P . . . \n"
                               ". . . . . . . . \n"
                               "P P P P . P P P \n"
                               "R N B Q K B N R \n"};

    // reset now, causes a segfault if done after the require
    std::cout.rdbuf(oldBuf);

    REQUIRE(expectedOutput == ss.str());
  }
}

TEST_CASE("Parse squares", "[board]") {
  // 56 57 58 59 60 61 62 63
  // 48 49 50 51 52 53 54 55
  // 40 41 42 43 44 45 46 47
  // 32 33 34 35 36 37 38 39
  // 24 25 26 27 28 29 30 31
  // 16 17 18 19 20 21 22 23
  // 8  9  10 11 12 13 14 15
  // 0  1  2  3  4  5  6  7

  int a1 = parseSquare("a1");
  int b2 = parseSquare("b2");
  int c3 = parseSquare("c3");
  int d4 = parseSquare("d4");
  int e5 = parseSquare("e5");
  int f6 = parseSquare("f6");
  int g7 = parseSquare("g7");
  int h8 = parseSquare("h8");

  REQUIRE(a1 == 0);
  REQUIRE(b2 == 9);
  REQUIRE(c3 == 18);
  REQUIRE(d4 == 27);
  REQUIRE(e5 == 36);
  REQUIRE(f6 == 45);
  REQUIRE(g7 == 54);
  REQUIRE(h8 == 63);
}