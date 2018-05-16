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


AbstractCard * Deck::findByCardId(int cardId)
{
    for (QVector<AbstractCard *>::iterator i = _deck.begin();
         i != _deck.end(); ++i)
    {
        if ((*i)->getId() == cardId)
            return (*i);
    }
   return nullptr;
}

AbstractCard* Deck::removeCardByCardId(int cardId)
{
    AbstractCard * card = findByCardId(cardId);
    _deck.removeOne(card);
    return card;
}

int Deck::size()
{
    return _deck.size();
}


