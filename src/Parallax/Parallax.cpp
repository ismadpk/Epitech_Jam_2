/*
** EPITECH PROJECT, 2024
** Parallax.cpp
** File description:
** Parallax
*/

#include "Parallax/Parallax.hpp"

Parallax::Parallax()
{
    initAssets();
}

void Parallax::initAssets(void)
{
    if (!_backgroundTexture.loadFromFile("./assets/sky.png")) {
        std::cerr << "Failed to load texture: sky.png" << std::endl;
    }
    if (!_midgroundTexture.loadFromFile("./assets/flag.png")) {
        std::cerr << "Failed to load texture: flag.png" << std::endl;
    }
    if (!_foregroundTexture.loadFromFile("./assets/ground.png")) {
        std::cerr << "Failed to load texture: ground.png" << std::endl;
    }
    if (!_buttonsTexture.loadFromFile("./assets/buttons.png")) {
        std::cerr << "Failed to load texture: buttons.png" << std::endl;
    }

    _background.setTexture(_backgroundTexture);
    _background.setScale(1.0f, 1.0f);
    _background.setPosition(0.0f, 0.0f);

    _midground.setTexture(_midgroundTexture);
    _midground.setScale(1.0f, 1.0f);
    _midground.setPosition(0.0f, 0.0f);

    _foreground.setTexture(_foregroundTexture);
    _foreground.setScale(1.1f, 0.94f);
    _foreground.setPosition(0.0f, 0.0f);

    _buttons.setTexture(_buttonsTexture);
    _buttons.setScale(1.0f, 1.0f);
    _buttons.setPosition(0.0f, 0.0f);
}

void Parallax:: checkParallaxSpritePos(void)
{
    if (_background.getPosition().x <= 0)
        _background.setPosition((sf::Vector2f){1920, 0.0});
    if (_midground.getPosition().x <= 0)
        _midground.setPosition((sf::Vector2f){1920, 0.0});
    if (_foreground.getPosition().x <= 0)
        _foreground.setPosition((sf::Vector2f){1920, 0.0});
}

void Parallax:: moveParallaxSprite(float deltaTime)
{
    _background.move((sf::Vector2f){-150.0f * deltaTime, 0});
    _midground.move((sf::Vector2f){-160.0f * deltaTime, 0});
    _foreground.move((sf::Vector2f){-400.0f * deltaTime, 0});
}

static void drawMoveLayers(sf::RenderWindow& window, sf::Sprite& sprite)
{
    window.draw(sprite);
    sprite.move((sf::Vector2f){-1920, 0});

    window.draw(sprite);
    sprite.move((sf::Vector2f){1920, 0});
}

void Parallax:: renderParallax(sf::RenderWindow& window)
{
    float deltaTime = _clock.restart().asSeconds();
    checkParallaxSpritePos();
    moveParallaxSprite(deltaTime);
    drawMoveLayers(window, _background);
    drawMoveLayers(window, _midground);
    drawMoveLayers(window, _foreground);
    window.draw(_buttons);
}
