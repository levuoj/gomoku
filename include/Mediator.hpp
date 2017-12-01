//
// Created by pashervz on 29/11/17.
//

#ifndef TYRANNOSAURUS_R_MEDIATOR_HPP
#define TYRANNOSAURUS_R_MEDIATOR_HPP

#include <memory>
#include <vector>
#include "Event.hpp"
#include "AIBrain.hpp"
#include "ProtocolManager.hpp"

#include <vector>
#include <memory>
#include "AManager.hpp"

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

    void        launch();
};


#endif //TYRANNOSAURUS_R_MEDIATOR_HPP
