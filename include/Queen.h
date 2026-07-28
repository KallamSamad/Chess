#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
public:

    Queen(Colour colour);

    bool isValidMove(
        int startRow,
        int startColumn,
        int destinationRow,
        int destinationColumn
    ) override;

    bool isDiagnoalMove(int columnDifference, int  rowDifference);

    bool isStraightMove(int columnDifference, int rowDifference);

};

 

#endif
