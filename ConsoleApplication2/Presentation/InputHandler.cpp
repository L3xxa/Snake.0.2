#include "InputHandler.h"
            
            /**
             * \brief Processes user input and updates the game state accordingly.
             *
             * This function handles keyboard input events to control the direction of the snake in the game.
             *
             * \param event The SFML Event to handle.
             * \param game The Game object to update based on the input.
             */
            void InputHandler::processInput(sf::Event& event, Game& game)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    int currentX = game.getDirectionX();
                    int currentY = game.getDirectionY();
            
                    if (event.key.code == sf::Keyboard::Up && currentY == 0) 
                        game.setDirection(0, -1);
                    if (event.key.code == sf::Keyboard::Down && currentY == 0) 
                        game.setDirection(0, 1);
                    if (event.key.code == sf::Keyboard::Left && currentX == 0) 
                        game.setDirection(-1, 0);
                    if (event.key.code == sf::Keyboard::Right && currentX == 0) 
                        game.setDirection(1, 0);
                }
            }