#include "SoundManager.h"
#include <iostream>

bool SoundManager::loadSound(const std::string& filename, sf::SoundBuffer& buffer) {
    if (!buffer.loadFromFile(filename)) {
        std::cout << "Failed to load sound: " << filename << std::endl;
        return false;
    }
    return true;
}

void SoundManager::playSound(sf::Sound& sound) {
    sound.play();
}
