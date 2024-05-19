
#include "Menu/Menu.hpp"

Menu::Menu(sf::RenderWindow& window, sf::Event& event) : _window(window), _event(event)
{
    if (!_menuTexture.loadFromFile("./assets/menu.png")) {
        std::cerr << "Failed to load texture" << std::endl;
    } else {
        _menuSprite.setTexture(_menuTexture);
        _menuSprite.setScale(1.0f, 1.0f);
    }
}


int Menu::handleMenu()
{
    _window.clear(sf::Color::Black);
    _window.draw(_menuSprite);
    return SUCCESS;
}