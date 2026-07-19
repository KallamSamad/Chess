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
	//constructor

	Piece(PieceType, Colour, int row, int column);


	//functions 
	char getPiece() {
		switch (attribute) {
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
			std::logic_error(R"(Invalid piece type)");
		}
	}
	char getColour() {
		switch (pieceColour) {
		case Colour::White:
			return 'W';
		case Colour::Black:
			return 'B';
		default:
			std::logic_error(R"(Invalid Colour)");
		}
	}
};

#endif