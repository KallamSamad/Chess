#include "Queen.h"
#include <cmath>

Queen::Queen(Colour colour)
    : Piece(PieceType::Queen, colour, 0, 0)
{

}


bool Queen::isDiagnoalMove(int columnDifference, int  rowDifference) {
    if (rowDifference == 0 && columnDifference == 0)
    {
        return false;
    }

    if (rowDifference == columnDifference)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Queen::isStraightMove(int columnDifference, int rowDifference) {
    if (columnDifference > 0 && rowDifference == 0)
    {
        return true;
    }

    if (rowDifference > 0 && columnDifference == 0)
    {
        return true;
    }
    else {
        return false;
    }

}
bool Queen::isValidMove(int startRow, int startColumn, int destinationRow, int destinationColumn)
{


    int rowDifference = abs(destinationRow - startRow);
    int columnDifference = abs(destinationColumn - startColumn);

    bool diag=isDiagnoalMove(columnDifference, rowDifference);
    bool straight=isStraightMove(columnDifference, rowDifference);

    if (diag || straight) {
        return true;
    }
    else {
        return false;
    }

   
}