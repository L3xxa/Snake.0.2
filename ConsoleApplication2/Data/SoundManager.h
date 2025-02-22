#ifndef SOUNDMANAGER_H
    #define SOUNDMANAGER_H
    
    #include <SFML/Audio.hpp>
    #include <string>
    
    /**
     * \class SoundManager
     * \brief Manages the loading and playing of sounds for the game.
     *
     * The SoundManager class provides methods to play sounds, play sounds in a loop, and load sounds from files.
     */
    class SoundManager {
    public:
        /**
         * \brief Plays a sound from a file.
         *
         * This function loads a sound file into the provided sf::SoundBuffer and plays it.
         * If the file fails to load, an error is handled.
         *
         * \param filename The path to the sound file.
         * \param buffer The sf::SoundBuffer object to load the sound into.
         */
        void playSound(const std::string& filename, sf::SoundBuffer& buffer);
    
        /**
         * \brief Plays a sound from a file in a loop.
         *
         * This function loads a sound file into the provided sf::SoundBuffer, sets it to loop, and plays it.
         * If the file fails to load, an error is handled.
         *
         * \param filename The path to the sound file.
         * \param buffer The sf::SoundBuffer object to load the sound into.
         */
        void playSoundLoop(const std::string& filename, sf::SoundBuffer& buffer);
    
        /**
         * \brief Loads a sound from a file.
         *
         * This function loads a sound file into the provided sf::SoundBuffer.
         * If the file fails to load, an error is handled.
         *
         * \param filename The path to the sound file.
         * \param buffer The sf::SoundBuffer object to load the sound into.
         */
        void loadSound(const std::string& filename, sf::SoundBuffer& buffer);
    };
    
    #endif