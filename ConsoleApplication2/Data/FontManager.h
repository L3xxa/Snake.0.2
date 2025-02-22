#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>

/**
 * \class FontManager
 * \brief Manages the loading of fonts for the game.
 *
 * The FontManager class provides a method to load fonts from files and handle any errors that occur during the loading process.
 */
class FontManager {
public:
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
    bool loadFont(const std::string& filename, sf::Font& font);
};

#endif