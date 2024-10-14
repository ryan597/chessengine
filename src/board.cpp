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
               blackBishops | blackRooks | blackQueens | blackKing),

      whitePieces(whitePawns | whiteKnights | whiteBishops | whiteRooks |
                  whiteQueens | whiteKing),
      blackPieces(blackPawns | blackKnights | blackBishops | blackRooks |
                  blackQueens | blackKing) {}

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

auto Board::getPieceAt(int square) const -> uint64_t {
  const uint64_t pieceMask = mask(square);
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

auto Board::makeMove(int from, int to) -> bool {

  const uint64_t fromMask = mask(from);
  const uint64_t toMask = mask(to);

  if ((whitePawns & fromMask) != 0) {
    whitePawns &= ~fromMask;
    whitePawns |= toMask;
    occupied &= ~fromMask;
    occupied |= toMask;
    return true;
  }

  return false; // invalid move
}

auto Board::isValidMove(int from, int to) -> bool {
  const uint64_t fromMask = mask(from);
  const uint64_t toMask = mask(to);

  if ((whitePawns & fromMask) != 0) {
    return validatePawnMove(from, to, true);
  }

  if ((blackPawns & fromMask) != 0) {
    return validatePawnMove(from, to, false);
  }
}

auto Board::validatePawnMove(int from, int to, bool isWhite) -> bool {
  const int direction = isWhite ? 1 : -1;
  const int startRank = isWhite ? 1 : 6;

  if (to == from + (8 * direction) && !(occupied & mask(to))) {
    return true; // move one square
  }

  if (to == from + (16 * direction) && from / 8 == startRank &&
      !(occupied & mask(to)) && !(occupied & mask(from + (8 * direction)))) {
    return true; // move two squares from starting position
  }

  if ((to == from + (7 * direction) || from + (9 * direction)) &&
      (occupied & mask(to))) {
    if (isWhite && (blackPieces & mask(to))) {
      return true;
    }
    if (!isWhite && (whitePieces & mask(to))) {
      return true;
    }
    return true; // capture diagonally
  }

  return false;
}

auto validateBishopMove(int from, int to) -> bool {}
auto validateRookMove(int from, int to) -> bool {}
auto validateQueenMove(int from, int to) -> bool {}
auto validateKingMove(int from, int to) -> bool {}

auto parseSquare(std::string square) -> int {
  const char fileChar = square[0];
  const char rankChar = square[1];

  const int file = fileChar - 'a';
  const int rank = rankChar - '1';

  return rank * 8 + file;
}

auto mask(int position) -> uint64_t { return (1ULL << position); }