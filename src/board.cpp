#include "board.hpp"

Board::Board(){
    m_turn = 'w';
    // FEN - position, turn, castling rights, halfmove counter (for 50 move rule), fullmove counter
    m_current_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    const std::vector<std::pair<char, char>> starting_square{{'R', 'a'}, {'N', 'b'}, {'B', 'c'}, {'Q', 'd'}, {'K', 'e'}, {'B', 'f'}, {'N', 'g'}, {'R', 'h'}};
    m_pieces.reserve(32);

    for (auto i: starting_square){ {
        m_pieces.emplace_back(std::make_unique<Pawn>('w', Square{i.second, '2'}));
        m_pieces.emplace_back(std::make_unique<Pawn>('w', Square{i.second, '1'}));
        m_pieces.emplace_back(std::make_unique<Pawn>('b', Square{i.second, '7'}));
        m_pieces.emplace_back(std::make_unique<Pawn>('b', Square{i.second, '8'}));
        }
    }
}

Board::Board(int variant){
    m_turn = 'w';

    switch (variant){
    case 0:
        Board();
        break;
    case 960:
        // Fischer random - Chess960
        // Black will mirror White's randomised pieces
        // King must be between the two rooks so that castling both sides is valid
        // otherwise, randomise the backrank

        const std::vector<std::pair<char, char>> starting_square{{'R', 'a'}, {'N', 'b'}, {'B', 'c'}, {'Q', 'd'}, {'K', 'e'}, {'B', 'f'}, {'N', 'g'}, {'R', 'h'}};
        m_pieces.reserve(32);

        for (auto i: starting_square){ {
            m_pieces.emplace_back(std::make_unique<Pawn>('w', Square{i.second, '2'}));
            m_pieces.emplace_back(std::make_unique<Pawn>('w', Square{i.second, '1'}));
            m_pieces.emplace_back(std::make_unique<Pawn>('b', Square{i.second, '7'}));
            m_pieces.emplace_back(std::make_unique<Pawn>('b', Square{i.second, '8'}));
            }
        }
    }
}

auto Board::get_fen() -> std::string {
    // needs to generate the fen from pieces
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
    // printing from the FEN - Likely to scrap
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

auto Board::print() -> void {
    std::array<char, 64> board_position{};
    std::fill(board_position.begin(), board_position.end(), '-');

    for (auto &piece: m_pieces){
        auto file = piece->get_file();
        auto rank = piece->get_rank();
        // when printing we start at the top left of the board (a8), so rank=7 (0 index for the array)
        // and file=0 (0 indexed for the array)
        board_position.at(64 - rank*8 + file-8) = piece->get_type();
    }

    for (int i=0; i<64; i++){
        std::cout << board_position.at(i);
        if ((i+1) % 8 == 0){
            std::cout << '\n';
        }
    }
}

auto Board::is_legal_move(std::string notation) -> bool {
    std::vector<std::string> legal_moves;
    for (auto& piece: m_pieces){
        legal_moves.emplace_back(piece->generate_legal_moves(this));
    }
    // TODO: check if two pieces can move to the same square
    // eg. R on d1 and R on d8 can both move to d5, so the moves must be
    // denoted as R1d5 and R8d5 respectively

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
    if (move.at(move.size()-1) == '+' || move.at(move.size()-1) == '#'){
        pad++;
    }
    dst.file = move.at(move.size()-2-pad);
    dst.rank = move.at(move.size()-1-pad);

    char piece = move[0];
    if (piece >= 'a'){  // pawn move denoted by lower case letter eg. dxe5
        for (auto &i:m_pieces){
            if (i->get_type() == 'P' && i->get_colour() == m_turn){
                i->move(dst);
                return;
            }
        }
    }
    else{  // piece move denoted by uppercase letter R,N,B,Q,K

    }
}

auto Board::get_pieces() -> std::vector<std::unique_ptr<Piece>>& {
    return m_pieces;
}