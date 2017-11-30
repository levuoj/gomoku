//
// Created by pashervz on 28/11/17.
//

#include "Board.hpp"

int             main()
{
    Board       board;

    board.displayMap();
    board.setSquare(7, 0, BLACK);
    board.setSquare(7, 1, BLACK);
    board.displayMap();
}
