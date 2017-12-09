//
// Created by pashervz on 29/11/17.
//

#include "Mediator.hpp"

Mediator::Mediator()
{
    _managers.push_back(std::shared_ptr<AManager>(new AIBrain(*this)));
    _managers.push_back(std::shared_ptr<AManager>(new ProtocolManager(*this)));
}

void Mediator::launch() {
    while (!static_cast<ProtocolManager *>(_managers.at(1).get())->getTerminate())  {
        static_cast<ProtocolManager *>(_managers.at(1).get())->readInfos();

    }
}