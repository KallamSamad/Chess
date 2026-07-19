#include "Board.h"
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


//Functions

void Board::display() {
    for (size_t i{ 0 }; i < 8; i++) {
        for (size_t j{ 0 }; j < 8; j++) {
            if (squares[i * 8 + j] == nullptr) {
                std::cout << 'O'<<' ';
            }
            else {
                std::cout << squares[i * 8 + j]->getPiece()<<' ';
            }
        }
        std::cout << '\n';
    }
     
}

void Board::placePiece(int row, int column, PieceType pieceType, Colour colour) {
    squares[row * 8 + column] =
        new Piece(pieceType, colour, row, column);
}
void Board::placePiece(int row, int column, Colour colour) {
    squares[row * 8 + column] =
        new Piece(PieceType::Pawn, colour, row, column);
}


void Board::backrankSetUp(Colour colour) {
    PieceType pieceOrder[8] = {PieceType::Rook, PieceType::Knight, PieceType::Bishop, PieceType::Queen,PieceType::King, PieceType::Bishop, PieceType::Knight, PieceType::Rook};
    if (colour == Colour::White) {
        for (int x{ 0 }; x < 8; x++) {
            placePiece(0, x, pieceOrder[x], colour);
            placePiece(1, x, colour); //Overloaded fucntion
        }
    }
    if (colour == Colour::Black) {
        for (int x{ 0 }; x < 8; x++) {
            placePiece(7, x, pieceOrder[x], colour);
            placePiece(6, x, colour);//Overloaded fucntion

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
        placePiece(0, x, pieceOrder[x], Colour::White);
        placePiece(1, x, Colour::White);

        placePiece(7, x, pieceOrder[x], Colour::Black);
        placePiece(6, x, Colour::Black);
    }
}
Piece* Board::getPiece(int row, int column)
{
    return squares[row * 8 + column];
}

 
