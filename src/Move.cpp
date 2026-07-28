#include "Move.h"
#include "Board.h"
#include "Piece.h"


Move::Move(Board& board, Piece* piece,
    int startRow, int startColumn,
    int destinationRow, int destinationColumn)
    :
    board(board),
    movingPiece(piece),
    startRow(startRow),
    startColumn(startColumn),
    destinationRow(destinationRow),
    destinationColumn(destinationColumn)
{

}


bool Move::isValid()
{
    return movingPiece->isValidMove(
        startRow,
        startColumn,
        destinationRow,
        destinationColumn
    );
}


void Move::execute()
{
    board.setPiece(destinationRow, destinationColumn, movingPiece);
    board.setPiece(startRow, startColumn, nullptr);
}