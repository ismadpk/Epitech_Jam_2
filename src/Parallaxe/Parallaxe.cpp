/*
** EPITECH PROJECT, 2024
** Parallaxe.cpp
** File description:
** Parallaxe
*/

#include "Parallaxe/Parallaxe.hpp"

Parallaxe::Parallaxe()
{
    initAssets();
}

void Parallaxe::initAssets(void)
{
    std::cout << "init Assets" << std::endl;
    std::vector<std::string> bgdFiles = {"./assets/sky.png", "./assets/flag.png", "./assets/ground.png", "assets/buttons.png"};
    _bgdSpeeds = {0.5f, 1.0f, 1.5f, 0.0f};

    _bgdTextures.resize(bgdFiles.size());
    _bgdSprites.resize(bgdFiles.size());

    for (size_t i = 0; i < bgdFiles.size(); ++i) {
        if (!_bgdTextures[i].loadFromFile(bgdFiles[i])) {
            std::cerr << "Failed to load texture: " << bgdFiles[i] << std::endl;
            return;
        }
        _bgdSprites[i].setTexture(_bgdTextures[i]);
        if (bgdFiles[i] == "./assets/ground.png")
            _bgdSprites[i].setScale(sf::Vector2f(1.1, 0.94));
        _bgdXPos.push_back(0);
    }
}

void Parallaxe::updatePosBgd(const sf::RenderWindow& window)
{
    for (size_t i = 0; i < _bgdSprites.size(); i++) {
        _bgdXPos[i] -= _bgdSpeeds[i];
        if (_bgdXPos[i] <= -window.getSize().x) {
            _bgdXPos[i] = 0;
        }
    }
}

void Parallaxe::renderParallaxe(sf::RenderWindow& window) 
{

    for (size_t i = 0; i < _bgdSprites.size(); ++i) {
        _bgdSprites[i].setPosition(_bgdXPos[i], 0);
        window.draw(_bgdSprites[i]);

      // Draw a second sprite to create the looping effect
        if (_bgdSpeeds[i] > 0.0f) { // Only for moving layers
            _bgdSprites[i].setPosition(_bgdXPos[i] + window.getSize().x, 0);
            window.draw(_bgdSprites[i]);
        }
    }
}