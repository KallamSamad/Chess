#include <windows.h>
#include "Board.h"
#include "../include/Piece.h"
#include "Move.h"
#include "Turn.h"
 int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Board board;

    Game game;

    game.gameLoop();

    return 0;
}