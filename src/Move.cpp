#include "Piece.h"
#include "Move.h"
#include "Board.h"
#include <iostream>

Move::Move(Board& board)
    : board{ board }
{
}
char Move::getPawnInput()
{
    char pawn;

    do {
        std::cout << "Choose start pawn" << std::endl;
        std::cin >> pawn;

        if (pawn < 'a' || pawn > 'h') {
            std::cout << "Invalid Input! Choose from a-h";
        }

    } while (pawn < 'a' || pawn > 'h');

    return pawn;
}
int Move::getNumSpaces()
{
    int spaces;

    do {
        std::cout << "Choose how many spaces" << std::endl;
        std::cin >> spaces;

        if (spaces != 1 && spaces != 2) {
            std::cout << "Invalid Input! Choose 1 or 2";
        }

    } while (spaces != 1 && spaces != 2);

    return spaces;
}



void Move::calculateDestination(char colour, int startRow, int spaces, int column) {
    if (colour == 'W') {
        destinationRow = startRow - spaces;
        destinationColumn = column;
        destinationPiece = board.getPiece(destinationRow, destinationColumn);
    }
    else if (colour == 'B') {
        destinationRow = startRow + spaces;
        destinationColumn = column;
        destinationPiece = board.getPiece(destinationRow, destinationColumn);

    }
}
bool Move::isValidPawnMove(char colour, int startRow, int spaces, int column){

        if (destinationPiece != nullptr) {
            std::cout << "Invalid move! The destination is occupied." << std::endl;
            return false; 
        }
        if (spaces == 2) {
            if (colour == 'W' && startRow != 6) {
                std::cout << "Invalid move! White pawns can only move two spaces from rank 1." << std::endl;
                return false;
            }

            if (colour == 'B' && startRow != 1) {
                std::cout << "Invalid move! Black pawns can only move two spaces from rank 6." << std::endl;
                return false;
            }
        }
        if (spaces == 2) {
            int middleRow;

            if (colour == 'W') {
                middleRow = startRow - 1;
            }
            else {
                middleRow = startRow + 1;
            }

            Piece* middlePiece = board.getPiece(middleRow, column);
 
            if (middlePiece != nullptr) {
                std::cout << "Invalid move! A piece is blocking the pawn." << std::endl;
                return false;
            }
            return true;

        }
        if (spaces == 1) {
            return true;
        }
}
void Move::movePawn(Colour col)
{
    char pawn = getPawnInput();
    int column = pawn - 'a';

    int startRow;

    if (col == Colour::White)
    {
        startRow = 6;
    }
    else
    {
        startRow = 1;
    }

    int spaces = getNumSpaces();

    movingPiece = board.getPiece(startRow, column);

    if (movingPiece == nullptr)
    {
        std::cout << "There is no piece on that square!" << std::endl;
        return;
    }

    char colour = movingPiece->getColour();

    calculateDestination(colour, startRow, spaces, column);

    bool validPawn = isValidPawnMove(colour, startRow, spaces, column);

    if (validPawn)
    {
        board.setPiece(destinationRow, destinationColumn, movingPiece);
        board.setPiece(startRow, column, nullptr);
    }
    else
    {
        std::cout << "Invalid move!" << std::endl;
    }
}