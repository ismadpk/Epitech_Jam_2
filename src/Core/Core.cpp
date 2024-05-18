#include "Core/Core.hpp"

Core::Core() : _window(sf::VideoMode(1920, 1080), "JAM Game", sf::Style::Default) {}

Core::~Core() {
    // destroy & free everything 
}

int Core::startGame()
{
    if (!_backgroundTexture.loadFromFile("./assets/side-background.png"))
        return ERROR;
    _backgroundSprite.setTexture(_backgroundTexture);
    _backgroundSprite.setScale(0.93f, 0.93f);
    _window.clear(sf::Color::Black);
    _window.draw(_backgroundSprite);
    return SUCCESS;
}

int Core::handleEvents()
{
    sf::Vector2i mousePos;

    if (_event.type == sf::Event::Closed)
        _window.close();
    if (_event.type == sf::Event::MouseButtonPressed && inGame == false) {
        if (_event.mouseButton.button == sf::Mouse::Left) {
            mousePos = sf::Mouse::getPosition(_window);
            if (mousePos.x >= 960 && mousePos.x <= 1355 && mousePos.y >= 735 && mousePos.y <= 910) {
                inGame = true;
            }
        }
    }
    if (_event.type == sf::Event::MouseButtonPressed && inGame == true) {
        if (_event.mouseButton.button == sf::Mouse::Left) {
            mousePos = sf::Mouse::getPosition(_window);
            //std::cout << "mousePos.x = " << mousePos.x << ", mousePos.y = " << mousePos.y << std::endl;
            if (mousePos.x >= 80 && mousePos.x <= 375 && mousePos.y >= 35 && mousePos.y <= 100) {
                //std::cout << "BACK TO MENU" << std::endl;
                inGame = false;
            }
        }
    }
    return SUCCESS;
}

int Core::mainGameLoop() 
{
    Menu menu(_window, _event);
    while (_window.isOpen()) {
        while (_window.pollEvent(_event)) {
            handleEvents();
        }
        _window.clear(sf::Color::Black);
        menu.handleMenu();
        if (inGame == true)
            startGame();
        _window.display();
    }
    return SUCCESS;
}