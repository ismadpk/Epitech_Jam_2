/*
** EPITECH PROJECT, 2024
** Parallaxe.hpp
** File description:
** Parallaxe
*/

#ifndef PARALLAXE_HPP_
#define PARALLAXE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

class Parallaxe {
    public:
        Parallaxe();
        ~Parallaxe() = default;

        std::vector<sf::Texture> getTextures() const {return _bgdTextures;};
        std::vector<sf::Sprite> getSprites() const {return _bgdSprites;};
        std::vector<float> getPositions() const {return _bgdXPos;};
        std::vector<float> getSpeeds() const {return _bgdSpeeds;};

        void initAssets(void);
        void updatePosBgd(const sf::RenderWindow& window);
        void renderParallaxe(sf::RenderWindow& window);

    private:
        std::vector<sf::Texture> _bgdTextures;
        std::vector<sf::Sprite> _bgdSprites;
        std::vector<float> _bgdXPos;
        std::vector<float> _bgdSpeeds;
};

#endif /* !PARALLAXE_HPP_ */
