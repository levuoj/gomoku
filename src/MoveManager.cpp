//
// Created by pashervz on 05/12/17.
//

#include "MoveManager.hpp"

std::string const             MoveManager::determineBestMove() {
    if (!this->_moves.empty()) {
        int                   bestScore = 0;
        std::string           bestMove;
        for (auto & it : this->_moves) {
            Action      bestAction = it.findBestAction();

            if (bestAction.score > bestScore) {
                bestScore += bestAction.score;
            }
        }
    }
    return ("Error");
}