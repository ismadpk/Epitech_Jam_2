
#ifndef CORE_HPP_
    #define CORE_HPP_

    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include "Menu/Menu.hpp"
    #include "Parallax/Parallax.hpp"
    #include "Player/Player.hpp"
    #include "Medaille/Medaille.hpp"

    #define ERROR 84;
    #define SUCCESS 0;

class Core {
    public:
        Core();
        ~Core();
        int mainGameLoop();
        int handleEvents();
        bool checkColisions(sf::Vector2f firstObj, sf::Vector2f secObj, sf::Vector2u firstSize, sf::Vector2u secSize);
        int handleLose();
        int startGame();

    private:
        sf::RenderWindow _window;
        sf::Event _event;
        Parallax _parallax;
        bool inGame = false;
        Player _player;
        Medaille _medalLeft;
};

#endif /* !CORE_HPP_ */
