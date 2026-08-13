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
    Piece* destinationPiece =
        board.getPiece(destinationRow, destinationColumn);

    if (destinationPiece != nullptr &&
        destinationPiece->getColour() == movingPiece->getColour())
    {
        return false;
    }

    if (!movingPiece->isValidMove(
        startRow,
        startColumn,
        destinationRow,
        destinationColumn))
    {
        return false;
    }

    PieceType type = movingPiece->getPiece();
    int rowDifference = abs(destinationRow - startRow);
    int columnDifference = abs(destinationColumn - startColumn);

    if (type == PieceType::Pawn) {
        if (destinationPiece != nullptr)
        {
            if (rowDifference == 1 && columnDifference == 1)
            {
                return true;
            }
            else {
                return false;
            }
        }

        if (destinationPiece == nullptr)
        {
            if (rowDifference == 1 && columnDifference == 1) {
                return false;
            }
            else {
                return true;
            }
        }
    }

    if (type == PieceType::Rook ||
        type == PieceType::Bishop ||
        type == PieceType::Queen)
    {
        if (!board.isPathClear(startRow, startColumn,
            destinationRow, destinationColumn))
        {
            return false;
        }
    }

    return true;
}

void Move::execute()
{
    Piece* capturedPiece = board.getPiece(destinationRow, destinationColumn);

    if (capturedPiece != nullptr)
    {
        delete capturedPiece;
    }
    board.setPiece(destinationRow, destinationColumn, movingPiece);
    board.setPiece(startRow, startColumn, nullptr);
}
