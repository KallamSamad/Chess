#include "Board.h"
#include "../include/Piece.h"
#include "Move.h"
int main()
{
    Board board;

    board.boardSetUpClassic();

    Move move(board);

    board.display();

    move.movePawn(6, 1, 'a');

    board.display();

    return 0;
}