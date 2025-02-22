#include "FontManager.h"
    #include <iostream>
    
    /**
     * \brief Loads a font from a file.
     *
     * This function attempts to load a font from the specified file and assigns it to the provided sf::Font object.
     * If the font fails to load, an error message is printed to the console.
     *
     * \param filename The path to the font file.
     * \param font The sf::Font object to load the font into.
     * \return true if the font was successfully loaded, false otherwise.
     */
    bool FontManager::loadFont(const std::string& filename, sf::Font& font) {
        if (!font.loadFromFile(filename)) {
            std::cout << "Failed to load font: " << filename << std::endl;
            return false;
        }
        return true;
    }