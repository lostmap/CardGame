#ifndef DECK_H
#define DECK_H

#include "abstractcard.h"

#include <QVector>

class Deck
{
public:
    Deck();
    // добавление карты в колоду по указателю
    void addCard(AbstractCard *);

    // удаление карты из колоды по указателю
    void removeCard(AbstractCard *);

    // поиск карты по уникальному id
    AbstractCard *findByCardId(int cardId);

    // удаление карты по уникальному id
    AbstractCard *removeCardByCardId(int cardId);

    int size();

private:
    QVector<AbstractCard *> _deck;
};

#endif // DECK_H
