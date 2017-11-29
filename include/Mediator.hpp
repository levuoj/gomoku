//
// Created by pashervz on 29/11/17.
//

#ifndef TYRANOSAURUS_R_MEDIATOR_HPP
#define TYRANOSAURUS_R_MEDIATOR_HPP

#include <memory>
#include <vector>
#include "Event.hpp"
#include "AIBrain.hpp"
#include "ProtocolManager.hpp"

class Mediator {
private:
    std::vector<std::shared_ptr<AManager>>      _managers;
public:
    Mediator();
    ~Mediator() = default;

    void        transmit(Event const & event) {
        for (auto const & it : _managers) {
            it->receive(event);
        }
    }

    void        launch() {}
};


#endif //TYRANOSAURUS_R_MEDIATOR_HPP
