#include "deck.h"

Deck::Deck()
{

}

void Deck::addCard(AbstractCard *card)
{
    switch (card->property()) {
    case Buff:
        card->property(this);

        break;
    default:
        break;
    }
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

AbstractCard* Deck::findByEntityType(int entityType)
{
    for (QVector<AbstractCard *>::iterator i = _deck.begin();
         i != _deck.end(); ++i)
    {
        if ((*i)->getEntityType() == entityType)
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

AbstractCard* Deck::takeLast()
{
    if (!_deck.isEmpty())
        return _deck.takeLast();
}

void Deck::clear()
{
    _deck.clear();
}

QDomElement Deck::toQDomElement(QString deckName)
{
    QDomDocument document;
    QDomElement element = document.createElement(deckName);

    for (auto i = _deck.begin(); i != _deck.end(); ++i)
    {
        element.appendChild((*i)->toDomElement());
    }

    return element;
}

