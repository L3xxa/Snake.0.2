#include "Snake.h"
            
            #include <SFML/Audio/Sound.hpp>
            
            /**
             * \class Snake
             * \brief Represents the snake in the game.
             *
             * The Snake class manages the snake's body, movement, growth, and collision detection.
             */
            
            /**
             * \brief Constructs a new Snake object.
             *
             * Initializes the snake with a starting position.
             *
             * \param startX The starting x-coordinate of the snake's head.
             * \param startY The starting y-coordinate of the snake's head.
             */
            Snake::Snake(int startX, int startY)
            {
                body.push_back(sf::Vector2i(startX, startY));
            }
            
            /**
             * \brief Moves the snake in the specified direction.
             *
             * Updates the position of the snake's head and removes the tail segment.
             *
             * \param dx The change in the x direction.
             * \param dy The change in the y direction.
             */
            void Snake::move(int dx, int dy)
            {
                sf::Vector2i newHead = body.front() + sf::Vector2i(dx, dy); // Create a new head
                body.insert(body.begin(), newHead); // Add the new head
                body.pop_back(); // Remove the tail
            }
            
            /**
             * \brief Grows the snake by adding a new segment to its body.
             *
             * Adds a new segment to the snake's body at the tail position.
             */
            void Snake::grow() {
                if (body.empty()) {
                    return; // If the snake is empty, do nothing
                }
            
                // The last segment (tail)
                sf::Vector2i tail = body.back();
            
                // If the snake has only one segment (head), add a new segment in the opposite direction of movement
                if (body.size() == 1) {
                    // For example, if the snake is moving right, add a new segment to the left of the head
                    body.push_back(tail - sf::Vector2i(Snake::size, 0)); // size - the size of the snake block
                    return;
                }
            
                // If the snake has more than one segment, add a new segment at the end of the tail
                sf::Vector2i beforeTail = body[body.size() - 2];
                sf::Vector2i direction = tail - beforeTail; // Tail direction
                body.push_back(tail + direction);
            }
            
            /**
             * \brief Checks if the snake's head has collided with its own body.
             *
             * \return true if the head has collided with any body segment, false otherwise.
             */
            bool Snake::checkCollision() const {
                const sf::Vector2i& head = body.front(); // Get the head
                for (size_t i = 1; i < body.size(); i++) { // Start from the second segment
                    if (head == body[i]) {
                        return true; // If the head has collided with any body segment
                    }
                }
                return false; // If there are no collisions
            }