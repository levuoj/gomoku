//
// Created by pashervz on 29/11/17.
//

#include <vector>
#include "ProtocolManager.hpp"

void ProtocolManager::receive(Event const & event) {
    std::cout << "Protocol Manager : I received an Event : " << event.datas.at(0) << std::endl;
}

void ProtocolManager::readInfos() {
    std::vector<std::string>        infos;
    std::string                     info;

    std::getline(std::cin, info);
    infos.push_back(info);
    if (info.find("BOARD") != std::string::npos) {
        while (true) {
            std::getline(std::cin, info);
            if (info == "DONE")
                break;
            infos.push_back(info);
        }
    }
    makeEvent(infos);
}

void ProtocolManager::makeEvent(std::vector<std::string> const & infos) {
    for (auto const & it : _eventMap) {
        if (infos.at(0).find(it.first) != std::string::npos) {
            Event           event;

            event.datas = infos;
            _mediator.transmit(event);
            break;
        }
    }
}