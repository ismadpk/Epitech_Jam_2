#include "Medaille.hpp"

Medaille::Medaille()
{
    this->setTexture();
}

void Medaille::setTexture()
{
    if (!this->_fireTexture.loadFromFile("assets/sprites/FlameFaling.png"))
        return;
    this->_fireTexture.setSmooth(true);

    if (!this->_waterTexture.loadFromFile("assets/sprites/WaterDrop.png"))
        return;
    this->_waterTexture.setSmooth(true);
    this->_medal.setTexture(this->_fireTexture);
}

void Medaille::moveMedal()
{
    int posY = this->_medal.getPosition().y + 1;
    int posX = this->_medal.getPosition().x;
    std::srand(std::time(0));
    int random_value = std::rand() % 2;
    sf::IntRect waterRect({0, 0, 60, 100});

    if (posY >= 600) {
        posY = -80;
        if (random_value == 0) {
            this->_medal.setTextureRect(waterRect);
            this->_medal.setTexture(this->_waterTexture);
        }
        else
            this->_medal.setTexture(this->_fireTexture);
            random_value = std::rand() % 3;
        if (random_value == 0)
            posX = 140;
        else if (random_value == 1)
            posX = 320;
        else
            posX = 560;
    }
    this->_medal.setPosition(posX, posY);
}

void Medaille::setPosition(sf::Vector2f pos)
{
    this->_medal.setPosition(pos.x, pos.y);
}

sf::Sprite Medaille::getMedal()
{
    return this->_medal;
}

sf::Vector2u Medaille::getSize()
{
    return this->_medal.getTexture()->getSize();
}

sf::Vector2f Medaille::getPosition()
{
    return this->_medal.getPosition();
}

Medaille::~Medaille()
{
}
