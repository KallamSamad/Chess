#include "Board.h"

//Constructor
Board::Board()
{
    for (int i{ 0 }; i < 8; i++) {
        for (int j{ 0 }; j < 8; j++) {
            squares.push_back('X');
        }
    }
    
}

//Functions

void Board::display() {
    for (size_t i{ 0 }; i < 8; i++) {
        for (size_t j{ 0 }; j < 8; j++) {
            if (j >= 7) {
                std::cout << std::endl;
            }
            else {
                std::cout << squares[i];
            }
        }
    }
     
}