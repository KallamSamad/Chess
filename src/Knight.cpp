#include "Knight.h"
#include <cmath>

Knight::Knight(Colour colour)
    : Piece(PieceType::Knight, colour, 0, 0)
{

}


bool Knight::isValidMove(int startRow, int startColumn, int destinationRow, int destinationColumn)
{


    int rowDifference = abs(destinationRow - startRow);
    int columnDifference = abs(destinationColumn - startColumn);


    if ((rowDifference == 2 && columnDifference == 1)||(rowDifference == 1 && columnDifference == 2)){
        return true;
    }


    return false;
}