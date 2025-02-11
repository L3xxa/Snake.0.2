#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Window/Event.hpp>
#include "../Domain/Game.h"

class InputHandler {
public:
    void processInput(sf::Event& event, Game& game);
};

#endif