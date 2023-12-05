#ifndef H_BOARD
#define H_BOARD

#include <iostream>
#include <algorithm>
#include <memory>
#include <array>
#include "piece.hpp"


class Board {
private:
    std::string m_current_fen;
    // Vector of pieces on board
    std::vector<std::shared_ptr<Piece>> m_pieces;
    char m_turn;

public:
    Board();
    Board(int variant);
    auto get_fen() -> std::string;
    auto set_fen(std::string& fen_string) -> bool;
    auto check_fen_is_valid(std::string fen) -> bool;
    auto print() -> void;
    auto print_fen() -> void;
    auto print_position() -> void;
    auto is_legal_move(std::string notation) -> bool;
    auto move(std::string notation) -> bool;
    auto parse_move(std::string move) -> void;
};


#endif