
#include "GameOver.h"
#include "../Data/FontManager.h"
#include <iostream>

void GameOverScreen::show(sf::RenderWindow& window) {
    sf::Font font;
    FontManager fontManager;
    if (!fontManager.loadFont("assets/BRITANIC.TTF", font)) {
        std::cout << "Failed to load font!" << std::endl;
        return;
    }

    sf::Text text("Game Over", font, 50);
    text.setPosition(250, 250);
    text.setFillColor(sf::Color::Red);

    window.clear();
    window.draw(text);
    window.display();

    sf::sleep(sf::seconds(2));
};