//
// Created by pashervz on 29/11/17.
//

#ifndef TYRANOSAURUS_R_MEDIATOR_HPP
#define TYRANOSAURUS_R_MEDIATOR_HPP

#include <vector>
#include <memory>
#include "AManager.hpp"

class Mediator {
private:
    std::vector<std::shared_ptr<AManager>>      _managers;

public:
};


#endif //TYRANOSAURUS_R_MEDIATOR_HPP
