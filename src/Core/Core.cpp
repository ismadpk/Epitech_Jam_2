#include "Core/Core.hpp"

Core::Core() : _window(sf::VideoMode(1920, 1080), "JAM Game", sf::Style::Default) {}

Core::~Core() {
    // destroy & free everything 
}

int Core::handleMenu()
{
    if (!_menuTexture.loadFromFile("./assets/menu.png"))
        return ERROR;
    _menuSprite.setTexture(_menuTexture);
    _menuSprite.setScale(0.93f, 0.93f);
    _window.clear(sf::Color::Black);
    _window.draw(_menuSprite);
    return SUCCESS;
}

int Core::startGame()
{
    return (0);
}

int Core::handleEvents()
{
    sf::Vector2i mousePos;

    if (_event.type == sf::Event::Closed)
        _window.close();
    if (_event.type == sf::Event::MouseButtonPressed) {
        if (_event.mouseButton.button == sf::Mouse::Left) {
            mousePos = sf::Mouse::getPosition(_window);
            if (mousePos.x >= 960 && mousePos.x <= 1355 && mousePos.y >= 735 && mousePos.y <= 910) {
                std::cout << "mousePos.x = " << mousePos.x << ", mousePos.y = " << mousePos.y << std::endl;
                std::cout << "STARTING GAME" << std::endl;
                startGame();
            }
        }
    }
    return SUCCESS;
}

int Core::mainGameLoop() 
{
    while (_window.isOpen()) {
        while (_window.pollEvent(_event)) {
            handleEvents();
        }
        _window.clear(sf::Color::Black);
        handleMenu();
        _window.display();
    }
    return SUCCESS;
}