#include "deck.h"

#include <algorithm>

#include "entitycard.h"
#include "entitywithpropertycard.h"

#include <algorithm>

Deck::Deck(float x, float y, int cardSpace):
        _x(x), _y(y), _cardSpace(cardSpace), _currentHold(nullptr)
{}

Deck::~Deck() {}

void Deck::addCard(std::shared_ptr<AbstractCard> new_card)
{
    auto card = findByCardId(new_card->getId());

    if (!card)
    {
        new_card->setPosition(sf::Vector2f(_x + size()*(Config::Instance().MEDIUM.WIDTH + Config::Instance().CARD.SPACE), _y));
        _deck.push_back(new_card);
    }
}


void Deck::draw(std::shared_ptr<sf::RenderWindow> window) {

    for(auto card: _deck)
        card->draw(window);

    if (_currentHold)
        _currentHold->draw(window);

}

void Deck::cardsMove() {

    for (size_t i = 0; i < size(); ++i) {
        _deck[i]->setPosition(sf::Vector2f(_x + i * (Config::Instance().MEDIUM.WIDTH + Config::Instance().CARD.SPACE), _y));
    }
}

void Deck::removeCard(std::shared_ptr<AbstractCard> card)
{

    for (auto element: _deck) {
        if (element->getId() == card->getId()) {
            std::cout<<card->getId()<<std::endl;
            _deck.erase(std::remove(_deck.begin(), _deck.end(), element));
            break;
        }
    }
    cardsMove();
}


std::shared_ptr<AbstractCard> Deck::findByCardId(int cardId)
{
    for (auto card: _deck)
    {
        if (card->getId() == cardId)
            return card;
    }
   return nullptr;
}

std::shared_ptr<AbstractCard> Deck::removeCardByCardId(int cardId)
{
    std::shared_ptr<AbstractCard> card = findByCardId(cardId);
    removeCard(card);
    return card;
}

int Deck::size()
{
    return _deck.size();
}

std::shared_ptr<AbstractCard> Deck::contains(sf::Vector2i mouse) {
    for (auto card :_deck)
        if (card->contains(mouse.x, mouse.y))
           return card;
    return nullptr;
}


std::shared_ptr<AbstractCard> Deck::catchIfContains(sf::Vector2i mouse) {
    for (auto card :_deck) {
        if (card->contains(mouse.x, mouse.y)) {
            _currentHold = card;
            card->hold();
            return _currentHold;
        }

    }
    return nullptr;
    
}

void Deck::move(sf::Vector2i mouse) {
    if(_currentHold) {
         _currentHold->move(mouse.x, mouse.y);
    }
}


void Deck::pressedEvent(sf::Vector2i mouse) {
    catchIfContains(mouse);
}

int Deck::releasedEvent(std::shared_ptr<Field> field, bool _turn) {

    if (_currentHold ) {
         int card_id = _currentHold->getId();
        if (_turn)
         if(field->catchCard(_currentHold)){
            removeCard(_currentHold);
            _currentHold = nullptr;
            return card_id;
        }
        else {
            _currentHold->drop();
            _currentHold = nullptr;
        
        }
        else {
            _currentHold->drop();
            _currentHold = nullptr;
        
        }

    }     
    return 0;
}


