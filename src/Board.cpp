//
// Created by levuoj on 11/28/17.
//

#include <string>
#include <iostream>
#include "Board.hpp"

//SINGLETON
//BEGIN

Board *        Board::boardInst = nullptr;

Board *        Board::Inst() {
    if (!boardInst)
        boardInst = new Board;
    return boardInst;
}

//END

const int      Board::SQRTDIM = static_cast<int>(std::sqrt(361));

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
    _map[x * SQRTDIM + y] = type;
}

void                                Board::emptySquare(int x, int y)
{
    _map[x * SQRTDIM + y] = EMPTY;
}

void                                Board::clearMap()
{
    std::fill(begin(_map), end(_map), EMPTY);
}

bool                                Board::isEmpty(int x, int y) const
{
    return (_map[x * SQRTDIM + y] ==  EMPTY);
}

void                                Board::displayMap() const
{
    std::cout << std::string(21, '#') << std::endl;
    for (auto y = 0; y < SQRTDIM; ++y)
    {
        std::cout << "#";
        for (auto x = 0; x < SQRTDIM; ++x)
        {
            if (_map[x * SQRTDIM + y] == EMPTY)
                std::cout << " ";
            else if (_map[x * SQRTDIM + y] == BLACK)
                std::cout << "O";
            else
                std::cout << "X";
        }
        std::cout << "#" << std::endl;
    }
    std::cout << std::string(21, '#') << std::endl;
}

ESquareType Board::getSquareType(int x, int y)
{
    return (_map[x * SQRTDIM + y]);
}