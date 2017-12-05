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
    Board               _board;
    std::vector<Move>   _moves;

public:
    MoveManager() = default;
    ~MoveManager() = default;

    Move            determineBestMove() const;
    void            findMoves() const;
    void            setBoard(Board const & board) { _board = board; }
};


#endif //TYRANNOSAURUS_R_MOVEMANAGER_HPP
