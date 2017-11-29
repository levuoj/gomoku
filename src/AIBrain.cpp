//
// Created by pashervz on 29/11/17.
//

#include <iostream>
#include "AIBrain.hpp"

void AIBrain::receive(Event const &event) {
    std::cout << "AIBrain : I received an event : " << event.datas.at(0) << std::endl;
}