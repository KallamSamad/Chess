#include "Pawn.h"

Pawn::Pawn(Colour colour)
    : Piece(PieceType::Pawn, colour, 0, 0)
{

}


bool Pawn::isValidMove(int startRow,int startColumn,int destinationRow,int destinationColumn)
{

    int direction;
    Colour colour = getColour();

    if (colour == Colour::White)
        direction = -1;
    else
        direction = 1;

    // Moving forward one square
    if (destinationColumn == startColumn &&
        destinationRow == startRow + direction)
    {
        return true;
    }


    // Moving two squares from starting position
    if (destinationColumn == startColumn &&
        destinationRow == startRow + (2 * direction))
    {
        return true;
    }


    return false;
}