#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
public:

    King(Colour colour);

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
