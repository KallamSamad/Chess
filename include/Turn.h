#ifndef TURN_H
#define TURN_H

#include "Board.h"
#include "Move.h"

class Game
{
private:

    Board board;
    Colour currentPlayer;
    bool gameOver;

public:

    void startGame();

    void takeTurn();

    void gameLoop();

    void switchPlayer();

    bool checkGameOver();
};

#endif