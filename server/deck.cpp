#include "deck.h"

#include <algorithm>
#include <functional>

Deck::Deck()
{

}

void Deck::addCard(std::shared_ptr<AbstractCard> card)
{
    _deck.push_back(card);
}

void Deck::removeCard(std::shared_ptr<AbstractCard> card)
{
     removeCardByCardId(card->getId());
}


bool Deck::findByCardId(int cardId)
{
    for (auto i: _deck)
    {
        if (i->getId() == cardId)
            return true;
    }
   return false;
}

std::shared_ptr<AbstractCard> Deck::findByEntityType(int entityType)
{
    for (auto i: _deck)
    {
        if (i->getEntityType() == entityType)
            return i;
    }
   return nullptr;
}

bool checkCardId(std::shared_ptr<AbstractCard> card, int cardId) {
  return card->getId() == cardId;
}


std::shared_ptr<AbstractCard> Deck::removeCardByCardId(int cardId)
{
    auto cardIter = std::find_if(_deck.begin(), _deck.end(), std::bind2nd(std::ptr_fun(checkCardId), cardId));
    std::shared_ptr<AbstractCard> card = std::move(*cardIter);
    _deck.erase(cardIter);
    return card;
}

int Deck::size()
{
    return _deck.size();
}

std::shared_ptr<AbstractCard> Deck::takeLast()
{
    if (!_deck.empty()){
        std::shared_ptr<AbstractCard> card = std::move(_deck.back());
        _deck.pop_back();
        return card;
    }
    return nullptr;
}

void Deck::clear()
{
    _deck.clear();
}

std::vector<std::shared_ptr<AbstractCard>>::iterator Deck::begin()
{
   return _deck.begin();
}

std::vector<std::shared_ptr<AbstractCard>>::iterator Deck::end()
{
    return _deck.end();
}
