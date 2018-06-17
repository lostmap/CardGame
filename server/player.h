#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "user.h"
#include "config.h"
#include "abstractcard.h"

#include <memory>

class Player
{
public:
    Player(std::shared_ptr<User>);
    std::string getLogin() const;

    void setWin();
    bool isWin() const;

    void setLose();

    bool isPass() const;
    void setPass();
    void resetPass();

    // возвращает карты из руки
    std::shared_ptr<Deck> getHand() const;
    // проверяет наличие карты в руке по id карты
    bool isInHand(int cardId) const;
    int getHandSize() const;

    std::shared_ptr<AbstractCard> removeFromHand(int cardId);
    void addToScore(int cardStrength);
    int getScore() const;
    void addCardToHand();
    void ReestablishHand();
    // колличество побед в раундах
    int getStageScore() const;
    void addStageWin();
    void resetScore();
    void reset();

    std::shared_ptr<AbstractCard> removeFromDeckByEntityType(ENTITY_TYPE);

private:

    // количество очков в стадии
    int _score;
    bool _pas;
    bool _win;
    // количество побед в партии
    int _stageScore;


    std::shared_ptr<User> _user;

    // колода игрока
    std::shared_ptr<Deck>_deck;

    // карты в руке
    std::shared_ptr<Deck> _hand;


    std::shared_ptr<Deck> _deckGenerator() const;
    std::shared_ptr<Deck> _handGenerator() const;
    std::shared_ptr<Deck> _createCards(int cards) const;
};

#endif // PLAYER_H
