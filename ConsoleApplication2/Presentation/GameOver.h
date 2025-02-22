#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <SFML/Graphics.hpp>

/**
 * \class GameOverScreen
 * \brief Manages the display of the game over screen.
 *
 * The GameOverScreen class handles the rendering of the game over message on the screen.
 */
class GameOverScreen {
public:
    /**
     * \brief Displays the game over screen.
     *
     * Loads the font, sets up the game over text, and displays it on the provided window.
     *
     * \param window The SFML RenderWindow to render the game over screen to.
     */
    void show(sf::RenderWindow& window);
};

#endif