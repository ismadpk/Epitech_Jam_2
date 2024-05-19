
#include "Player/Player.hpp"
#include <iostream>
#include <SFML/Window.hpp>

Player::Player() : _rect(0, 119, 56, 90), _windowSize(1920, 1050), _counterFlam(0),
    _counterWater(0), _nbTransformation(0), _speed(8), _score(0), _isLoss(false)
{
    if (!this->_texture.loadFromFile("assets/flame-runner.png"))
    {
        return;
    }
    this->_sprite.setTextureRect(this->_rect);
    this->_sprite.setTexture(this->_texture);
    this->_currentPos = std::make_pair<int, int>((this->_windowSize.first / 2), (this->_windowSize.second - 220));
    this->_sprite.setPosition(this->_currentPos.first, this->_currentPos.second);
}

Player::~Player()
{
}

void Player::moveLeft()
{
    if (this->_currentPos.first - this->_speed >= 0)
    {
        this->_currentPos.first -= this->_speed;
    }
}

void Player::moveRight()
{
    if (this->_rect.width + this->_currentPos.first + this->_speed <= this->_windowSize.first)
    {
        this->_currentPos.first += this->_speed;
    }
}

void Player::handlemove(bool isCollision, Status status)
{
    bool isMove = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->moveLeft();
        isMove = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->moveRight();
        isMove = true;
    }
    if (isMove == true)
    {
        this->_sprite.setPosition(this->_currentPos.first, this->_currentPos.second);
    }
    this->handleTransformation(isCollision, status);
}

bool Player::upgradeTransformation(bool isCollision, Status status)
{
    if (status == Status::Fire && isCollision == true && _nbTransformation < MAX_TRANSFORMATION) {
        this->_counterFlam += 1;
        if (this->_counterFlam % NB_FOR_UPGRADE == 0)
        {
            this->_counterFlam = 0;
            this->_nbTransformation += 1;
            return true;
        }
    }
    return false;
}

bool Player::downgradeTransformation(bool isCollision, Status status)
{

    if (status == Status::Water && isCollision == true && _nbTransformation > MIN_TRANSFORMATION) {
        this->_counterWater += 1;
        if (this->_counterWater >= NB_FOR_DOWNGRADE)
        {
            this->_counterWater = 0;
            this->_nbTransformation -= 1;
            return true;
        }
    }
    if (status == Status::Water && _nbTransformation == MIN_TRANSFORMATION && isCollision == true)
    {
        this->_counterWater += 1;
        if (this->_counterWater == NB_FOR_LOSS)
        {
            this->_isLoss = true;
        }
    }
    return false; 
}

void Player::handleTransformation(bool isCollision, Status status)
{
    if (this->upgradeTransformation(isCollision, status) == true || this->downgradeTransformation(isCollision, status) == true)
    {
        if (this->_nbTransformation == 0)
        {
            sf::IntRect newRect(0, 119, 56, 90);
            this->_rect = newRect;
            this->_sprite.setTextureRect(this->_rect);
            this->_currentPos.second = this->_windowSize.second - 220;
            this->_sprite.setPosition(this->_currentPos.first, this->_currentPos.second);
        }
        if (_nbTransformation == 1)
        {
            sf::IntRect newRect(114, 104, 76, 105);
            this->_rect = newRect;
            this->_sprite.setTextureRect(this->_rect);
            this->_currentPos.second = this->_windowSize.second - 235;
            this->_sprite.setPosition(this->_currentPos.first, this->_currentPos.second);
        }
        if (_nbTransformation == 2)
        {
            sf::IntRect newRect(249, 63, 105, 146);
            this->_rect = newRect;
            this->_sprite.setTextureRect(this->_rect);
            this->_currentPos.second = this->_windowSize.second - 275;
            this->_sprite.setPosition(this->_currentPos.first, this->_currentPos.second);
        }
        if (_nbTransformation == 3)
        {
            sf::IntRect newRect(412, 27, 120, 182);
            this->_rect = newRect;
            this->_sprite.setTextureRect(this->_rect);
            this->_currentPos.second = this->_windowSize.second - 310;
            this->_sprite.setPosition(this->_currentPos.first, this->_currentPos.second);
        }
        if (_nbTransformation == 4)
        {
            sf::IntRect newRect(593, 0, 211, 209);
            this->_rect = newRect;
            this->_sprite.setTextureRect(this->_rect);
            this->_currentPos.second = this->_windowSize.second - 350;
            this->_sprite.setPosition(this->_currentPos.first, this->_currentPos.second);
        }
    
    }
}

sf::Sprite Player::getSprite() const
{
    return this->_sprite;
}

sf::Vector2f Player::getPosition() const
{
    return this->_sprite.getPosition();
}

sf::Vector2u Player::getSize() const
{
    return this->_sprite.getTexture()->getSize();
}

bool Player::getStatusGame() const
{
    return this->_isLoss;
}
