#include "Parallax/Parallax.hpp"
#include "Core/Core.hpp"

Core::Core() : _window(sf::VideoMode(1920, 1080), "JAM Game", sf::Style::Default)
{
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
    _window.clear(sf::Color::Black);
    _medalLeft.moveMedal(checkColisions(_player.getPosition(), _medalLeft.getPosition(), _player.getSize(), _medalLeft.getSize()));
    _player.handlemove(checkColisions(_player.getPosition(), _medalLeft.getPosition(), _player.getSize(), _medalLeft.getSize()), _medalLeft.getStatus());
    _parallax.renderParallax(_window);
    _window.draw(_player.getSprite());
    _window.draw(_medalLeft.getMedal());
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
        if (inGame) {
            startGame();
        } else {
            menu.handleMenu();
        }
        if(_player.getStatusGame() == true) // check if the player is lost
            break;
        _window.display();
    }
    return SUCCESS;
}
