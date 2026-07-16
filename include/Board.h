#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
class Board
{
private:
    std::vector<char> squares = {};


public:
    // Constructor
    Board();

    // Functions
    void display();
    void boardSetUpClassic();
    void boardSetUp960();
};

#endif