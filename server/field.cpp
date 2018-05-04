#include "field.h"
#include "student.h"

Field::Field(Player* player1, Player *player2)
{
    _tableDeck[player1] = new Deck();
    _tableDeck[player2] = new Deck();
}

Deck* Field::getDeck(Player *player)
{
    return _tableDeck[player];
}

void Field::addCardToField(Player *player, AbstractCard *card)
{
    _tableDeck[player]->addCard(card);
    player->addToScore(static_cast<Student*>(card)->getStrength());
}

void Field::reset(Player* player)
{
    _tableDeck[player]->clear();
}
