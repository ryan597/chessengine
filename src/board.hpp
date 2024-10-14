#pragma once

#include <cstdint>
#include <iostream>

const uint64_t WHITEPAWNS = 0x000000000000FF00;   // 2nd rank for white pawns
const uint64_t WHITEKNIGHTS = 0x0000000000000042; // b1, g1
const uint64_t WHITEBISHOPS = 0x0000000000000024; // c1, f1
const uint64_t WHITEROOKS = 0x0000000000000081;   // a1, h1
const uint64_t WHITEQUEENS = 0x0000000000000008;  // d1
const uint64_t WHITEKING = 0x0000000000000010;    // e1

const uint64_t BLACKPAWNS = 0x00FF000000000000;   // 7th rank for black pawns
const uint64_t BLACKKNIGHTS = 0x4200000000000000; // b8, g8
const uint64_t BLACKBISHOPS = 0x2400000000000000; // c8, f8
const uint64_t BLACKROOKS = 0x8100000000000000;   // a8, h8
const uint64_t BLACKQUEENS = 0x0800000000000000;  // d8
const uint64_t BLACKKING = 0x1000000000000000;    // e8

class Board {
public:
  Board();
  void display() const;
  bool makeMove(int from, int to);
  void reset();

private:
  uint64_t whitePawns, whiteKnights, whiteBishops, whiteRooks, whiteQueens,
      whiteKing;
  uint64_t blackPawns, blackKnights, blackBishops, blackRooks, blackQueens,
      blackKing;
  uint64_t occupied;
  void initializeBoard();
  uint64_t getPieceAt(int square) const;
};
