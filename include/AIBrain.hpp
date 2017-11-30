//
// Created by pashervz on 29/11/17.
//

#ifndef TYRANOSAURUS_R_AIBRAIN_HPP
#define TYRANOSAURUS_R_AIBRAIN_HPP


#include <vector>
#include "ESquareType.hpp"

class AIBrain {
private:
    ESquareType         _type;
    const int           MAX = 1000;
    const int           MIN = -1000;
    const int           DEPTH = 3;
public:
    AIBrain(ESquareType);
    AIBrain();

    ESquareType const&  getType() const;
    void                setType(ESquareType);
    void                play();
    int                 minimax(int depth, int nodeIndex, bool maximizePlayer, std::vector<int> values, int alpha, int beta);
};


#endif //TYRANOSAURUS_R_AIBRAIN_HPP
