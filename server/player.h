#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "user.h"

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
    // колличество побед в раундах
    int getStageScore();
    void addStageWin();
    void resetScore();
    void reset();

private:

    // количество очков в стадии
    int _score;
    bool _pass;
    int _win;
    // количество побед в партии
    int _stageScore;


    User *_user;
    // колода игрока
    Deck *_deck;
    // карты в руке
    Deck *_heand;

    Deck *_deckGenerator();
    Deck *_heandGenerator();
};

#endif // PLAYER_H
