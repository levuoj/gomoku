//
// Created by pashervz on 29/11/17.
//

#ifndef TYRANOSAURUS_R_EVENT_HPP
#define TYRANOSAURUS_R_EVENT_HPP

#include <iostream>
#include <vector>

enum EventType {
    //MANDATORY
    START,
    TURN,
    BEGIN,
    BOARD,
    INFO,
    END,
    ABOUT
};

struct Event {
    EventType                    type;
    std::vector<std::string>     datas;
};

#endif //TYRANOSAURUS_R_EVENT_HPP