//
// Created by pashervz on 29/11/17.
//

#ifndef TYRANOSAURUS_R_AIBRAIN_HPP
#define TYRANOSAURUS_R_AIBRAIN_HPP

#include "Mediator.hpp"
#include "AManager.hpp"

#include <vector>
#include "ESquareType.hpp"

class AIBrain : public AManager {
private:
    ESquareType _type;
    const int MAX = 1000;
    const int MIN = -1000;
    const int DEPTH = 3;
public:
    AIBrain(ESquareType, Mediator &);

    explicit AIBrain(Mediator &);

    virtual ~AIBrain() final = default;

    void receive(Event const &);

    ESquareType const &getType() const;

    void setType(ESquareType);

    void play();

    int minimax(int depth, int nodeIndex, bool maximizePlayer, std::vector<int> values, int alpha, int beta);
};


#endif //TYRANOSAURUS_R_AIBRAIN_HPP
