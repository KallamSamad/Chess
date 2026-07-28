#include "King.h"
#include <cmath>

King::King(Colour colour)
    : Piece(PieceType::King, colour, 0, 0)
{

}


bool King::isDiagnoalMove(int columnDifference, int  rowDifference) {
    if (rowDifference == 0 && columnDifference == 0)
    {
        return false;
    }

    if ((rowDifference == columnDifference)&& rowDifference==1)
    {
        return true;
    }
    else {
        return false;
    }
}

bool King::isStraightMove(int columnDifference, int rowDifference) {
    if (columnDifference==1 && rowDifference == 0)
    {
        return true;
    }

    if (rowDifference ==1 && columnDifference == 0)
    {
        return true;
    }
    else {
        return false;
    }

}
bool King::isValidMove(int startRow, int startColumn, int destinationRow, int destinationColumn)
{


    int rowDifference = abs(destinationRow - startRow);
    int columnDifference = abs(destinationColumn - startColumn);

    bool diag = isDiagnoalMove(columnDifference, rowDifference);
    bool straight = isStraightMove(columnDifference, rowDifference);

    if (diag || straight) {
        return true;
    }
    else {
        return false;
    }


}