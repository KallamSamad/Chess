#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:

    Bishop(Colour colour);


    bool isValidMove(
        int startRow,
        int startColumn,
        int destinationRow,
        int destinationColumn
    ) override;

};

#endif