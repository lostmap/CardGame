#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "user.h"
#include "define.h"

class Player
{
public:
    Player(User *);
    QString getLogin();

    bool isWin();
    void setWin();
    int getWin();

    void setLose();
    bool isLose();

    bool isPass();
    void setPass();
    void resetPass();

    // возвращает карты из руки
    Deck *getHeand();
    // проверяет наличие карты в руке по id карты
    bool isInHeand(int cardId);

    AbstractCard* removeFromHand(int cardId);
    void addToScore(int cardStrength);
    int getScore();
    void addCardToHeand();
    void ReestablishHand();
    // колличество побед в раундах
    int getStageScore();
    void addStageWin();
    void resetScore();
    void reset();

    void isInDeckByEntityType();

    QDomElement toQDomElementWithHeand(QString playerName);
    QDomElement toQDomElement(QString playerName);

private:

    // количество очков в стадии
    int _score;
    bool _pas;
    int _win;
    // количество побед в партии
    int _stageScore;


    User *_user;

    // колода игрока
    // перенести в отдельный класс??
    Deck *_deck;

    // карты в руке
    // перенести в отдельный класс??
    Deck *_heand;

    // создать класс генератор
    Deck *_deckGenerator();
    Deck *_heandGenerator();

    QDomElement _domElement(QString elementName, int value);
};

#endif // PLAYER_H
