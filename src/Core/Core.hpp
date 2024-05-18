
#ifndef CORE_HPP_
    #define CORE_HPP_

#include <SFML/Graphics.hpp>
#include "../Medaille/Medaille.hpp"

class Core {
    public:
        Core();
        int runGame();
        bool checkColisions(sf::Vector2f firstObj, sf::Vector2f secObj, sf::Vector2u firstSize, sf::Vector2u secSize);
        ~Core();

    protected:
    private:
};

#endif /* !CORE_HPP_ */
