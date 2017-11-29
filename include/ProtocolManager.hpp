//
// Created by pashervz on 29/11/17.
//

#ifndef TYRANOSAURUS_R_PROTOCOLMANAGER_HPP
#define TYRANOSAURUS_R_PROTOCOLMANAGER_HPP

#include <unordered_map>
#include "AManager.hpp"

class ProtocolManager : public AManager {
private:
    std::unordered_map<std::string, EventType>      _eventMap {
            { "BEGIN", EventType::BEGIN },
            { "BOARD", EventType::BOARD },
            { "INFO", EventType::INFO },
            { "START", EventType::START },
            { "TURN", EventType::TURN },
            { "END", EventType::END },
            { "ABOUT", EventType::ABOUT }
    };
public:
    explicit ProtocolManager(Mediator &mediator) : AManager(mediator) {}

    virtual ~ProtocolManager() final = default;

    void receive(Event const &);

    void readInfos();

    void makeEvent(std::vector<std::string> const &);
};


#endif //TYRANOSAURUS_R_PROTOCOLMANAGER_HPP
