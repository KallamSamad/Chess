#include "Board.h"
#include "../include/Piece.h"
int main()
{
    Board board;
    std::cout << "=============================" << std::endl;
    std::cout << "Standard Chess Arrangement" << std::endl;
    std::cout << "=============================" << std::endl;
    board.boardSetUpClassic();
    board.display();
    std::cout <<"=============================="<< std::endl;
    std::cout << "960 Chess Arrangement" << std::endl;
    std::cout << "=============================" << std::endl;

    board.boardSetUp960();
    board.display();
    board.clearBoard();

    int row{ 7 };
    int column{ 0 };

    std::cout << board.getChessNotation(row, column) << '\n';


    return 0;
}