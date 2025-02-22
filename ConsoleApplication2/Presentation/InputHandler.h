#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Window/Event.hpp>
#include "../Domain/Game.h"

/**
 * \class InputHandler
 * \brief Handles user input for the game.
 *
 * The InputHandler class processes user input events and updates the game state accordingly.
 */
class InputHandler {
public:
    /**
     * \brief Processes user input and updates the game state.
     *
     * This function handles keyboard input events to control the direction of the snake in the game.
     *
     * \param event The SFML Event to handle.
     * \param game The Game object to update based on the input.
     */
    void processInput(sf::Event& event, Game& game);
};

#endif