//
// Created by pashervz on 05/12/17.
//

#ifndef TYRANNOSAURUS_R_MOVE_HPP
#define TYRANNOSAURUS_R_MOVE_HPP


#include <vector>

struct Action {
    int                     score;
    std::pair<int, int>     coords;
    Action(int s, std::pair<int, int> pair) : score(s), coords(pair) {}
};

class Move {
private:
    std::vector<Action>         _actions;
    int                         _x;
    int                         _y;

    void                        addAction();
    bool                        checkSquare(int x, int y);
    void                        setScore();
public:
    Move(int x, int y);
    ~Move() = default;

    Action const &            findBestAction();
};

#endif //TYRANNOSAURUS_R_MOVE_HPP
