#include "Core/Core.hpp"

Core::Core() : _window(sf::VideoMode(1920, 1080), "JAM Game", sf::Style::Default) {}

Core::~Core() {
    // destroy & free everything 
}

int Core::startGame()
{
    if (!_backgroundTexture.loadFromFile("./assets/background-game.png"))
        return ERROR;
    _backgroundSprite.setTexture(_backgroundTexture);
    _backgroundSprite.setPosition(-2480.0f, -2730.0f);
    _backgroundSprite.setScale(3.5f, 3.5f);
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
                std::cout << "mousePos.x = " << mousePos.x << ", mousePos.y = " << mousePos.y << std::endl;
                std::cout << "STARTING GAME" << std::endl;
                inGame = true;
            }
        }
    }
    return SUCCESS;
}

int Core::mainGameLoop() 
{
    Menu menu(_window);
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