#ifndef PARTY_H
#define PARTY_H

#include "player.h"
#include "deck.h"
#include "field.h"
#include "abstractcard.h"
#include "info.h"


#include <memory>

class Party
{
public:
    Party(bool tern);
    ~Party();

    bool isMyTern();

    void setTurn(int turn);
    void setWin(int win);
    void setPlayerInfo(int stageScore,int score, int handSize, int pass);
    void setPartnerInfo(int stageScore, int Score, int handSize, int pass);
    void addHandCard(std::shared_ptr<AbstractCard> card);
    void addCardToEnemy(std::shared_ptr<AbstractCard> card);
    void addCardToMe(std::shared_ptr<AbstractCard> card);

    int getScore();
    int getEnemyScore();


    bool passEnemy();
    void draw(std::shared_ptr<sf::RenderWindow> window, sf::Vector2i mousePosition);
    void pressedEvent(sf::Vector2i mousePosition);
    int releasedEvent();

    void move(sf::Vector2i mousePosition);

private:

    std::shared_ptr<Field> _field;
    std::shared_ptr<Deck> _hand;
    bool _turn;
    std::shared_ptr<Player> _me;
    std::shared_ptr<Player> _partner;
    std::shared_ptr<Info> _info;


};

#endif // PARTY_H
