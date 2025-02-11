// Render.cpp
#include "Render.h"
#include "../Domain/Game.h"
#include <SFML/Graphics.hpp>


void Renderer::renderGame(const Game& game, sf::RenderWindow& window) {
    window.clear();

    // Render the snake
    for (const auto& segment : game.getSnake().getBody()) {
        sf::RectangleShape rectangle(sf::Vector2f(game.getSize() - 2, game.getSize() - 2));
        rectangle.setPosition(segment.x, segment.y);
        rectangle.setFillColor(sf::Color::Green);
        window.draw(rectangle);
    }

    // Render the food
    sf::RectangleShape foodShape(sf::Vector2f(game.getSize(), game.getSize()));
    foodShape.setPosition(game.getFood().x, game.getFood().y);
    foodShape.setFillColor(sf::Color::Red);
    window.draw(foodShape);

    window.display();
}