//
// Created by levuoj on 11/28/17.
//

#ifndef TYRANNOSAURUS_R_BOARD_HPP
#define TYRANNOSAURUS_R_BOARD_HPP

#include <vector>
#include <cmath>
#include "ESquareType.hpp"

class Board {
private:

    std::vector<ESquareType>    _map;

    int                         _size;

    static Board *              boardInst;

    Board();

public:

    static Board *              Inst();

    ~Board() = default;

    std::vector<ESquareType> const &getMap() const;

    void setSquare(int x, int y, ESquareType);

    void emptySquare(int x, int y);

    void clearMap();

    void displayMap() const;

    bool isEmpty(int x, int y) const;

    ESquareType getSquareType(int x, int y);

    int          getSize() const;
    void          setSize(int);
};


#endif //TYRANNOSAURUS_R_BOARD_HPP
