#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

#include <memory>


class Menu
{
public:
    Menu();

    int draw(std::shared_ptr<sf::RenderWindow> window);

private:

};

#endif 