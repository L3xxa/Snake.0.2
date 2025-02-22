#ifndef RENDERER_H
    #define RENDERER_H
    
    #include <SFML/Graphics.hpp>
    #include "../Domain/Game.h"
    
    /**
     * \class Renderer
     * \brief Handles rendering of the game elements.
     *
     * The Renderer class is responsible for drawing the game elements such as the snake and the food on the screen.
     */
    class Renderer {
    public:
        /**
         * \brief Renders the game state to the window.
         *
         * Clears the window, renders the snake and the food, and then displays the updated window.
         *
         * \param game The Game object containing the current state of the game.
         * \param window The SFML RenderWindow to render the game to.
         */
        void renderGame(const Game& game, sf::RenderWindow& window);
        
    };
    
    #endif