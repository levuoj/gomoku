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

Board::Board()
{
    clearMap();
}

std::vector<ESquareType> const& Board::getMap() const
{
    return (_map);
}

int                                 Board::getSize() const
{
    return (_size);
}

void                                Board::setSize(int size)
{
    for (int i = 0; i < (size * size); ++i)
        _map.push_back(EMPTY);
    _size = size;
}

void                                Board::setSquare(int x, int y, ESquareType type)
{
    _map[x + _size * y] = type;
}

void                                Board::emptySquare(int x, int y)
{
    _map[x + _size * y] = EMPTY;
}

void                                Board::clearMap()
{
    std::fill(begin(_map), end(_map), EMPTY);
}

bool                                Board::isEmpty(int x, int y) const
{
    return (_map[x + _size * y] ==  EMPTY);
}

void                                Board::displayMap() const
{
    std::cout << std::string(21, '#') << std::endl;
    for (auto y = 0; y < _size; ++y)
    {
        std::cout << "#";
        for (auto x = 0; x < _size; ++x)
        {
            if (_map[x + _size * y] == EMPTY)
                std::cout << " ";
            else if (_map[x + _size * y] == BLACK)
                std::cout << "B";
            else
                std::cout << "W";
        }
        std::cout << "#" << std::endl;
    }
    std::cout << std::string(21, '#') << std::endl;
}

ESquareType Board::getSquareType(int x, int y)
{
    return (_map[x + _size * y]);
}