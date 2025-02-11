
#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include "../Data/SoundManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game {
public:
    Game(int width, int height, int size);
    void update();
    void render(sf::RenderWindow& window) const;
    bool isGameOver() const;
    void handleInput(sf::Event& event);
    void setDirection(int dx, int dy);

    const Snake& getSnake() const { return snake; }
    const Food& getFood() const { return food; }
    int getSize() const { return size; }

private:
    int width, height, size;
    Snake snake;
    Food food;
    bool gameOver;
    int directionX, directionY;
    SoundManager soundManager;
    sf::SoundBuffer eatBuffer, gameOverBuffer;
    sf::Sound eatSound, gameOverSound;
};

#endif

