#include "piece.hpp"

Piece::Piece(char type, char colour, Square position) : m_type(type), m_colour(colour), m_position(position) {
    m_legal_moves = {};
}

auto Piece::get_type() -> char {
    return m_type;
}

auto Piece::get_colour() -> char {
    return m_colour;
}

auto Piece::move(Square dest) -> void {
        m_position = dest;
}

auto Piece::get_file() -> int {
    return int(m_position.file - 'a');
}

auto Piece::get_rank() -> int {
    return int(m_position.rank - '1');
}

Pawn::Pawn(char colour, Square position): Piece('P', colour, position){}
auto Pawn::promote_pawn(char type) -> void {

}
auto Pawn::generate_legal_moves() -> std::vector<std::string> {
    return {" "};
}


Rook::Rook(char colour, Square position): Piece('R', colour, position){}
auto Rook::generate_legal_moves() -> std::vector<std::string> {
    return {" "};
}

Knight::Knight(char colour, Square position): Piece('N', colour, position){}
auto Knight::generate_legal_moves() -> std::vector<std::string> {
    return {" "};
}

Bishop::Bishop(char colour, Square position): Piece('B', colour, position){}
auto Bishop::generate_legal_moves() -> std::vector<std::string> {
    return {" "};
}

Queen::Queen(char colour, Square position): Piece('Q', colour, position){}
auto Queen::generate_legal_moves() -> std::vector<std::string> {
    return {" "};
}

King::King(char colour, Square position): Piece('K', colour, position){}
auto King::generate_legal_moves() -> std::vector<std::string> {
    return {" "};
}
