/*
** EPITECH PROJECT, 2024
** Parallax.hpp
** File description:
** Parallax
*/

#ifndef Parallax_HPP_
#define Parallax_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

class Parallax {
    public:
        Parallax();
        ~Parallax() = default;

        void checkParallaxSpritePos(void);
        void moveParallaxSprite(float deltaTime);
        void renderParallax(sf::RenderWindow& window);

    private:
        void initAssets(void);
        sf::Texture _backgroundTexture;
        sf::Texture _midgroundTexture;
        sf::Texture _foregroundTexture;
        sf::Texture _buttonsTexture;

        sf::Sprite _background;
        sf::Sprite _midground;
        sf::Sprite _foreground;
        sf::Sprite _buttons;

        sf::Clock _clock;
};

#endif /* !Parallax_HPP_ */
