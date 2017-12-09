//
// Created by pashervz on 05/12/17.
//

#include <string>
#include "EScore.hpp"
#include "MoveManager.hpp"

std::string const             MoveManager::determineBestMove() {
    if (!this->_moves.empty()) {
        int                   bestScore = 0;
        std::string           bestMove;
        for (auto & it : this->_moves) {
            //it.display();
            Action      bestAction = it.findBestAction();

            if (bestAction.score != EScore::INVALID) {
                if (bestAction.score > bestScore) {
                    bestScore += bestAction.score;
                    bestMove = std::to_string(bestAction.coords.first) +
                               "," +
                               std::to_string(bestAction.coords.second);
                }
            }
        }
        return (bestMove);
    }
    return ("ERROR");
}

void                        MoveManager::findMoves() {
    int                     idx = 0;

    clear();
    for (const auto & it : Board::Inst()->getMap()) {
        if (it != ESquareType::EMPTY)
            _moves.push_back(Move(idx % Board::Inst()->getSize(), idx / Board::Inst()->getSize()));
        ++idx;
    }
}

void                        MoveManager::clear() {
    this->_moves.clear();
}