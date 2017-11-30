//
// Created by pashervz on 29/11/17.
//

#ifndef TYRANNOSAURUS_R_AIBRAIN_HPP
#define TYRANNOSAURUS_R_AIBRAIN_HPP

#include "Mediator.hpp"
#include "AManager.hpp"

class AIBrain : public AManager {
public:
    explicit AIBrain(Mediator & mediator) : AManager(mediator) {}
    virtual ~AIBrain() final = default;
    void        receive(Event const &);
};


#endif //TYRANNOSAURUS_R_AIBRAIN_HPP