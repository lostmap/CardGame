#include "menu.h"

Menu::Menu() {}

int Menu::draw(std::shared_ptr<sf::RenderWindow> window){
    sf::Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
    menuTexture1.loadFromFile("images/one.png");
    menuTexture2.loadFromFile("images/two.png");
    menuTexture3.loadFromFile("images/three.png");
    aboutTexture.loadFromFile("images/about.png");
    menuBackground.loadFromFile("images/bg.png");
    sf::Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
    bool isMenu = 1;
    int menuNum = 0;
    menu1.setPosition(528, 296);
    menu2.setPosition(529, 418);
    menu3.setPosition(540, 537);
 
    //////////////////////////////МЕНЮ///////////////////
    sf::Event event;
    while (isMenu)
    {
        menu1.setColor(sf::Color::White);
        menu2.setColor(sf::Color::White);
        menu3.setColor(sf::Color::White);
        menuNum = 0;
        window->clear(sf::Color(129, 181, 221));
 
        if (sf::IntRect(528, 296, menuTexture1.getSize().x, menuTexture1.getSize().y).contains(sf::Mouse::getPosition(*(window.get())))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }
        if (sf::IntRect(529, 418, menuTexture2.getSize().x, menuTexture2.getSize().y).contains(sf::Mouse::getPosition(*(window.get())))) { menu2.setColor(sf::Color::Blue); menuNum =  2; }
        if (sf::IntRect(540, 537, menuTexture3.getSize().x, menuTexture3.getSize().y).contains(sf::Mouse::getPosition(*(window.get())))) { menu3.setColor(sf::Color::Blue); menuNum = 3; }
 
        window->pollEvent(event);
 
        window->draw(menuBg);
        window->draw(menu1);
        window->draw(menu2);
        window->draw(menu3);
        
        window->display();


        if (event.type == sf::Event::MouseButtonReleased)
        {

            if(menuNum == 1){
                break;
            }

            if (menuNum == 3){
                window->close();
                break;
            }
        }



    }
}