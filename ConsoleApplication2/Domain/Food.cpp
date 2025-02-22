#include "Food.h"
                #include <cstdlib>
                #include <ctime>
                
                /**
                 * \class Food
                 * \brief Represents the food object in the game.
                 *
                 * The Food class is responsible for managing the position of the food item in the game.
                 * It ensures that the food does not spawn on the snake's body.
                 */
                Food::Food() {
                    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // Initialize random seed
                }
                
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
                void Food::spawnFood(int width, int height, int size, const std::vector<sf::Vector2i>& snakeBody) {
                    bool validPosition = false;
                
                    while (!validPosition) {
                        x = (std::rand() % (width / size)) * size;
                        y = (std::rand() % (height / size)) * size;
                        validPosition = true;
                
                        for (const auto& segment : snakeBody) {
                            if (segment.x == x && segment.y == y) {
                                validPosition = false;
                                break;
                            }
                        }
                    }
                }