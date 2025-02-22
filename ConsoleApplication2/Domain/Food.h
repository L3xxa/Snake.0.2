#ifndef FOOD_H
    #define FOOD_H
    
    #include <vector>
    #include <SFML/System/Vector2.hpp>
    
    /**
     * \class Food
     * \brief Represents the food object in the game.
     *
     * The Food class is responsible for managing the position of the food item in the game.
     * It ensures that the food does not spawn on the snake's body.
     */
    class Food {
    public:
        int x, y;  ///< The x and y coordinates of the food position.
    
        /**
         * \brief Constructs a new Food object.
         *
         * Initializes the random seed for generating food positions.
         */
        Food();
    
        /**
         * \brief Spawns food at a random position on the game grid.
         *
         * This function generates a random position for the food on the game grid, ensuring that it does not overlap with the snake's body.
         *
         * \param width The width of the game area.
         * \param height The height of the game area.
         * \param size The size of each grid cell.
         * \param snakeBody A vector containing the positions of the snake's body segments.
         */
        void spawnFood(int width, int height, int size, const std::vector<sf::Vector2i>& snakeBody);
    };
    
    #endif