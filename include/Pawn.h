#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
public:

    Pawn(Colour colour);

    bool isValidMove(
        int startRow,
        int startColumn,
        int destinationRow,
        int destinationColumn
    ) override;

};

#endif