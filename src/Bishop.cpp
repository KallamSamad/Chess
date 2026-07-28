#include "Bishop.h"
#include <cmath>

Bishop::Bishop(Colour colour)
    : Piece(PieceType::Bishop, colour, 0, 0)
{

}


bool Bishop::isValidMove(int startRow, int startColumn, int destinationRow, int destinationColumn)
{


    int rowDifference = abs(destinationRow - startRow);
    int columnDifference = abs(destinationColumn - startColumn);


    if (rowDifference ==  columnDifference) {
        return true;
    }


    return false;
}