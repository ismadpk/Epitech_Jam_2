#ifndef MEDAILLE_HPP_
    #define MEDAILLE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

class Medaille {
    public:
        Medaille();
        void setTexture();
        void moveMedal(bool isCollision);
        void setPosition(sf::Vector2f pos);
        sf::Vector2f getPosition();
        sf::Vector2u getSize();
        sf::Sprite getMedal();
        ~Medaille();

    private:
        sf::Texture _fireTexture;
        sf::Texture _waterTexture;
        sf::Sprite _medal;
};

#endif /* !MEDAILLE_HPP_ */
