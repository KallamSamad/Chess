#ifndef KNIGHT_H
#define KNIGHT_H
 

#include "Piece.h"

class Knight : public Piece
{
public:

    Knight(Colour colour);


    bool isValidMove(
        int startRow,
        int startColumn,
        int destinationRow,
        int destinationColumn
    ) override;

};

#endif