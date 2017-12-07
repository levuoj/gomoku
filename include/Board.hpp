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

    std::array<ESquareType, 361> _map;

    static Board *              boardInst;

    Board();

public:
    static const int              SQRTDIM;

    static Board *               Inst();

    ~Board() = default;

    std::array<ESquareType, 361> const &getMap() const;

    void setSquare(int x, int y, ESquareType);

    void emptySquare(int x, int y);

    void clearMap();

    void displayMap() const;

    bool isEmpty(int x, int y) const;

    ESquareType getSquareType(int x, int y);
};


#endif //TYRANNOSAURUS_R_BOARD_HPP
