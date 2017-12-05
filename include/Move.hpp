//
// Created by pashervz on 05/12/17.
//

#ifndef TYRANNOSAURUS_R_MOVE_HPP
#define TYRANNOSAURUS_R_MOVE_HPP


#include <vector>

struct Action {
    int                     score;
    std::pair<int, int>     coords;
};

class Move {
private:
    std::vector<Action>        _actions;

public:
    Move() = default;
    ~Move() = default;

    Action const &             findBestAction();
};


#endif //TYRANNOSAURUS_R_MOVE_HPP
