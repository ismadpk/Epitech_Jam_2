#ifndef MEDAILLE_HPP_
    #define MEDAILLE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

enum Status {
    Fire = 0,
    Water
};

class Medaille {
    public:
        Medaille();
        void setTexture();
        void moveMedal(bool isCollision);
        void setPosition(sf::Vector2f pos);
        sf::Vector2f getPosition() const;
        sf::Vector2u getSize() const;
        sf::Sprite getMedal() const;
        Status getStatus() const;
        ~Medaille();

    private:
        sf::Texture _fireTexture;
        sf::Texture _waterTexture;
        sf::Sprite _medal;
        Status _status;
};

#endif /* !MEDAILLE_HPP_ */
