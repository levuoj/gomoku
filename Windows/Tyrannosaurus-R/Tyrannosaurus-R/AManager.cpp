//
// Created by pashervz on 29/11/17.
//

#include "AManager.hpp"

void AManager::sending(Event const & event) {
    _mediator.transmit(event);
}
