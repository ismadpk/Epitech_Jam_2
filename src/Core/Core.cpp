#include "Core/Core.hpp"

Core::Core() : _window(sf::VideoMode(1920, 1080), "JAM Game", sf::Style::Default)
{
    _medalLeft.setPosition({140, 0});
    _window.setFramerateLimit(140);
}

Core::~Core() {
    // destroy & free everything 
}

bool Core::checkColisions(sf::Vector2f firstPos, sf::Vector2f secPos, sf::Vector2u firstSize, sf::Vector2u secSize)
{
    if (firstPos.x < (secPos.x + secSize.x) && (firstPos.x + firstSize.x) > secPos.x
    && firstPos.y < (secPos.y + secSize.y) && (firstPos.y + firstSize.y) > secPos.y) {
        return true;
    }
    return false;
}

int Core::startGame()
{
    if (!_backgroundTexture.loadFromFile("./assets/plain-background.png"))
        return ERROR;
    if (!_groundOnlyTexture.loadFromFile("./assets/ground.png"))
        return ERROR;
    if (!_gameButtonsTexture.loadFromFile("./assets/scaled-buttons.png"))
        return ERROR;
    
    _backgroundSprite.setTexture(_backgroundTexture);
    _backgroundSprite.setScale(0.93f, 0.93f);
    _groundOnlySprite.setTexture(_groundOnlyTexture);
    _groundOnlySprite.setScale(2.55f, 2.55f);
    _groundOnlySprite.setPosition(0.0f, 43.0f);
    _gameButtonsSprite.setTexture(_gameButtonsTexture);
    _gameButtonsSprite.setScale(0.93f, 0.93f);

    _medalLeft.moveMedal(checkColisions(_player.getPosition(), _medalLeft.getPosition(), _player.getSize(), _medalLeft.getSize()));
    _player.handlemove(checkColisions(_player.getPosition(), _medalLeft.getPosition(), _player.getSize(), _medalLeft.getSize()));
    _window.clear(sf::Color::Black);
    _window.draw(_backgroundSprite);
    _window.draw(_groundOnlySprite);
    _window.draw(_player.getSprite());
    _window.draw(_medalLeft.getMedal());
    _window.draw(_gameButtonsSprite);
    return SUCCESS;
}

int Core::handleEvents()
{
    sf::Vector2i mousePos;

    if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
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
            if (mousePos.x >= 80 && mousePos.x <= 375 && mousePos.y >= 35 && mousePos.y <= 100) {
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
        if(_player.getStatusGame() == true) // check if the player is lost
            break;
        _window.display();
    }
    return SUCCESS;
}
