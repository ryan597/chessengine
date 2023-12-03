#include <iostream>
#include <algorithm>
#include "piece.hpp"


class Board {
private:
    std::string m_current_fen;
    // Array of squares
    std::vector<std::vector<char>> m_current_position;
    // Vector of pieces on board
    std::vector<Piece> m_pieces;
    char m_turn;

public:
    Board(){
        m_turn = 'w';
        // FEN - position, turn, castling rights, halfmove counter (for 50 move rule), fullmove counter
        m_current_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        m_current_position = {{'R','N','B','Q','K','B','N','R'},
                             {'P','P','P','P','P','P','P','P'},
                             {'-','-','-','-','-','-','-','-'},
                             {'-','-','-','-','-','-','-','-'},
                             {'-','-','-','-','-','-','-','-'},
                             {'-','-','-','-','-','-','-','-'},
                             {'p','p','p','p','p','p','p','p'},
                             {'r','n','b','q','k','b','n','r'}};
        const std::vector<std::pair<char, char>> starting_square{{'R', 'a'}, {'N', 'b'}, {'B', 'c'}, {'Q', 'd'}, {'K', 'e'}, {'B', 'f'}, {'N', 'g'}, {'R', 'h'}};
        for (auto i: starting_square){ {
            m_pieces.push_back({i.first, 'w', Square{i.second, '1'}});
            m_pieces.push_back({'P', 'w', Square{i.second, '2'}});
            m_pieces.push_back({i.first, 'b', Square{i.second, '7'}});
            m_pieces.push_back({'P', 'w', Square{i.second, '8'}});
            }
        }
    }

    auto get_fen() -> std::string;
    auto set_fen(std::string& fen_string) -> bool;
    auto check_fen_is_valid(std::string fen) -> bool;
    auto print_fen() -> void;
    auto print_position() -> void;
    auto is_legal_move(std::string& notation) -> bool;
    auto move(std::string notation) -> bool;
    auto parse_move(std::string move) -> void;
};