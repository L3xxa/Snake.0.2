#include "FontManager.h"
#include <iostream>

bool FontManager::loadFont(const std::string& filename, sf::Font& font) {
    if (!font.loadFromFile(filename)) {
        std::cout << "Failed to load font: " << filename << std::endl;
        return false;
    }
    return true;
}
