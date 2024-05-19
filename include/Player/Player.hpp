#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include <utility>
    #include <SFML/Graphics/Sprite.hpp>
    #include <SFML/Graphics/Texture.hpp>
    #include "Medaille/Medaille.hpp"
    #define NB_FOR_UPGRADE 5
    #define NB_FOR_DOWNGRADE 3
    #define NB_FOR_LOSS 5
    #define MAX_TRANSFORMATION 4
    #define MIN_TRANSFORMATION 0

class Player
{
    public:
        Player();
        ~Player();
        void handlemove(bool isCollision, Status status);
        sf::Sprite getSprite() const;
        sf::Vector2f getPosition() const;
        sf::Vector2u getSize() const;
        bool getStatusGame() const;
        int getScore() const;

    private:
        void moveLeft();
        void moveRight();
        void handleTransformation(bool isCollision, Status status);
        bool upgradeTransformation(bool isCollision, Status status);
        bool downgradeTransformation(bool isCollision, Status status);
        sf::IntRect _rect;
        std::pair<int, int> _currentPos;
        std::pair<int, int> _windowSize;
        sf::Sprite _sprite;
        sf::Texture _texture;
        int _counterFlam;
        int _counterWater;
        int _nbTransformation;
        int _speed;
        int _score;
        bool _isLoss;
};

#endif /* !PLAYER_HPP_ */
