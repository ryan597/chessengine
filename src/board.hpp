#include <iostream>
#include <algorithm>
#include "piece.hpp"


class Board {
private:
    std::string m_currentFEN;
    // Array of squares
    std::vector<std::vector<char>> m_currentPosition;
    // Vector of pieces on board
    std::vector<Piece> Pieces;

public:
    Board(){
        // FEN - position, turn, castling rights, halfmove counter (for 50 move rule), fullmove counter
        //m_currentFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        m_currentPosition = {{'R','N','B','Q','K','B','N','R'},
                             {'P','P','P','P','P','P','P','P'},
                             {'-','-','-','-','-','-','-','-'},
                             {'-','-','-','-','-','-','-','-'},
                             {'-','-','-','-','-','-','-','-'},
                             {'-','-','-','-','-','-','-','-'},
                             {'p','p','p','p','p','p','p','p'},
                             {'r','n','b','q','k','b','n','r'}};
        const std::vector<std::pair<char, char>> startingSquare{{'R', 'a'}, {'N', 'b'}, {'B', 'c'}, {'Q', 'd'}, {'K', 'e'}, {'B', 'f'}, {'N', 'g'}, {'R', 'h'}};
        for (auto i: startingSquare){ {
            Pieces.push_back({i.first, 'w', Square{i.second, '1'}});
            Pieces.push_back({'P', 'w', Square{i.second, '2'}});
            Pieces.push_back({i.first, 'b', Square{i.second, '7'}});
            Pieces.push_back({'P', 'w', Square{i.second, '8'}});
            }
        }
    }

    auto getFEN() -> std::string;
    auto setFEN(std::string& fen_string) -> bool;
    auto checkFENIsValid(std::string fen) -> bool;
    auto printFEN() -> void;
    auto printPosition() -> void;
    auto isLegalMove(std::string& notation) -> bool;
    auto move(std::string notation) -> bool;
    auto parseMove(std::string move) -> std::pair<Square, Square>;
};