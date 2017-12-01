//
// Created by levuoj on 11/28/17.
//

#include <string>
#include <iostream>
#include "Board.hpp"

Board::Board()
{
    clearMap();
}

std::array<ESquareType, 361> const& Board::getMap() const
{
    return (_map);
}

void                                Board::setSquare(int x, int y, ESquareType type)
{
    _map[x + y * 19] = type;
}

void                                Board::emptySquare(int x, int y)
{
    _map[x + y * 19] = EMPTY;
}

void                                Board::clearMap()
{
    std::fill(begin(_map), end(_map), EMPTY);
}

bool                                Board::isEmpty(int x, int y) const
{
    return (_map[x + y * 19] ==  EMPTY);
}

void                                Board::displayMap() const
{
    std::cout << std::string(21, '#') << std::endl;
    for (auto y = 0; y < 19; ++y)
    {
        std::cout << "#";
        for (auto x = 0; x < 19; ++x)
        {
            if (_map[x + y * 19] == EMPTY)
                std::cout << " ";
            else if (_map[x + y * 19] == BLACK)
                std::cout << "O";
            else
                std::cout << "X";
        }
        std::cout << "#" << std::endl;
    }
    std::cout << std::string(21, '#') << std::endl;
}