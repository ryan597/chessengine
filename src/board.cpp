#include "board.hpp"


auto Board::get_fen() -> std::string {
    return m_current_fen;
}

auto Board::set_fen(std::string& fen_string) -> bool {
    if (check_fen_is_valid(fen_string)){
        m_current_fen = fen_string;
        return true;
    }
    else{
        std::cout << "FEN is not valid.\n";
        return false;
    }
}

auto Board::check_fen_is_valid(std::string fen) -> bool {
    // check the formatting is correct

    return true;
}

auto Board::print_fen() -> void {
    std::cout << get_fen();
}

auto Board::print_position() -> void {
    auto fen = get_fen();
    std::vector<char> pieces = {'p','r','n','b','q','k','P','R','N','B','Q','K'};
    std::string asci_position{};
    for (auto& i: fen){
        if (std::find(pieces.begin(), pieces.end(), i)  != std::end(pieces)){
            asci_position += i;
        }
        else if (isdigit(i)){
            asci_position += std::string(i-'0', '.');
        }
        else if (i == '/'){
            asci_position += '\n';
        }
        else if (i == ' ')
        {
            std::cout << asci_position << '\n';
            return;
        }
    }
}

auto Board::is_legal_move(std::string& notation) -> bool {
    return true;
}

auto Board::move(std::string notation) -> bool {

    if (is_legal_move(notation)){
        parse_move(notation);
        return true;
    }
    return false;
}

auto Board::parse_move(std::string move) -> void {
    //Square src;
    Square dst;
    int pad{};
    if (move[-1] == '+' || move[-1] == '#'){
        pad++;
    }
    dst.file = move[-2-pad];
    dst.rank = move[-1-pad];

    char piece = move[0];
    if (piece >= 'a'){  // pawn move denoted by lower case letter eg. dxe5
        for (auto i:m_pieces){
            if (i.get_type() == 'P' && i.get_colour() == m_turn){
                i.move(dst);
            }
        }
    }
    else{  // piece move denoted by uppercase letter R,N,B,Q,K

    }
}