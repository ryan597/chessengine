#include "board.hpp"

Board::Board()
    : // initialize bitboards
      whitePawns(WHITEPAWNS), whiteKnights(WHITEKNIGHTS),
      whiteBishops(WHITEBISHOPS), whiteRooks(WHITEROOKS),
      whiteQueens(WHITEQUEENS), whiteKing(WHITEKING),

      blackPawns(BLACKPAWNS), blackKnights(BLACKKNIGHTS),
      blackBishops(BLACKBISHOPS), blackRooks(BLACKROOKS),
      blackQueens(BLACKQUEENS), blackKing(BLACKKING),
      occupied(whitePawns | whiteKnights | whiteBishops | whiteRooks |
               whiteQueens | whiteKing | blackPawns | blackKnights |
               blackBishops | blackRooks | blackQueens | blackKing) {}

void Board::display() const {
  for (int rank = 7; rank >= 0; rank--) {
    for (int file = 0; file < 8; file++) {
      int square = rank * 8 + file;
      if (getPieceAt(square) != 0) {
        std::cout << static_cast<char>(getPieceAt(square)) << ' ';
      } else {
        std::cout << ". ";
      }
    }
    std::cout << '\n';
  }
}

uint64_t Board::getPieceAt(int square) const {
  uint64_t pieceMask = (1ULL << square);
  if ((whitePawns & pieceMask) != 0) {
    return 'P';
  }
  if ((whiteKnights & pieceMask) != 0) {
    return 'N';
  }
  if ((whiteBishops & pieceMask) != 0) {
    return 'B';
  }
  if ((whiteRooks & pieceMask) != 0) {
    return 'R';
  }
  if ((whiteQueens & pieceMask) != 0) {
    return 'Q';
  }
  if ((whiteKing & pieceMask) != 0) {
    return 'K';
  }

  if ((blackPawns & pieceMask) != 0) {
    return 'p';
  }
  if ((blackKnights & pieceMask) != 0) {
    return 'n';
  }
  if ((blackBishops & pieceMask) != 0) {
    return 'b';
  }
  if ((blackRooks & pieceMask) != 0) {
    return 'r';
  }
  if ((blackQueens & pieceMask) != 0) {
    return 'q';
  }
  if ((blackKing & pieceMask) != 0) {
    return 'k';
  }

  return 0; // empty square
}

bool Board::makeMove(int from, int to) {
  uint64_t fromMask = (1ULL << from);
  uint64_t toMask = (1ULL << to);

  if ((whitePawns & fromMask) != 0) {
    whitePawns &= ~fromMask;
    whitePawns |= toMask;
    occupied &= ~fromMask;
    occupied |= toMask;
    return true;
  }

  return false; // invalid move
}