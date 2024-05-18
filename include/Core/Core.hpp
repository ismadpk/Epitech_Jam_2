
#ifndef CORE_HPP_
    #define CORE_HPP_
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #define ERROR 84;
    #define SUCCESS 0;

class Core {
    public:
        Core();
        ~Core();
        int mainGameLoop();
        int handleMenu();
        int handleEvents();
        int startGame();

    private:
        sf::RenderWindow _window;
        sf::Texture _menuTexture;
        sf::Sprite _menuSprite;
        sf::Texture _backgroundTexture;
        sf::Sprite _backgroundSprite;
        sf::Event _event;
        bool inGame = false;
};

#endif /* !CORE_HPP_ */
