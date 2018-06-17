#include "player.h"

#include <stdlib.h>
#include <time.h>


#include "entityfactory.h"
#include "entitywithpropertyfactory.h"
#include "config.h"


Player::Player(std::shared_ptr<User> user):
    _score(0), _pas(false), _win(false),
    _stageScore(0), _user(user),
    _deck(_deckGenerator()),
    _hand(_handGenerator())
{
    srand (time(NULL));
}

std::shared_ptr<Deck> Player::_handGenerator() const
{
   return _createCards(Config::Instance().HAND_SIZE);
}

std::shared_ptr<Deck> Player::_deckGenerator() const
{
    return _createCards(Config::Instance().DECK_SIZE);
}

std::shared_ptr<Deck> Player::_createCards(int cards) const
{
    auto newDeck = std::make_shared<Deck>();

    auto entityWithPropertyFactory = new EntityWithPropertyFactory();
    auto entityFactory = new EntityFactory();

    for (int i = 0; i < cards; ++i){

        PROPERTY_TYPE propertyType =  (PROPERTY_TYPE)(rand()% PROPERTIES);
        ENTITY_TYPE entityType = (ENTITY_TYPE)(rand()%ENTITIES);
        int strength = rand() % Config::Instance().MAX_STRENGTH + 1;

        switch (propertyType){
            case (NO_PROPERTY):
                newDeck->addCard(entityFactory->createCard(entityType, strength));
            break;

            default:
                newDeck->addCard(entityWithPropertyFactory->createCard(entityType, strength, propertyType));
            break;
        }
    }

    delete entityWithPropertyFactory;
    delete entityFactory;
    return newDeck;
}

void Player::addCardToHand()
{
    _hand->addCard(_deck->takeLast());
}

std::string Player::getLogin() const
{
    return _user->getLogin();

}

std::shared_ptr<Deck> Player::getHand() const
{
    return _hand;
}

bool Player::isPass() const
{
    return _pas;
}

void Player::setPass()
{
    _pas = true;
}

void Player::resetPass()
{
    _pas = false;
}

void Player::resetScore()
{
    _score = 0;
}

bool Player::isInHand(int cardId) const
{
    return _hand->findByCardId(cardId)?true:false;
}


std::shared_ptr<AbstractCard> Player::removeFromHand(int cardId)
{
    return _hand->removeCardByCardId(cardId);
}

std::shared_ptr<AbstractCard> Player::removeFromDeckByEntityType(ENTITY_TYPE entityType)
{
    auto card = _deck->findByEntityType(entityType);
    if (card)
        return _deck->removeCardByCardId(card->getId());

    return nullptr;
}

void Player::addToScore(int cardStrength)
{
    _score += cardStrength;
}

int Player::getScore() const
{
    return _score;
}

void Player::reset()
{
    resetScore();
    resetPass();
}

void Player::setWin()
{
    _win = true;
}

void Player::setLose()
{
    _win = false;
}

bool Player::isWin() const
{
    return _win;
}

int Player::getStageScore() const
{
    return _stageScore;
}

void Player::addStageWin()
{
    _stageScore++;
}

void Player::ReestablishHand()
{
    while(_hand->size() < Config::Instance().HAND_SIZE)
    {
        addCardToHand();
    }

}

int Player::getHandSize() const
{
    return _hand->size();
}

