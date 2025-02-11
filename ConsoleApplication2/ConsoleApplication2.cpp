#include <SFML/Graphics.hpp>
#include "Domain/Game.h"
#include "Presentation/Render.h"
#include "Presentation/InputHandler.h"
#include "Presentation/GameOver.h"
#include "Data/SoundManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");

    Game game(800, 600, 20);
    Renderer renderer;
    InputHandler inputHandler;
    GameOverScreen gameOverScreen;
    SoundManager soundManager;

    sf::SoundBuffer startBuffer;
    sf::Sound startSound;

    soundManager.loadSound("assets/Start.wav", startBuffer);
    startSound.setBuffer(startBuffer);
    startSound.play();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            inputHandler.processInput(event, game);
        }

        game.update();
        renderer.renderGame(game, window);

        if (game.isGameOver()) {
            gameOverScreen.show(window);
            break;
        }

        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
