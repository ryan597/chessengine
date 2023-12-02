#include "board.hpp"


auto Board::getFEN() -> std::string {
    return m_currentFEN;
}

auto Board::setFEN(std::string& fen_string) -> bool {
    if (checkFENIsValid(fen_string)){
        m_currentFEN = fen_string;
        return true;
    }
    else{
        std::cout << "FEN is not valid.\n";
        return false;
    }
}

auto Board::checkFENIsValid(std::string fen) -> bool {
    // check the formatting is correct

    return true;
}

auto Board::printFEN() -> void {
    std::cout << getFEN();
}

auto Board::printPosition() -> void {
    auto fen = getFEN();
    std::vector<char> pieces = {'p','r','n','b','q','k','P','R','N','B','Q','K'};
    std::string asciPosition{};
    for (auto& i: fen){
        if (std::find(pieces.begin(), pieces.end(), i)  != std::end(pieces)){
            asciPosition += i;
        }
        else if (isdigit(i)){
            asciPosition += std::string(i-'0', '.');
        }
        else if (i == '/'){
            asciPosition += '\n';
        }
        else if (i == ' ')
        {
            std::cout << asciPosition << '\n';
            return;
        }
    }
}

auto Board::isLegalMove(std::string& notation) -> bool {
    return true;
}

auto Board::move(std::string notation) -> bool {

    if (isLegalMove(notation)){

        return true;
    }
    return false;
}

auto Board::parseMove(std::string move) -> std::pair<Square, Square> {
    char piece = move[0];
    Square src;

    int pad{};
    if (move[-1] == '+' || move[-1] == '#'){
        pad++;
    }
    Square dst;
    dst.file = move[-2-pad];
    dst.rank = move[-1-pad];

    return {src, dst};
}