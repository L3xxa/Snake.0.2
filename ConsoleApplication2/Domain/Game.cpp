// Game.cpp
    #include "Game.h"
    #include "Food.h"
    #include "../Presentation/Render.h"
    #include <SFML/Graphics.hpp>
    
    /**
     * \class Game
     * \brief Manages the game logic and state.
     *
     * The Game class handles the main game loop, including updating the game state, handling collisions, and rendering the game.
     */
    
    /**
     * \brief Constructs a new Game object.
     *
     * Initializes the game with the specified width, height, and grid size. Loads the necessary sounds and spawns the initial food.
     *
     * \param width The width of the game area.
     * \param height The height of the game area.
     * \param size The size of each grid cell.
     */
    Game::Game(int width, int height, int size)
        : width(width), height(height), size(size), snake(width / 2, height / 2),
          directionX(1), directionY(0), gameOver(false) {
    
        soundManager.loadSound("assets/eating.wav", eatBuffer);
        soundManager.loadSound("assets/game_over.wav", gameOverBuffer);
        soundManager.loadSound("assets/collision.wav", collisionBuffer);
        
    
        eatSound.setBuffer(eatBuffer);
        gameOverSound.setBuffer(gameOverBuffer);
    
        food.spawnFood(width, height, size, snake.getBody());
    }
    
    /**
     * \brief Updates the game state.
     *
     * Moves the snake, checks for collisions with food, screen boundaries, and the snake's body. Plays appropriate sounds and sets the game over state if necessary.
     */
    void Game::update() {
        if (gameOver) return;
    
        // Рухаємо змійку
        snake.move(directionX * size, directionY * size);
    
        // Перевіряємо, чи змійка з'їла фрукт
        if (snake.getBody().front().x == food.x && snake.getBody().front().y == food.y) {
            snake.grow(); // Змійка росте
            eatSound.play();
            food.spawnFood(width, height, size, snake.getBody()); // Новий фрукт не повинен з'являтися на тілі змійки
        }
    
        // Перевіряємо колізію з межами екрану
        if (snake.getBody().front().x < 0 || snake.getBody().front().y < 0 ||
            snake.getBody().front().x >= width || snake.getBody().front().y >= height) {
            gameOver = true;
            
            gameOverSound.play();
            collisionSound.play();
            }
    
        // Перевіряємо колізію з тілом змійки
        if (snake.checkCollision()) {
            gameOver = true;
            
            gameOverSound.play();
            collisionSound.play();
        }
    }
    
    /**
     * \brief Sets the direction of the snake's movement.
     *
     * \param dx The change in the x direction.
     * \param dy The change in the y direction.
     */
    void Game::setDirection(int dx, int dy) {
        directionX = dx;
        directionY = dy;
    }
    
    /**
     * \brief Checks if the game is over.
     *
     * \return true if the game is over, false otherwise.
     */
    bool Game::isGameOver() const {
        return gameOver;
    }
    
    /**
     * \brief Renders the game.
     *
     * Uses the Renderer class to render the game state to the provided window.
     *
     * \param window The SFML RenderWindow to render the game to.
     */
    void Game::render(sf::RenderWindow& window) const {
        Renderer renderer;
        renderer.renderGame(*this, window);
    }
    
    /**
     * \brief Gets the food object.
     *
     * \return A constant reference to the Food object.
     */
    const Food& Game::getFood() const {  
        return food;  
    }
    
    /**
     * \brief Gets the size of each grid cell.
     *
     * \return The size of each grid cell.
     */
    int Game::getSize() const {  
        return size;  
    }
    
    /**
     * \brief Gets the snake object.
     *
     * \return A constant reference to the Snake object.
     */
    const Snake& Game::getSnake() const {  
        return snake;
    }