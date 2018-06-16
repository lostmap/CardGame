#include "field.h"

Field::Field(std::shared_ptr<Player> player1,
             std::shared_ptr<Player> player2)
{
    _tableDeck[player1] = std::shared_ptr<Deck>(new Deck());
    _tableDeck[player2] = std::shared_ptr<Deck>(new Deck());
}

Field::~Field() {

}

std::shared_ptr<Deck> Field::getDeck(std::shared_ptr<Player> player) const
{
    return _tableDeck.at(player);
}

void Field::addCardToDeck(std::shared_ptr<Player> player,
                          std::shared_ptr<AbstractCard> card)
{
    _tableDeck[player]->addCard(card);
}

void Field::addCardToField(std::shared_ptr<Player> player1,
                           std::shared_ptr<Player> player2,
                           std::shared_ptr<AbstractCard> card)
{
    _cardProperty.activate(player1, player2, card, shared_from_this());
}

void Field::reset()
{
    for (auto i: _tableDeck)
        i.second->clear();
}
