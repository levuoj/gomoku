//
// Created by pashervz on 29/11/17.
//

#ifndef TYRANOSAURUS_R_AMANAGER_HPP
#define TYRANOSAURUS_R_AMANAGER_HPP

#include "Event.hpp"

class Mediator;

class AManager {
protected:
    Mediator    &_mediator;

public:
    AManager(Mediator & mediator) : _mediator(mediator) {}
    virtual ~AManager() = default;

    virtual void receive(Event const &) = 0;

    void    sending(Event const &);
};

#include "Mediator.hpp"

#endif //TYRANOSAURUS_R_AMANAGER_HPP
