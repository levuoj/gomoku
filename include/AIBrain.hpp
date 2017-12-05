//
// Created by pashervz on 29/11/17.
//

#ifndef TYRANNOSAURUS_R_AIBRAIN_HPP
#define TYRANNOSAURUS_R_AIBRAIN_HPP

#include "Mediator.hpp"
#include "AManager.hpp"

#include <vector>
#include "ESquareType.hpp"
#include "Board.hpp"
#include "MoveManager.hpp"

class AIBrain : public AManager {
private:
    ESquareType _type;
    Board board;
    MoveManager moveManager;

    const int MAX = 1000;
    const int MIN = -1000;
    const int DEPTH = 3;

    std::string const play();

    int minimax(int depth, int nodeIndex, bool maximizePlayer, std::vector<int> values, int alpha, int beta);

public:
    AIBrain(ESquareType, Mediator &);

    explicit AIBrain(Mediator &);

    virtual ~AIBrain() final = default;

    void receive(Event const &);

    ESquareType const &getType() const;

    void setType(ESquareType);

    void begin();

    void start(std::string const &);

    void turn(std::string);
};

#endif //TYRANNOSAURUS_R_AIBRAIN_HPP
