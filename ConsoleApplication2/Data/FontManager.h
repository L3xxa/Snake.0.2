#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>

class FontManager {
public:
    bool loadFont(const std::string& filename, sf::Font& font);
};

#endif