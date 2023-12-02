#include <string>
#include <vector>

struct Square {
    char file;  // a b c d e f g h
    char rank;  // 1 2 3 4 5 6 7 8
};

class Piece {
private:
    char m_type;
    char m_colour;
    Square m_position;
    std::vector<std::string> legalMoves;
public:
    Piece(char type, char colour, Square position) : m_type(type), m_colour(colour), m_position(position) {
        legalMoves = generateLegalMoves();
    }
    auto move(Square dest) -> void;
    auto isLegalMove(std::string move) -> bool;
    auto isLegalMove(Square dest) -> bool;
    auto isCapture(Square dest) -> bool;
    auto isCheck(Square dest) -> bool;
    auto generateLegalMoves() -> std::vector<std::string>;
};
