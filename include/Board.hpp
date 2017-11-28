//
// Created by levuoj on 11/28/17.
//

#ifndef TYRANOSAURUS_R_BOARD_HPP
#define TYRANOSAURUS_R_BOARD_HPP

#include <array>
#include "ESquareType.hpp"

class Board {
private:
    //                    19 * 19
    std::array<ESquareType, 361>        _map;
public:
    Board();
    ~Board() = default;

    std::array<ESquareType, 361> const& getMap() const;
    void                                setSquare(int, int, ESquareType);
    void                                clearMap();
    void                                displayMap() const;
};


#endif //TYRANOSAURUS_R_BOARD_HPP
