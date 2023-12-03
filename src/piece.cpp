#include "piece.hpp"

Piece::Piece(char type, char colour, Square position) : m_type(type), m_colour(colour), m_position(position) {
    m_legal_moves = generate_legal_moves();
}

auto Piece::get_type() -> char {
    return m_type;
}

auto Piece::get_colour() -> char {
    return m_colour;
}

auto Piece::promote_pawn(char type) -> void {}

auto Piece::move(Square dest) -> void {
        m_position = dest;
}

auto Piece::generate_legal_moves() -> std::vector<std::string> {
    return {" "};
}