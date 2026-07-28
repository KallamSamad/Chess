#include "Turn.h"
#include "Board.h"
#include "../include/Piece.h"
#include "Move.h"

void Game::startGame()
{

    board.boardSetUpClassic();
    currentPlayer = Colour::White;

}
void Game::takeTurn(Colour player){
    Move move(board);
    move.movePawn(player);
}
bool Game::checkGameOver()
{
    char input;

    std::cout << "Game over? (y/n): ";
    std::cin >> input;

    return input == 'y';
}

void Game::switchPlayer() {
    {
        if (currentPlayer == Colour::White)
        {
            currentPlayer = Colour::Black;
        }
        else
        {
            currentPlayer = Colour::White;
        }
    }
}
void Game::gameLoop()
{
    startGame();
    gameOver = false;
    do
    {
        board.display();

        takeTurn(currentPlayer);

        switchPlayer();

        gameOver = checkGameOver();

    } while (gameOver == false);
}