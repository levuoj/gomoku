//
// Created by levuoj on 12/6/17.
//

#include "Move.hpp"

Move::Move(int x, int y) : _x(x), _(y)
{}

bool        Move::checkSquare(int x, int y)
{
    if ((_x + x < 0) || (_x + x > 18))
        return (false);
    if ((_y + y < 0) || (_y + y > 18))
        return (false);
    return (Board.Inst().isEmpty(_x + x, _y + y));
}

void        Move::addAction()
{
    if (checkSquare(-1, -1))
        _actions.push_back(0, std::make_pair(x - 1, y - 1));
    if (checkSquare(0, -1))
        _actions.push_back(0, std::make_pair(x, y - 1));
    if (checkSquare(1, -1))
        _actions.push_back(0, std::make_pair(x + 1, y - 1));
    if (checkSquare(1, 0))
        _actions.push_back(0, std::make_pair(x + 1, y));
    if (checkSquare(1, 1))
        _actions.push_back(0, std::make_pair(x + 1, y + 1));
    if (checkSquare(-1, 1))
        _actions.push_back(0, std::make_pair(x - 1, y + 1));
    if (checkSquare(0, 1))
        _actions.push_back(0, std::make_pair(x, y + 1));
    if (checkSquare(-1, 0))
        _actions.push_back(0, std::make_pair(x - 1, y));
}

void       Move::setScore()
{
    for (const auto &it : _actions)
    {
        it.score += 0;
    }
}

Action const&      Move::findBestAction()
{
    if (_actions.empty())
        return (nullptr);
    int score = 0;
    int index = 0;
    for (const auto &it : _actions)
    {
        if (score <= it.score) {
            score = it.score;
            index = it - _actions.begin();
        }
    }
    return (_actions.at(index));
}