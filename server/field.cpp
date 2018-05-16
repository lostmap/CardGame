#include "field.h"

Field::Field(Player* player1, Player *player2)
{
    _tableDeck[player1] = new Deck();
    _tableDeck[player2] = new Deck();
}

Field::~Field()
{
    for ( QMap<Player *, Deck *>::iterator deck = _tableDeck.begin(); deck != _tableDeck.end(); ++deck)
    {
        delete (*deck);
    }
}

Deck* Field::getDeck(Player *player)
{
    return _tableDeck[player];
}

void Field::addCardToDeck(Player *player, AbstractCard *card)
{
    _tableDeck[player]->addCard(card);
}

void Field::addCardToField(Player *player1, Player *player2, AbstractCard *card)
{
    switch (card->property()) {
    case Buff:
        card->property(getDeck(player1));
        addCardToDeck(player1, card);
        break;

    case Spy:
        addCardToDeck(player2, card);
        player1->addCardToHeand();
        player1->addCardToHeand();
        break;

    case RollCall:
        // !!!!!!!!!!!!!!!!!!!!!
        player1->addCardToHeand();
        player1->addCardToHeand();
        break;

    default:
        addCardToDeck(player1, card);
        break;
    }
    player1->ReestablishHand();
}

void Field::reset(Player* player)
{
    _tableDeck[player]->clear();
}


QDomElement Field::toQDomElement(Player* player1, Player* player2)
{
    QDomDocument document;
    QDomElement node = document.createElement("field");

    node.appendChild(getDeck(player2)->toQDomElement("partner"));
    node.appendChild(getDeck(player1)->toQDomElement("mycards"));

   return node;
}
