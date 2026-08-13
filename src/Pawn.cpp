#include "Pawn.h"

Pawn::Pawn(Colour colour)
    : Piece(PieceType::Pawn, colour, 0, 0)
{
}

bool Pawn::isValidMove(int startRow, int startColumn,
    int destinationRow, int destinationColumn)
{
    int direction;
    Colour colour = getColour();

    int rowDifference = abs(destinationRow - startRow);
    int columnDifference = abs(destinationColumn - startColumn);

    if (colour == Colour::White)
        direction = -1;
    else
        direction = 1;

     if (destinationColumn == startColumn &&
        destinationRow == startRow + direction)
    {
        return true;
    }

     if (destinationColumn == startColumn &&
         destinationRow == startRow + (2 * direction))
     {
         if ((colour == Colour::White && startRow == 6) ||
             (colour == Colour::Black && startRow == 1))
         {
             return true;
         }
     }

     if ((rowDifference == 1 && columnDifference == 1) &&
        (destinationRow - startRow == direction))
    {
        return true;
    }

    return false;
}