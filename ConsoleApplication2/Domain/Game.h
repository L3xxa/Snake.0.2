#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include "../Data/SoundManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

/**
 * \class Game
 * \brief Manages the game logic and state.
 *
 * The Game class handles the main game loop, including updating the game state, handling collisions, rendering the game, and processing input.
 */
class Game {
public:
    /**
     * \brief Constructs a new Game object.
     *
     * Initializes the game with the specified width, height, and grid size. Loads the necessary sounds and spawns the initial food.
     *
     * \param width The width of the game area.
     * \param height The height of the game area.
     * \param size The size of each grid cell.
     */
    Game(int width, int height, int size);

    /**
     * \brief Updates the game state.
     *
     * Moves the snake, checks for collisions with food, screen boundaries, and the snake's body. Plays appropriate sounds and sets the game over state if necessary.
     */
    void update();

    /**
     * \brief Renders the game.
     *
     * Uses the Renderer class to render the game state to the provided window.
     *
     * \param window The SFML RenderWindow to render the game to.
     */
    void render(sf::RenderWindow& window) const;

    /**
     * \brief Checks if the game is over.
     *
     * \return true if the game is over, false otherwise.
     */
    bool isGameOver() const;

    /**
     * \brief Handles user input.
     *
     * Processes the input events to control the game, such as changing the snake's direction.
     *
     * \param event The SFML Event to handle.
     */
    void handleInput(sf::Event& event);

    /**
     * \brief Sets the direction of the snake's movement.
     *
     * \param dx The change in the x direction.
     * \param dy The change in the y direction.
     */
    void setDirection(int dx, int dy);

    /**
     * \brief Gets the snake object.
     *
     * \return A constant reference to the Snake object.
     */
    const Snake& getSnake() const;

    /**
     * \brief Gets the food object.
     *
     * \return A constant reference to the Food object.
     */
    const Food& getFood() const;

    /**
     * \brief Gets the size of each grid cell.
     *
     * \return The size of each grid cell.
     */
    int getSize() const;

    /**
     * \brief Gets the direction of the snake's movement in the x direction.
     *
     * \return The change in the x direction.
     */
    int getDirectionX() const { return directionX; }

    /**
     * \brief Gets the direction of the snake's movement in the y direction.
     *
     * \return The change in the y direction.
     */
    int getDirectionY() const { return directionY; }

private:
    int width, height, size; ///< The dimensions of the game area and the size of each grid cell.
    Snake snake; ///< The snake object representing the player's snake.
    Food food; ///< The food object representing the food in the game.
    bool gameOver; ///< The game over state.
    int directionX, directionY; ///< The direction of the snake's movement.
    SoundManager soundManager; ///< The sound manager for handling game sounds.
    sf::SoundBuffer eatBuffer, gameOverBuffer, collisionBuffer; ///< Sound buffers for different game sounds.
    sf::Sound eatSound, gameOverSound, collisionSound; ///< Sound objects for playing game sounds.
};

#endif