#include "field.h"

#include "config.h"

Field::Field():
	_myDropSpace(std::make_shared<DropSpace>(Config::Instance().MY_SPACE.X, Config::Instance().MY_SPACE.Y,
	 						   Config::Instance().MY_SPACE.WIDTH, Config::Instance().MY_SPACE.HEIGHT,
	 						   Config::Instance().DROP_AREA_QUANTITY)),
	_enemyDropSpace(std::make_shared<DropSpace>(Config::Instance().ENEMY_SPACE.X, Config::Instance().ENEMY_SPACE.Y,
								  Config::Instance().ENEMY_SPACE.WIDTH, Config::Instance().ENEMY_SPACE.HEIGHT,
								  Config::Instance().DROP_AREA_QUANTITY)), 
	_blocked(false)
{

}

void Field::addCardToMe(std::shared_ptr<AbstractCard> card) {
	 if (!_blocked)
	 	_myDropSpace->addCard(card);
}


void Field::addCardToEnemy(std::shared_ptr<AbstractCard> card) {
	if (!_blocked)
		_enemyDropSpace->addCard(card);
}

void Field::setBlocked() {
	_blocked = true;
}

void Field::unblock() {
	_blocked = false;
}

std::shared_ptr<AbstractCard> Field::contains(sf::Vector2i mouse) {

	std::shared_ptr<AbstractCard> card = _myDropSpace->contains(mouse);
    
    if (card)
    	return card;

    card = _enemyDropSpace->contains(mouse);
    return card;
}

Field::~Field() {}


void Field::draw(std::shared_ptr<sf::RenderWindow> window) {
	_enemyDropSpace->draw(window);
	_myDropSpace->draw(window);
}


int Field::catchCard(std::shared_ptr<AbstractCard> card) {
	if(!_blocked)
		
		switch (card->getPropertyType()) {
			case NO_PROPERTY:
			case Buff:
			case RollCall:
				return _myDropSpace->catchCard(card);
				break;

			case Spy:
				return _enemyDropSpace->catchCard(card);
				break;
		}

	return 0;
}
