#ifndef DECK_H
#define DECK_H

#include "abstractcard.h"
#include "define.h"

#include <QVector>
#include <QDomElement>

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

    // поиск карты по её типу
    AbstractCard *findByEntityType(int entityType);

    // удаление карты по уникальному id
    AbstractCard *removeCardByCardId(int cardId);

    // удаляет и возвращает из колоды последнюю карту
    AbstractCard *takeLast();

    int size();
    void clear();

    QDomElement toQDomElement(QString deckName);

private:
    QVector<AbstractCard *> _deck;
};

#endif // DECK_H
