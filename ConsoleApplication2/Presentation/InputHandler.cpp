#include "InputHandler.h"
#include "../Domain/Game.h"

void InputHandler::processInput(sf::Event& event, Game& game) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) game.setDirection(0, -1);
        if (event.key.code == sf::Keyboard::Down) game.setDirection(0, 1);
        if (event.key.code == sf::Keyboard::Left) game.setDirection(-1, 0);
        if (event.key.code == sf::Keyboard::Right) game.setDirection(1, 0);
    }
}