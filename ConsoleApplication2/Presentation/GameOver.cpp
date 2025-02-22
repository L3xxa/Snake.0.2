#include "GameOver.h"
    #include "../Data/FontManager.h"
    #include <iostream>
    
    /**
     * \class GameOverScreen
     * \brief Manages the display of the game over screen.
     *
     * The GameOverScreen class handles the rendering of the game over message on the screen.
     */
    
    /**
     * \brief Displays the game over screen.
     *
     * Loads the font, sets up the game over text, and displays it on the provided window.
     *
     * \param window The SFML RenderWindow to render the game over screen to.
     */
    void GameOverScreen::show(sf::RenderWindow& window) {
        sf::Font font;
        FontManager fontManager;
        
        // Завантаження шрифта
        if (!fontManager.loadFont("assets/BRITANIC.TTF", font)) {
            std::cout << "Failed to load font!" << std::endl;
            return;
        }
    
        // Текст, який відображатиметься на екрані
        sf::Text text("Game Over", font, 50);
        text.setPosition(250, 250); // Позиція тексту на екрані
        text.setFillColor(sf::Color::Red); // Колір тексту
    
        // Очистка екрану, малювання тексту та відображення
        window.clear();
        window.draw(text);
        window.display();
    
        // Пауза на 2 секунди
        sf::sleep(sf::seconds(2));
    }