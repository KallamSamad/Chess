#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "Piece.h"
class Board
{
private:
    std::vector<Piece*> squares;


public:
    // Constructor
    Board();
    //destructor
    ~Board();
    // Functions
    void display();
    void placePiece(int row, int column, PieceType pieceType, Colour colour);
    void clearBoard();
    void fileDisplay();
    std::string getChessNotation(int row, int column);

    Piece* getPiece(int row, int column);
    bool isPathClear(int startRow,int startColumn,int destinationRow,int destinationColumn);
    void backrankSetUp(Colour colour);
    void boardSetUpClassic();
    void boardSetUp960();
    void setPiece(int row, int column, Piece* piece);
};

#endif