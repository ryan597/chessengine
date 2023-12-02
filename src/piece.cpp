#include "piece.hpp"


auto Piece::move(Square dest) -> void {
    if (isLegalMove(dest)){
        if (isCapture(dest)){
            // Remove piece from board
        }
        if (isCheck(dest))
        {
            // Update that opposing king is in check
        }
    }
}

auto Piece::isLegalMove(std::string move) -> bool {}
auto Piece::isLegalMove(Square dest) -> bool {}
auto Piece::isCapture(Square dest) -> bool {}
auto Piece::isCheck(Square dest) -> bool {}
auto Piece::generateLegalMoves() -> std::vector<std::string> {}