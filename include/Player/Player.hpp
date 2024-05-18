#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include <utility>
    #include <SFML/Graphics/Sprite.hpp>
    #include <SFML/Graphics/Texture.hpp>
    #define NB_FOR_UPGRADE 15
    #define NB_FOR_DOWNGRADE 5
    #define MAX_TRANSFORMATION 4
    #define MIN_TRANSFORMATION 0

class Player
{
    public:
        Player();
        ~Player();
        void handlemove();
        void handleTransformation();
        sf::Sprite getSprite() const;

    private:
        void moveLeft();
        void moveRight();
        bool upgradeTransformation();
        bool downgradeTransformation();
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
};

#endif /* !PLAYER_HPP_ */
