#include "Core.hpp"
#include <unistd.h>

Core::Core()
{
}

int Core::runGame()
{
    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    Medaille medalLeft;
    Medaille medalLefta;
    medalLeft.setPosition({0, 0});
    medalLefta.setPosition({31, 0});
    window.setFramerateLimit(100);
 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
        medalLeft.moveMedal();

        window.clear();
        window.draw(medalLeft.getMedal());
        window.draw(medalLefta.getMedal());
        window.display();
    }

    return EXIT_SUCCESS;
}

bool Core::checkColisions(sf::Vector2f firstPos, sf::Vector2f secPos, sf::Vector2u firstSize, sf::Vector2u secSize)
{
    if (firstPos.x < secPos.x + secSize.x && firstPos.x + firstSize.x > secPos.x
    && firstPos.y < secPos.y + secSize.y && firstPos.y + firstSize.y > secPos.y)
        return true;

    return false;
}

Core::~Core()
{
}
