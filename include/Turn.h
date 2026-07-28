#ifndef TURN_H
#define TURN_H
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <Move.h>
#include <Piece.h>



class Game
{
private:
    Board board;
    Colour currentPlayer;
    bool gameOver;

public:
    void startGame();
    void takeTurn(Colour player);
    void gameLoop();
    void takeTurn();
    void switchPlayer();
    bool checkGameOver();
};

#endif