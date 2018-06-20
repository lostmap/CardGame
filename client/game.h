#ifndef GAME_H
#define GAME_H


#include "player.h"
#include "user.h"
#include "party.h"

class InterLayer;

#include <string>
#include <SFML/Graphics.hpp>

#include <memory>

class Game
{
public:
    Game();
    ~Game();

    void startParty();
    void setInterLayer(std::shared_ptr<InterLayer>);
    void logIn(std::string login, std::string password);
    void signUp(std::string login, std::string password);

    // игрок пасанул
    void pass();
    void setPass();
    bool passEnemy();
    bool myTern();

    void draw(std::shared_ptr<sf::RenderWindow> window, sf::Vector2i mousePosition);

    void setTurn(int turn);
    void setWin(int win);
    void setPlayerInfo(int stageSore,int score, int handSize, int pass);
    void setPartnerInfo(int stageScore, int Score, int handSize, int pass);
    void addHeandCard(std::shared_ptr<AbstractCard> card);
    void addCardToEnemy(std::shared_ptr<AbstractCard> card);
    void addCardToMe(std::shared_ptr<AbstractCard> card);

    void pressedEvent(sf::Vector2i mousePosition);
    void releasedEvent();
    void move(sf::Vector2i mousePosition);

    int getEnemyScore();
    int getScore();

    std::string getLogin();
    std::string getPassword();



private:
    std::shared_ptr<InterLayer> _interLayer;

    std::shared_ptr<User> _user;
    std::shared_ptr<Party> _party;
};

#endif // GAME_H
