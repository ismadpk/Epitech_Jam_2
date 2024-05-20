#include "Parallax/Parallax.hpp"
#include "Core/Core.hpp"
#include "unistd.h"

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
    _player.handleScoreText();
    _parallax.renderParallax(_window);
    _window.draw(_player.getSprite());
    _window.draw(_medalLeft.getMedal());
    _window.draw(_player.getScoreText());
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

int Core::handleLose()
{
    sf::Texture loseTexture;
    sf::Sprite loseSprite;

    if (!loseTexture.loadFromFile("assets/loseSprite.png")) {
        std::cerr << "Error : lose sprite failed" << std::endl;
        return 1;
    }
    loseSprite.setPosition(720, 350);
    loseSprite.setTexture(loseTexture);
    
    while (_window.isOpen()) {
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                _window.close();
            if (_event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                    return 0;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    return 1;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    return 1;
            }
        }
        this->_window.draw(loseSprite);
        this->_window.display();
    }
    return 0;
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
        if (_player.getStatusGame() == true) {
            if (this->handleLose() == 1) {
                this->_window.clear();
                this->inGame = false;
            }
            this->_player.setScore(0);
            this->_player.setLoss(false);
        }
        _window.display();
    }
    return SUCCESS;
}
