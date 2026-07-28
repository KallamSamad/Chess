#include "Rook.h"
#include <cmath>

Rook::Rook(Colour colour)
    : Piece(PieceType::Rook, colour, 0, 0)
{

}


bool Rook::isValidMove(int startRow, int startColumn, int destinationRow, int destinationColumn)
{


    int rowDifference = abs(destinationRow - startRow);
    int columnDifference = abs(destinationColumn - startColumn);


    if (columnDifference > 0 && rowDifference ==0)
    {
        return true;
    }

    if (rowDifference >0 && columnDifference ==0)
    {
        return true;
    }
    else {
        return false;
    }
}