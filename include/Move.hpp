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
    ESquareType                 _type;

    void                        addAction();
    bool                        checkSquare(int x, int y);
    void                        setScore();

    int                         diagonalNO(std::pair<int, int> const&);
    int                         diagonalNE(std::pair<int, int> const&);
    int                         horizontal(std::pair<int, int> const&);
    int                         vertical(std::pair<int, int> const&);
public:
    Move(int x, int y, ESquareType t);
    ~Move() = default;

    Action const &            findBestAction();
};

#endif //TYRANNOSAURUS_R_MOVE_HPP
