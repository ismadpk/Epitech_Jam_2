#include "Medaille.hpp"

Medaille::Medaille()
{
    this->setTexture("assets/sprites/FlameFaling.png");
}

void Medaille::setTexture(std::string Img)
{
    if (!this->_texture.loadFromFile(Img))
        return;
    this->_texture.setSmooth(true);
    this->_medal.setTexture(this->_texture);
    std::cout << this->_texture.getSize().x << this->_texture.getSize().y << std::endl;
}

void Medaille::moveMedal()
{
    int posY = this->_medal.getPosition().y + 1;

    std::srand(std::time(nullptr));
    int random_value = std::rand() % 2;

    if (random_value == 0) {   
        this->setTexture("assets/sprites/WaterDrop.png");
        this->_medal.setScale({10.f, 10.f});
    }


    if (posY >= 600) 
        posY = -20;
    this->_medal.setPosition(this->_medal.getPosition().x, posY);
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
