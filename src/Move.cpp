//
// Created by levuoj on 12/6/17.
//

#include <include/Board.hpp>
#include "Move.hpp"

Move::Move(int x, int y) : _x(x), _y(y)
{
    addAction();
    setScore();
}

bool        Move::checkSquare(int x, int y)
{
    if ((_x + x < 0) || (_x + x > 18))
        return (false);
    if ((_y + y < 0) || (_y + y > 18))
        return (false);
    return (Board::Inst()->isEmpty(_x + x, _y + y));
}

bool        Move::SquareExist(int x, int y) {
    if ((x < 0) || (x > 18))
        return (false);
    if ((y < 0) || (y > 18))
        return (false);
    return (true);
}

void        Move::addAction()
{
    //_actions.emplace_back(EScore::INVALID, std::make_pair(_x, _y));
    if (checkSquare(-1, -1))
        _actions.emplace_back(0, std::make_pair(_x - 1, _y - 1));
    if (checkSquare(0, -1))
        _actions.emplace_back(0, std::make_pair(_x, _y - 1));
    if (checkSquare(1, -1))
        _actions.emplace_back(0, std::make_pair(_x + 1, _y - 1));
    if (checkSquare(1, 0))
        _actions.emplace_back(0, std::make_pair(_x + 1, _y));
    if (checkSquare(1, 1))
        _actions.emplace_back(0, std::make_pair(_x + 1, _y + 1));
    if (checkSquare(-1, 1))
        _actions.emplace_back(0, std::make_pair(_x - 1, _y + 1));
    if (checkSquare(0, 1))
        _actions.emplace_back(0, std::make_pair(_x, _y + 1));
    if (checkSquare(-1, 0))
        _actions.emplace_back(0, std::make_pair(_x - 1, _y));
}

std::string const   Move::addToPattern(int x, int y)
{
    if (Board::Inst()->getSquareType(x, y) == ESquareType::EMPTY)
        return (" ");
    else if (Board::Inst()->getSquareType(x, y) == ESquareType::BLACK)
        return  ("B");
    else
        return ("W");
}

int                 Move::checkPattern(std::string const &pattern, ESquareType type)
{
    //std::cout << "pattern : '" << pattern << "'" << std::endl;
    if (type == ESquareType::BLACK)
    {
        for (auto const& map : BlackScore)
        {
            if (pattern.find(map.second) != std::string::npos)
                return (map.first);
        }
    }
    else
    {
        for (auto const& map : WhiteScore)
        {
            if (pattern.find(map.second) != std::string::npos)
            {
                //std::cout << "found : '" << map.second << "'" << std::endl;
                return (map.first);
            }
        }
    }
    return (0);
}

int                 Move::diagonalNO(std::pair<int, int> const & pair, ESquareType type)
{
    std::string     pattern;

    for (auto i = -4; i <= 4; ++i)
    {
        if (i == 0) {
            if (type == ESquareType::BLACK)
                pattern += 'B';
            else
                pattern += 'W';
        }
        else if (SquareExist(pair.first + i, pair.second + i))
            pattern += addToPattern(pair.first + i, pair.second + i);
    }
    return (checkPattern(pattern, type));
}

int                 Move::diagonalNE(std::pair<int, int> const & pair, ESquareType type)
{
    std::string     pattern;

    for (auto i = -4; i <= 4; ++i)
    {
        if (i == 0) {
            if (type == ESquareType::BLACK)
                pattern += 'B';
            else
                pattern += 'W';
        }
        else if (SquareExist(pair.first + i, pair.second - i))
            pattern += addToPattern(pair.first + i, pair.second - i);
    }
    return (checkPattern(pattern, type));
}

int                 Move::horizontal(std::pair<int, int> const & pair, ESquareType type)
{
    std::string     pattern;

    for (auto i = -4; i <= 4; ++i)
    {
        if (i == 0) {
            if (type == ESquareType::BLACK)
                pattern += 'B';
            else
                pattern += 'W';
        }
        else if (SquareExist(pair.first + i, pair.second))
            pattern += addToPattern(pair.first + i, pair.second);
    }
    return (checkPattern(pattern, type));
}

int                 Move::vertical(std::pair<int, int> const & pair, ESquareType type)
{
    std::string     pattern;

    for (auto i = -4; i <= 4; ++i)
    {
        if (i == 0) {
            if (type == ESquareType::BLACK)
                pattern += 'B';
            else
                pattern += 'W';
        }
        else if (SquareExist(pair.first, pair.second + i))
            pattern += addToPattern(pair.first, pair.second + i);
    }
    return (checkPattern(pattern, type));
}

void                Move::setScore()
{
    for (auto &it : _actions)
    {
        if (it.score != EScore::INVALID)
        {
            it.score = diagonalNO(it.coords, ESquareType::BLACK)
                       + diagonalNE(it.coords, ESquareType::BLACK)
                       + horizontal(it.coords, ESquareType::BLACK)
                       + vertical(it.coords, ESquareType::BLACK)
                       + diagonalNO(it.coords, ESquareType::WHITE)
                       + diagonalNE(it.coords, ESquareType::WHITE)
                       + horizontal(it.coords, ESquareType::WHITE)
                       + vertical(it.coords, ESquareType::WHITE);
        }
    }
}

Action const&      Move::findBestAction()
{
    if (_actions.empty())
	return (_actions.front());
    int score = 0;
    size_t index = 0;
    size_t count = 0;
    for (const auto &it : _actions)
    {
	    if (score <= it.score)
        {
	        score = it.score;
            count = index;
	    }
        ++index;
    }
    return (_actions.at(count));
}
