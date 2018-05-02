#include "deck.h"

Deck::Deck()
{

}

void Deck::addCard(AbstractCard *card)
{
    _deck.push_back(card);

}

void Deck::removeCard(AbstractCard *card)
{
    _deck.removeOne(card);
}

QVector<AbstractCard *>::iterator Deck::begin()
{
    return _deck.begin();
}

QVector<AbstractCard *>::iterator Deck::end()
{
    return _deck.end();
}
