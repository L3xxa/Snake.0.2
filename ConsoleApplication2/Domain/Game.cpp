#include "Game.h"
#include "Food.h"
#include "../Presentation/Render.h"
#include <SFML/Graphics.hpp>

Game::Game(int width, int height, int size)
    : width(width), height(height), size(size), snake(width / 2, height / 2),
      directionX(1), directionY(0), gameOver(false) {

    soundManager.loadSound("assets/Eat.wav", eatBuffer);
    soundManager.loadSound("assets/Game-Over.wav", gameOverBuffer);

    eatSound.setBuffer(eatBuffer);
    gameOverSound.setBuffer(gameOverBuffer);

    food.spawnFood(width, height, size);
}


void Game::update() {
    if (gameOver) return;

    // Переміщення змії, отримуємо напрямок через методи getDirectionX та getDirectionY
    snake.move(directionX * size, directionY * size);

    if (snake.getBody().front().x == food.x && snake.getBody().front().y == food.y) {
        snake.grow();
        eatSound.play();
        food.spawnFood(width, height, size);
    }

    // Перевірка на зіткнення з межами
    if (snake.getBody().front().x < 0 || snake.getBody().front().y < 0 ||
        snake.getBody().front().x >= width || snake.getBody().front().y >= height) {
        gameOver = true;
        gameOverSound.play();
        }
}

void Game::setDirection(int dx, int dy) {
    directionX = dx;
    directionY = dy;
}

void Game::getDirection(int& dx, int& dy) const {
    dx = directionX;
    dy = directionY;
}

bool Game::isGameOver() const {
    return gameOver;
}

void Game::render(sf::RenderWindow& window) const {
    Renderer renderer;
    renderer.renderGame(*this, window);
}
