#include "SoundManager.h"

void SoundManager::playSound(const std::string& filename, sf::SoundBuffer& buffer) {
    if (!buffer.loadFromFile(filename)) {
        // Handle error
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
}

void SoundManager::playSoundLoop(const std::string& filename, sf::SoundBuffer& buffer) {
    if (!buffer.loadFromFile(filename)) {
        // Handle error
    }
    sf::Sound* sound = new sf::Sound();
    sound->setBuffer(buffer);
    sound->setLoop(true);
    sound->play();
}

void SoundManager::loadSound(const std::string& filename, sf::SoundBuffer& buffer) {
    if (!buffer.loadFromFile(filename)) {
        // Handle error
    }
}