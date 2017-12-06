//
// Created by levuoj on 11/28/17.
//

#ifndef TYRANNOSAURUS_R_BOARD_HPP
#define TYRANNOSAURUS_R_BOARD_HPP

#include <array>
#include <cmath>
#include "ESquareType.hpp"

class Board {
private:
    static const int              SQRTDIM;

    std::array<ESquareType, 361> _map;

    static Board *              boardInst;

    Board();

public:

    static Board *               Inst();

    ~Board() = default;

    std::array<ESquareType, 361> const &getMap() const;

    void setSquare(int x, int y, ESquareType);

    void emptySquare(int x, int y);

    void clearMap();

    void displayMap() const;

    bool isEmpty(int x, int y) const;
};


#endif //TYRANNOSAURUS_R_BOARD_HPP
