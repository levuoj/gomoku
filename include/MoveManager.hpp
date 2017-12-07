//
// Created by pashervz on 05/12/17.
//

#ifndef TYRANNOSAURUS_R_MOVEMANAGER_HPP
#define TYRANNOSAURUS_R_MOVEMANAGER_HPP


#include <vector>
#include "Board.hpp"
#include "Move.hpp"

class MoveManager {
private:
    std::vector<Move>   _moves;
    ESquareType         _playerType;

public:
    MoveManager() = default;
    ~MoveManager() = default;

    std::string const       determineBestMove();
    void                    findMoves();
    void                    clear();
    void                    setPlayerType(ESquareType type) { _playerType = type; }
};


#endif //TYRANNOSAURUS_R_MOVEMANAGER_HPP
