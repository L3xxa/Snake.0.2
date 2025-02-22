// Render.cpp
    #include "Render.h"
    #include "../Domain/Game.h"
    #include <SFML/Graphics.hpp>
    
    /**
     * \class Renderer
     * \brief Handles rendering of the game elements.
     *
     * The Renderer class is responsible for drawing the game elements such as the snake and the food on the screen.
     */
    
    /**
     * \brief Renders the game state to the window.
     *
     * Clears the window, renders the snake and the food, and then displays the updated window.
     *
     * \param game The Game object containing the current state of the game.
     * \param window The SFML RenderWindow to render the game to.
     */
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