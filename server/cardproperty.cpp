#include "cardproperty.h"

#include "field.h"
#include "player.h"
#include "abstractcard.h"
#include "config.h"

CardProperty::CardProperty()
{

}

void CardProperty::activate(std::shared_ptr<Player> player1,
                            std::shared_ptr<Player> player2,
                            std::shared_ptr<AbstractCard> card,
                            std::shared_ptr<Field> field)
{
    switch (card->getPropertyType()) {
    case Buff:
            _buff(player1, card, field);
        break;

    case Spy:
            _spy(player1, player2, card, field);
        break;

    case RollCall:
            _rollCall(player1, card, field);
        break;

    default:
            _default(player1, card, field);
        break;
    }
    player1->ReestablishHand();
}

void CardProperty::_buff(std::shared_ptr<Player> player1,
                          std::shared_ptr<AbstractCard> card,
                          std::shared_ptr<Field> field) {

    std::shared_ptr<AbstractCard> same_card = field->getDeck(player1)->findByEntityType(card->getEntityType());
    if (same_card)
    {
        same_card->setStrength(same_card->getStrength() * Config::Instance().BUFF_RATE);
        card->setStrength(card->getStrength() * Config::Instance().BUFF_RATE);
    }
    field->addCardToDeck(player1, card);
}

void CardProperty::_rollCall(std::shared_ptr<Player> player1,
                              std::shared_ptr<AbstractCard> card,
                              std::shared_ptr<Field> field) {

    field->addCardToDeck(player1, card);
    auto newCard = player1->removeFromDeckByEntityType(card->getEntityType());
    if (newCard) {
        field->addCardToDeck(player1, newCard);
    }
}

void CardProperty::_spy(std::shared_ptr<Player> player1,
                         std::shared_ptr<Player> player2,
                         std::shared_ptr<AbstractCard> card,
                         std::shared_ptr<Field> field) {

    field->addCardToDeck(player2, card);
    player1->addCardToHand();
    player1->addCardToHand();

}

void CardProperty::_default(std::shared_ptr<Player> player1,
              std::shared_ptr<AbstractCard> card,
              std::shared_ptr<Field> field) {

    field->addCardToDeck(player1, card);

}
