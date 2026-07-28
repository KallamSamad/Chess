#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

enum class PieceType {
	Empty,
	King,
	Queen,
	Rook,
	Bishop,
	Knight,
	Pawn
	 
};

enum class Colour {
	White,
	Black
};

class Piece {

private:
    PieceType attribute;
    Colour pieceColour;
    int row;
    int column;

public:

    Piece(PieceType, Colour, int row, int column);

    virtual bool isValidMove(
        int startRow,
        int startColumn,
        int destinationRow,
        int destinationColumn
    ) = 0;


    Colour getColour() const
    {
        return pieceColour;
    }

    PieceType getPiece() const {
        return attribute;
    }

    char getPieceSymbol() const
    {
        switch (attribute)
        {
        case PieceType::King:
            return 'K';

        case PieceType::Queen:
            return 'Q';

        case PieceType::Rook:
            return 'R';

        case PieceType::Bishop:
            return 'B';

        case PieceType::Knight:
            return 'N';

        case PieceType::Pawn:
            return 'P';

        default:
            return ' ';
        }
    }
};

class King : public Piece
{
public:
    King(Colour colour)
        : Piece(PieceType::King, colour, 0, 0)
    {
    }

    bool isValidMove(int, int, int, int) override
    {
        return true; // temporary
    }
};


 
#endif