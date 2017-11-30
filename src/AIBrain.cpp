//
// Created by pashervz on 29/11/17.
//

#include <iostream>
#include "AIBrain.hpp"

AIBrain::AIBrain(ESquareType type, Mediator & mediator) : AManager(mediator)
{
    _type = type;
}

AIBrain::AIBrain(Mediator & mediator) : AManager(mediator) {}

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

void AIBrain::receive(Event const &event) {
    std::cout << "AIBrain : I received an event : " << event.datas.at(0) << std::endl;
}