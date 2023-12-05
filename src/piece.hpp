#ifndef H_PIECE
#define H_PIECE

#include <string>
#include <vector>

struct Square {
    char file{};  // a b c d e f g h
    char rank{};  // 1 2 3 4 5 6 7 8
};

class Piece {
private:
    char m_type;
    const char m_colour;
    Square m_position;
    std::vector<std::string> m_legal_moves;
public:
    Piece(char type, char colour, Square position);
    auto get_type() -> char;
    auto get_colour() -> char;
    auto get_file() -> int;
    auto get_rank() -> int;
    auto move(Square dest) -> void;
};


class Pawn: public Piece {
public:
    Pawn(char colour, Square position);
    auto promote_pawn(char type) -> void;
    auto generate_legal_moves() -> std::vector<std::string>;
};


class Rook: public Piece {
public:
    Rook(char colour, Square position);
    auto generate_legal_moves() -> std::vector<std::string>;
};

class Knight: public Piece {
public:
    Knight(char colour, Square position);
    auto generate_legal_moves() -> std::vector<std::string>;
};

class Bishop: public Piece {
public:
    Bishop(char colour, Square position);
    auto generate_legal_moves() -> std::vector<std::string>;
};

class Queen: public Piece {
public:
    Queen(char colour, Square position);
    auto generate_legal_moves() -> std::vector<std::string>;
};

class King: public Piece {
public:
    King(char colour, Square position);
    auto generate_legal_moves() -> std::vector<std::string>;
};


#endif