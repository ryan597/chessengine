#include <string>
#include <vector>

struct Square {
    char file;  // a b c d e f g h
    char rank;  // 1 2 3 4 5 6 7 8
};

class Piece {
private:
    char m_type;  // type isnt const for pawns
    const char m_colour;
    Square m_position;
    std::vector<std::string> m_legal_moves;
public:
    Piece(char type, char colour, Square position);
    auto get_type() -> char;
    auto get_colour() -> char;
    auto promote_pawn(char type) -> void;
    auto move(Square dest) -> void;
    auto generate_legal_moves() -> std::vector<std::string>;
};
