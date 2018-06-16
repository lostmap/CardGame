#ifndef DECK_H
#define DECK_H

#include "abstractcard.h"
#include "config.h"

#include <vector>
#include <memory>


class Deck
{
public:
    Deck();

    // добавление карты в колоду по указателю
    void addCard(std::shared_ptr<AbstractCard>);

    // удаление карты из колоды по указателю
    void removeCard(std::shared_ptr<AbstractCard>);

    // поиск карты по уникальному id
    bool findByCardId(int cardId);

    // поиск карты по её типу
    std::shared_ptr<AbstractCard>findByEntityType(int entityType);

    // удаление карты по уникальному id
     std::shared_ptr<AbstractCard>removeCardByCardId(int cardId);

    // удаляет и возвращает из колоды последнюю карту
    std::shared_ptr<AbstractCard> takeLast();

    std::vector<std::shared_ptr<AbstractCard>>::iterator begin();
    std::vector<std::shared_ptr<AbstractCard>>::iterator end();

    int size();
    void clear();

private:
    std::vector<std::shared_ptr<AbstractCard>> _deck;
};

#endif // DECK_H
