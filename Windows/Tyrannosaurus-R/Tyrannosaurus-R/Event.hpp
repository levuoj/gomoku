//
// Created by pashervz on 29/11/17.
//

#ifndef TYRANNOSAURUS_R_EVENT_HPP
#define TYRANNOSAURUS_R_EVENT_HPP

#include <iostream>
#include <vector>

enum EventType {
    // FOR THE BRAIN : MANDATORY
    START = 0,
    TURN = 1,
    BEGIN = 2,
    BOARD = 3,
    INFO = 4,
    END = 5,
    ABOUT = 6,

    // FOR THE PROTOCOL MANAGER

    WRITE = 7
};

struct Event {
    EventType                    type;
    std::vector<std::string>     datas;
};

#endif //TYRANNOSAURUS_R_EVENT_HPP