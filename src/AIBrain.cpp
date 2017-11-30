//
// Created by pashervz on 29/11/17.
//

#include <iostream>
#include <string>
#include <random>
#include <sstream>
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

std::string const     AIBrain::play()
{
    std::random_device  rd;
    std::default_random_engine  generator(rd());
    std::uniform_int_distribution<int> distribution(1, 19);

    int x = distribution(generator);
    int y = distribution(generator);
    while (!board.isEmpty(x, y))
    {
        x = distribution(generator);
        y = distribution(generator);
    }
    return (std::to_string(x) + "," + std::to_string(y));
}

void AIBrain::receive(Event const &event)
{
    switch (event.type)
    {
        case EventType::BEGIN:
            begin();
            break;
        case EventType::START:
            start("OK");
            break;
        case EventType::TURN:
            turn(event.datas.at(0));
            break;
        default:
            break;
    }
}

void AIBrain::begin()
{
    Event event;
    event.type = EventType::WRITE;
    event.datas.push_back("9,8");
    sending(event);
}

void AIBrain::start(std::string const& string)
{
    Event event;
    event.type = EventType::WRITE;
    event.datas.push_back(string);
    sending(event);
}

void AIBrain::turn(std::string string)
{
    // tmp
    string = string.substr(string.find(" ") + 1);;
    //
    std::istringstream  iss(string);
    int y = std::stoi(string.substr(string.find(",") + 1));
    std::getline(iss, string, ',');
    int x = std::stoi(string);
    if (_type == BLACK)
        board.setSquare(x, y, WHITE);
    else
        board.setSquare(x, y, BLACK);
    Event event;
    event.type = EventType::WRITE;
    event.datas.push_back(play());
    sending(event);
}