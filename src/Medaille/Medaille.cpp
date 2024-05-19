#include "Medaille/Medaille.hpp"

Medaille::Medaille()
{
    this->setTexture();
}

void Medaille::setTexture()
{
    int posX = 0;

    if (!this->_fireTexture.loadFromFile("assets/sprites/FlameFaling.png"))
        return;
    this->_fireTexture.setSmooth(true);

    if (!this->_waterTexture.loadFromFile("assets/sprites/WaterDrop.png"))
        return;
    std::srand(std::time(0));
    posX = std::rand() % (1920 + 1 - 0) + 0;
    this->_waterTexture.setSmooth(true);
    this->_medal.setPosition(posX, -80);
    this->_medal.setTexture(this->_fireTexture);
    this->_status = Status::Fire;
}

void Medaille::moveMedal(bool isCollision)
{
    int posY = this->_medal.getPosition().y + 5;
    int posX = this->_medal.getPosition().x;
    std::srand(std::time(0));
    int random_value = std::rand() % 2;

    if (posY >= 830 || isCollision == true) {
        posY = -80;
        if (random_value == 0) {
            sf::IntRect waterRect({0, 0, 70, 92});
            this->_medal.setTextureRect(waterRect);
            this->_medal.setTexture(this->_waterTexture);
            this->_status = Status::Water;
        } else {
            sf::IntRect fireRect({0, 0, 32, 82});
            this->_medal.setTextureRect(fireRect);
            this->_medal.setTexture(this->_fireTexture);
            this->_status = Status::Fire;
        }
        std::srand(std::time(0));
        posX = std::rand() % (1920 + 1 - 0) + 0;
    }
    this->_medal.setPosition(posX, posY);
}

void Medaille::setPosition(sf::Vector2f pos)
{
    this->_medal.setPosition(pos.x, pos.y);
}

sf::Sprite Medaille::getMedal() const
{
    return this->_medal;
}

sf::Vector2u Medaille::getSize() const
{
    return this->_medal.getTexture()->getSize();
}

sf::Vector2f Medaille::getPosition() const
{
    return this->_medal.getPosition();
}

Status Medaille::getStatus() const
{
    return this->_status;
}

Medaille::~Medaille()
{
}
