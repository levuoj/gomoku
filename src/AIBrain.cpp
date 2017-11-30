//
// Created by pashervz on 29/11/17.
//

#include "AIBrain.hpp"

AIBrain::AIBrain(ESquareType type)
{
    _type = type;
}

AIBrain::AIBrain() {}

ESquareType const& AIBrain::getType() const
{
    return (_type);
}

void    AIBrain::setType(ESquareType type)
{
    _type = type;
}

int     AIBrain::minimax(int depth, int nodeIndex, bool maximizePlayer, std::vector<int> values, int, int)
{
    if (depth == DEPTH)
        return (values[nodeIndex]);
    if (maximizePlayer)
    {
        int best = MIN;
        return best;
    }
    else
    {
        int best = MAX;
        return best;
    }
}

void    AIBrain::play()
{
}