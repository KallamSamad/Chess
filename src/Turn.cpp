#include "Turn.h"
#include <iostream>
#include <string>


void Game::startGame()
{
    board.boardSetUpClassic();

    currentPlayer = Colour::White;
    gameOver = false;
}


void Game::takeTurn()
{
    std::string start;
    std::string destination;


    std::cout << "Move from: ";
    std::cin >> start;


    std::cout << "Move to: ";
    std::cin >> destination;

    if (start.length() != 2 || destination.length() != 2)
    {
        std::cout << "Invalid notation\n";
        return;
    }

    if (start[0] < 'a' || start[0] > 'h' ||
        destination[0] < 'a' || destination[0] > 'h' ||
        start[1] < '1' || start[1] > '8' ||
        destination[1] < '1' || destination[1] > '8')
    {
        std::cout << "Invalid square\n";
        return;
    }

    // Convert chess notation to board coordinates

    int startColumn = start[0] - 'a';
    int startRow = 8 - (start[1] - '0');


    int destinationColumn = destination[0] - 'a';
    int destinationRow = 8 - (destination[1] - '0');


    Piece* piece = board.getPiece(startRow, startColumn);


    if (piece == nullptr)
    {
        std::cout << "No piece on that square!\n";
        return;
    }


    Move move(
        board,
        piece,
        startRow,
        startColumn,
        destinationRow,
        destinationColumn
    );


    if (move.isValid())
    {
        move.execute();
    }
    else
    {
        std::cout << "Invalid move!\n";
    }
}


void Game::switchPlayer()
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


bool Game::checkGameOver()
{
    char input;

    std::cout << "Game over? (y/n): ";
    std::cin >> input;

    return input == 'y';
}


void Game::gameLoop()
{
    startGame();


    do
    {
        board.display();

        takeTurn();

        switchPlayer();

        gameOver = checkGameOver();

    } while (gameOver == false);
}