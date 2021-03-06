//
// Created by pashervz on 29/11/17.
//

#include <iostream>
#include <string>
#include <random>
#include <sstream>
#include "AIBrain.hpp"
#include "Board.hpp"

AIBrain::AIBrain(Mediator & mediator) : AManager(mediator) {
    _type = ESquareType::BLACK;
}

ESquareType const& AIBrain::getType() const
{
    return (_type);
}

void    AIBrain::setType(ESquareType type)
{
    _type = type;
}

std::string const     AIBrain::play()
{
    _moveManager.findMoves();
    std::string move = _moveManager.determineBestMove();
    std::string toSplit = move;
    std::istringstream  iss(toSplit);
    int y = std::stoi(toSplit.substr(toSplit.find(",") + 1));
    std::getline(iss, toSplit, ',');
    int x = std::stoi(toSplit);
    Board::Inst()->setSquare(x, y, _type);
    return (move);
}

void AIBrain::receive(Event const &event)
{
    switch (event.type)
    {
        case EventType::BEGIN:
            begin();
            break;
        case EventType::START:
            start(event.datas.at(0));
            break;
        case EventType::TURN:
            turn(event.datas.at(0));
            break;
        case EventType ::BOARD:
            board(event.datas);
            break;
        default:
            break;
    }
}

void AIBrain::begin()
{
    Event event;
    event.type = EventType::WRITE;
    event.datas.push_back(std::to_string((Board::Inst()->getSize() - 1)) + "," + std::to_string((Board::Inst()->getSize() - 1)));
    Board::Inst()->setSquare(Board::Inst()->getSize() - 1, Board::Inst()->getSize() - 1, ESquareType::BLACK);
    sending(event);
}

void AIBrain::start(std::string const& string)
{
    Board::Inst()->setSize(std::stoi(string));
    Board::Inst()->clearMap();
    Event event;
    event.type = EventType::WRITE;
    event.datas.push_back("OK");
    sending(event);
}

void AIBrain::turn(std::string string)
{
    std::istringstream  iss(string);
    int y = std::stoi(string.substr(string.find(",") + 1));
    std::getline(iss, string, ',');
    int x = std::stoi(string);	
    Board::Inst()->setSquare(x, y, WHITE);
    Event event;
    event.type = EventType::WRITE;
    event.datas.push_back(play());
    //Board::Inst()->displayMap();
    sending(event);
}

void AIBrain::board(std::vector<std::string> const& infos)
{
    Board::Inst()->clearMap();
    for (auto const& it : infos)
    {
        if (it != "BOARD")
        {
            std::string str = it;
            std::istringstream iss(str);
            int color = std::stoi(str.substr(str.find_last_of(",") + 1));
            std::getline(iss, str, ',');
            int x = std::stoi(str.substr(str.find(",") + 1));
            std::getline(iss, str, ',');
            int y = std::stoi(str);
            if (color == 1)
                Board::Inst()->setSquare(x, y, BLACK);
            else
                Board::Inst()->setSquare(x, y, WHITE);
        }
    }
    Event event;
    event.type = EventType::WRITE;
    event.datas.push_back(play());
    sending(event);
}
