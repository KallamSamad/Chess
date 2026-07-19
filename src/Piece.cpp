#include "Piece.h"


Piece::Piece(PieceType pieceType, Colour colour, int row, int column)
    : attribute{ pieceType },
    pieceColour{ colour },
    row{ row },
    column{ column }
{
}

 