#ifndef DECK_H
#define DECK_H

#include "abstractcard.h"
#include "config.h"
#include "field.h"

#include <memory>
#include <vector>


class Deck
{
public:
    Deck(float x = Config::Instance().DECK.X, float y = Config::Instance().DECK.Y,
         int cardSpace = Config::Instance().CARD.SPACE);

    ~Deck();

    // добавление карты в колоду по указателю
    void addCard(std::shared_ptr<AbstractCard>);

    // удаление карты из колоды по указателю
    void removeCard(std::shared_ptr<AbstractCard>);

    // поиск карты по уникальному id
    std::shared_ptr<AbstractCard> findByCardId(int cardId);

    // удаление карты по уникальному id
    std::shared_ptr<AbstractCard> removeCardByCardId(int cardId);

    void draw(std::shared_ptr<sf::RenderWindow>);

    void pressedEvent(sf::Vector2i);
    int releasedEvent(std::shared_ptr<Field>,bool);
    void move(sf::Vector2i);

    void cardsMove();
    std::shared_ptr<AbstractCard> catchIfContains(sf::Vector2i mouse);
    std::shared_ptr<AbstractCard> contains(sf::Vector2i mouse);

    int size();

private:
    std::vector<std::shared_ptr<AbstractCard>> _deck;
    std::shared_ptr<AbstractCard> _currentHold;
    float _x;
    float _y;
    int _cardSpace;
};

#endif // DECK_H
