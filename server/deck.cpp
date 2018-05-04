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

AbstractCard * Deck::findByCardId(int cardId)
{
    for (QVector<AbstractCard *>::iterator i = begin();
         i != end(); ++i)
    {
        if ((*i)->getId() == cardId)
            return (*i);
    }
   return nullptr;
}

AbstractCard * Deck::removeCardByCardId(int cardId)
{
    AbstractCard * card = findByCardId(cardId);
    _deck.removeOne(card);
    return card;
}

int Deck::size()
{
    return _deck.size();
}

AbstractCard* Deck::takeLast()
{
    if (!_deck.isEmpty())
        return _deck.takeLast();
}

void Deck::clear()
{
    _deck.clear();
}

