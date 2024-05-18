#ifndef MENU_HPP_
    #define MENU_HPP_
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #define ERROR 84;
    #define SUCCESS 0;

class Menu {
    public:
        Menu() = default;
        Menu(sf::RenderWindow& window, sf::Event& event);
        ~Menu() = default;
        int handleMenu();

    private:
        sf::RenderWindow& _window;
        sf::Texture _menuTexture;
        sf::Sprite _menuSprite;
        sf::Event& _event;
};

#endif /* !MENU_HPP_ */
