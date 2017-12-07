//
// Created by pashervz on 05/12/17.
//

#ifndef TYRANNOSAURUS_R_MOVE_HPP
#define TYRANNOSAURUS_R_MOVE_HPP


#include <vector>
#include <map>
#include <include/EScore.hpp>

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
    bool                        SquareExist(int x, int y);
    void                        setScore();

    int                         diagonalNO(std::pair<int, int> const&, ESquareType);
    int                         diagonalNE(std::pair<int, int> const&, ESquareType);
    int                         horizontal(std::pair<int, int> const&, ESquareType);
    int                         vertical(std::pair<int, int> const&, ESquareType);

    std::string const           addToPattern(int x, int y);
    int                         checkPattern(std::string const& pattern, ESquareType type);

private:
    const	std::map<EScore, std::string> BlackScore =
            {
                    {VICTORY, "BBBBB"},
                    {FOUR_TWO, " BBBBB "},
                    {FOUR_ONE_L, " BBBB"},
                    {FOUR_ONE_R, "BBBB "},
                    {THREE_TWO, " BBB "},
                    {THREE_ONE_L, " BBB"},
                    {THREE_ONE_R, "BBB "},
                    {TWO_TWO, " BB "},
                    {TWO_ONE_L, " BB"},
                    {TWO_ONE_R, "BB "}
            };

    const	std::map<EScore, std::string> WhiteScore =
            {
                    {DEFEAT, "WWWWW"},
                    {FOUR_TWO, " WWWWW "},
                    {FOUR_ONE_L, " WWWW"},
                    {FOUR_ONE_R, "WWWW "},
                    {THREE_TWO, " WWW "},
                    {THREE_ONE_L, " WWW"},
                    {THREE_ONE_R, "WWW "},
                    {TWO_TWO, " WW "},
                    {TWO_ONE_L, " WW"},
                    {TWO_ONE_R, "WW "}
            };
public:
    Move(int x, int y);
    ~Move() = default;

    Action const &            findBestAction();
};

#endif //TYRANNOSAURUS_R_MOVE_HPP
