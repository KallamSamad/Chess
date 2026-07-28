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

    bool takeTurn();

    void gameLoop();

    std::string switchPlayer();

    bool checkGameOver();
};

#endif