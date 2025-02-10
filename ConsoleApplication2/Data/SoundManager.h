#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include <string>

class SoundManager {
public:
    bool loadSound(const std::string& filename, sf::SoundBuffer& buffer);
    void playSound(sf::Sound& sound);
};

#endif