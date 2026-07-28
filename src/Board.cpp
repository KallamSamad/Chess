#include "Board.h"

#include "Piece.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Pawn.h"
#include "Knight.h"

#include <random>
 
//Constructor
Board::Board()
{
    for (int i{ 0 }; i < 8; i++) {
        for (int j{ 0 }; j < 8; j++) {
            squares.push_back(nullptr);
        }
    }
    
}
Board::~Board()
{
    clearBoard();
}
std::string Board::getChessNotation(int row, int column) {
    char file = 'a' + column;
    int rank = 8 - row;

    return std::string{ file } + std::to_string(rank);
}
void Board::clearBoard()
{
    for (Piece*& piece : squares) {
        delete piece;
        piece = nullptr;
    }
}

void Board::fileDisplay() {
    std::cout << "   ";
    for (size_t j{ 0 }; j < 8; j++) {
        char file = 'a' + j;
        std::cout << file << ' ';
    }

    std::cout << '\n';
}
//Functions

void Board::display() {
    fileDisplay();

    for (size_t i{ 0 }; i < 8; i++) {
        std::cout << 8 - i<< ' '<< ' ';
        for (size_t j{ 0 }; j < 8; j++) {

            if (squares[i * 8 + j] == nullptr) {
                std::cout << 'O'<<' ';
            }
            else {
                std::cout << squares[i * 8 + j]->getPieceSymbol()<<' ';
            }
        }

        std::cout << '\n';
    }
    fileDisplay();
     
}

void Board::placePiece(int row, int column, PieceType pieceType, Colour colour)
{
    switch (pieceType)
    {
    case PieceType::Pawn:
        squares[row * 8 + column] = new Pawn(colour);
        break;

          case PieceType::Knight:
             squares[row * 8 + column] = new Knight(colour);
             break;

         case PieceType::Bishop:
             squares[row * 8 + column] = new Bishop(colour);
             break;

         case PieceType::Rook:
             squares[row * 8 + column] = new Rook(colour);
             break;

         case PieceType::Queen:
             squares[row * 8 + column] = new Queen(colour);
             break;

         case PieceType::King:
             squares[row * 8 + column] = new King(colour);
             break;

    default:
        squares[row * 8 + column] = nullptr;
        break;
    }
}


void Board::backrankSetUp(Colour colour) {
    PieceType pieceOrder[8] = {PieceType::Rook, PieceType::Knight, PieceType::Bishop, PieceType::Queen,PieceType::King, PieceType::Bishop, PieceType::Knight, PieceType::Rook};
    if (colour == Colour::Black) {
        for (int x{ 0 }; x < 8; x++) {
            placePiece(0, x, pieceOrder[x], colour);
            placePiece(1, x, PieceType::Pawn, colour);
        }
    }
    if (colour == Colour::White) {
        for (int x{ 0 }; x < 8; x++) {
            placePiece(7, x, pieceOrder[x], colour);
            placePiece(6, x, PieceType::Pawn, colour);

        }
    }

}

void Board::boardSetUpClassic() {
    
        backrankSetUp(Colour::Black);
        backrankSetUp(Colour::White);
 

}

void Board::boardSetUp960() {
    std::vector<int> availablePositions{ };
    PieceType pieceOrder[8] = { };
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(0, 3);

    int randomNumber1 = dist(gen);
    int bishopPosition1 = randomNumber1 * 2 + 1;
    pieceOrder[bishopPosition1] = PieceType::Bishop;

    int randomNumber2 = dist(gen);
    int bishopPosition2 = randomNumber2 * 2;
    pieceOrder[bishopPosition2] = PieceType::Bishop;


    for (int x{ 0 }; x < 8; x++) {
        if (pieceOrder[x] == PieceType::Empty) {
            availablePositions.push_back(x);

        }

    }
    std::uniform_int_distribution<int> queenDist(0, 5);
    int randomIndex = queenDist(gen);
    int queenPosition = availablePositions[randomIndex];
    pieceOrder[queenPosition] = PieceType::Queen;
    availablePositions.erase(availablePositions.begin() + randomIndex);

    std::uniform_int_distribution<int> knightDist1(0, 4);
    int randomIndex1 = knightDist1(gen);
    int knightPosition1 = availablePositions[randomIndex1];
    pieceOrder[knightPosition1] = PieceType::Knight;
    availablePositions.erase(availablePositions.begin() + randomIndex1);
    
    std::uniform_int_distribution<int> knightDist2(0, 3);
    int randomIndex2 = knightDist2(gen);
    int knightPosition2 = availablePositions[randomIndex2];
    pieceOrder[knightPosition2] = PieceType::Knight;
    availablePositions.erase(availablePositions.begin() + randomIndex2);

    pieceOrder[availablePositions[0]] = PieceType::Rook;
    pieceOrder[availablePositions[1]] = PieceType::King;
    pieceOrder[availablePositions[2]] = PieceType::Rook;

    for (int x{ 0 }; x < 8; x++) {
        placePiece(0, x, pieceOrder[x], Colour::Black);
        placePiece(1, x, PieceType::Pawn, Colour::Black);

        placePiece(7, x, pieceOrder[x], Colour::White);
        placePiece(6, x, PieceType::Pawn, Colour::White);
    }
}
Piece* Board::getPiece(int row, int column)
{
    if (row < 0 || row >= 8 || column < 0 || column >= 8)
    {
        return nullptr;
    }

    return squares[row * 8 + column];
}
void Board::setPiece(int row, int column, Piece* piece)
{
    squares[row * 8 + column] = piece;
}