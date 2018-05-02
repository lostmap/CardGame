#ifndef DECK_H
#define DECK_H

#include "abstractcard.h"

#include <QVector>



class Deck
{
public:
    Deck();

    void addCard(AbstractCard *);
    void removeCard(AbstractCard *);
    QVector<AbstractCard *>::iterator begin();
    QVector<AbstractCard *>::iterator end();


private:
    QVector<AbstractCard *> _deck;
};

#endif // DECK_H
