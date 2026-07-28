#ifndef MOVE_H
#define MOVE_H

class Board;
class Piece;

enum class MoveType {
    Normal,
    Capture,
    Castling,
    EnPassant,
    Promotion
};

class Move {

private:

    Board& board;

    Piece* movingPiece;
    Piece* capturedPiece;

    int startRow;
    int startColumn;

    int destinationRow;
    int destinationColumn;

    MoveType moveType;

public:

    Move(Board& board, Piece* piece,
        int startRow, int startColumn,
        int destinationRow, int destinationColumn);

    bool isValid();
    void execute();

    int getStartRow() const;
    int getStartColumn() const;

    int getDestinationRow() const;
    int getDestinationColumn() const;

    MoveType getMoveType() const;

};

#endif