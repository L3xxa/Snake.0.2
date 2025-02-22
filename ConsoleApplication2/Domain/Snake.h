#ifndef SNAKE_H
    #define SNAKE_H
    
    #include <vector>
    #include <SFML/Graphics.hpp>
    
    /**
     * \class Snake
     * \brief Represents the snake in the game.
     *
     * The Snake class manages the snake's body, movement, growth, and collision detection.
     */
    class Snake
    {
    private:
        std::vector<sf::Vector2i> body; ///< The body segments of the snake.
    public:
    
        static const int size = 20; ///< The size of each snake block.
    
        /**
         * \brief Constructs a new Snake object.
         *
         * Initializes the snake with a starting position.
         *
         * \param startX The starting x-coordinate of the snake's head.
         * \param startY The starting y-coordinate of the snake's head.
         */
        Snake (int startX, int startY);
    
        /**
         * \brief Moves the snake in the specified direction.
         *
         * Updates the position of the snake's head and removes the tail segment.
         *
         * \param dx The change in the x direction.
         * \param dy The change in the y direction.
         */
        void move(int dx, int dy);
    
        /**
         * \brief Grows the snake by adding a new segment to its body.
         *
         * Adds a new segment to the snake's body at the tail position.
         */
        void grow();
    
        /**
         * \brief Checks if the snake's head has collided with its own body.
         *
         * \return true if the head has collided with any body segment, false otherwise.
         */
        bool checkCollision() const;
    
        /**
         * \brief Gets the body segments of the snake.
         *
         * \return A constant reference to the vector of body segments.
         */
        const std::vector<sf::Vector2i>& getBody() const { return body; }
    };
    
    #endif // SNAKE_H