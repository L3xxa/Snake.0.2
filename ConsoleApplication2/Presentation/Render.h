#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "../Domain/Game.h"

class Renderer {
public:
    void renderGame(const Game& game, sf::RenderWindow& window);
};

#endif