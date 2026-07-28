#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <vector>
#include "Board.h"
#include "Piece.h"
enum class MoveType {
    Normal,
    Capture,
    Castling,
    EnPassant,
    Promotion
};

class Board;
class Piece;

class Move {
 
private:
    Board& board;
    Piece* movingPiece;
    int startRow;
    int startColumn;
    int destinationRow;
    int destinationColumn;
    Piece* destinationPiece;
    Piece* capturedPiece;
    MoveType moveType;
    PieceType promotionPieceType;
    int capturedPieceRow;
    int capturedPieceColumn;
    Piece* castlingRook;
    int rookStartRow;
    int rookStartColumn;
    int rookDestinationRow;
    int rookDestinationColumn;
    int spaces;
    char colour;
public:
    Move(Board& board);
    void movePawn(int startRow, int numSpaces, char startColumn);
    char getPawnInput(char pawn);
    int getNumSpaces(int spaces);
    bool isValidPawnMove(char colour, int startRow, int spaces, int column);
    void calculateDestination(char colour, int startRow, int spaces, int column);
};
#endif