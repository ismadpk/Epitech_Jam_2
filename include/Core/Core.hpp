
#ifndef CORE_HPP_
    #define CORE_HPP_
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include "Menu/Menu.hpp"
    #include "Player/Player.hpp"
    #define ERROR 84;
    #define SUCCESS 0;

class Core {
    public:
        Core();
        ~Core();
        int mainGameLoop();
        int handleEvents();
        int startGame();

    private:
        sf::RenderWindow _window;
        sf::Texture _backgroundTexture;
        sf::Sprite _backgroundSprite;
        sf::Texture _groundOnlyTexture;
        sf::Sprite _groundOnlySprite;
        sf::Texture _gameButtonsTexture;
        sf::Sprite _gameButtonsSprite;
        sf::Event _event;
        bool inGame = false;
        Player _player;
};

#endif /* !CORE_HPP_ */
