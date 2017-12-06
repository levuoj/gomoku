//
// Created by levuoj on 12/6/17.
//

#include <include/Board.hpp>
#include <include/EScore.hpp>
#include "Move.hpp"

Move::Move(int x, int y, ESquareType type) : _x(x), _y(y), _type(type)
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

void        Move::addAction()
{
    _actions.emplace_back(EScore::INVALID, std::make_pair(_x, _y));
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

int                 Move::diagonalNO(std::pair<int, int> const & pair)
{
    int             score = 0;
    std::string     pattern = NULL;

    return (score);
}

int                 Move::diagonalNE(std::pair<int, int> const & pair)
{
    int             score = 0;
    return (score);
}

int                 Move::horizontal(std::pair<int, int> const & pair)
{
    int             score = 0;
    return (score);
}

int                 Move::vertical(std::pair<int, int> const & pair)
{
    int             score = 0;
    return (score);
}

void                Move::setScore()
{
    for (auto &it : _actions)
    {
        if (it.score != EScore::INVALID)
        {
            it.score = diagonalNO(it.coords)
                    + diagonalNE(it.coords)
                    + horizontal(it.coords)
                    + vertical(it.coords);

        }
    }
}

Action const&      Move::findBestAction()
{
    if (_actions.empty())
	return (_actions.front());
    int score = 0;
    int index = 0;
    int count = 0;
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