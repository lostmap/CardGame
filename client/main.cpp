#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "interlayer.h"
#include "client.h"
#include "config.h"  
#include "entitycard.h"
#include "menu.h"
#include "mainwindow.h"

#include <memory>

int main()
{   
    Config& init = Config::Instance("client.xml");


    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1366, 768), "GWINT");
    
    Menu menu;
    menu.draw(window);


    auto client = std::make_shared<Client>();
    auto game = std::make_shared<Game>();
    client->signUp(game->getLogin(), game->getPassword());
    auto mainWindow = std::make_shared<MainWindow>();
    auto interLayer = std::make_shared<InterLayer>(game, client);
    game->setInterLayer(interLayer);
    client->setInterLayer(interLayer);
    

    while (window->isOpen())
    {
        interLayer->update();

        mainWindow->setScore(game->getScore(), game->getEnemyScore());
            
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*(window.get()));

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            if (event.type == sf::Event::MouseButtonPressed)//если нажата клавиша мыши
                if (event.key.code == sf::Mouse::Left) {
                    game->pressedEvent(mousePosition);
                    if (mainWindow->pass(mousePosition.x, mousePosition.y)){
                        game->setPass();
                    }

                }


            if (event.type == sf::Event::MouseButtonReleased)
                if (event.key.code == sf::Mouse::Left)
                    game->releasedEvent(); 

        }

        if (game->passEnemy()) {
            mainWindow->setEnemyPass();
        }


        mainWindow->setTurn(game->myTern());


        game->move(mousePosition);

        window->clear();
        
        mainWindow->draw(window);

        game->draw(window, mousePosition);
        
        window->display();

    }
  
    return 0;
}