#include "droparea.h"


DropArea::DropArea(int _x, int _y): 
				_card(nullptr)
{

	_sprite.setTextureRect(sf::IntRect(0, 0, Config::Instance().SMALL.WIDTH,
											 Config::Instance().SMALL.HEIGHT)); 
	_sprite.setPosition(_x, _y); 
}


DropArea::~DropArea() {
	
}


void DropArea::addCard(std::shared_ptr<AbstractCard> card) {
	_card = card;
	_card->drop();
	_card->setS();
	_card->setPosition(_sprite.getPosition());
}

int DropArea::getId(){
	if (_card)
		return _card->getId();
	return -1;
}

int DropArea::getStrength() {
	if (_card)
		return _card->getStrength();
	return -1;
}
	

void DropArea::setStrength(int strength) {
	if (_card)
		_card->setStrength(strength);
}

std::shared_ptr<AbstractCard> DropArea::contains(sf::Vector2i mouse) {
	if (_card)
		if (_card->contains(mouse.x, mouse.y)){
			return _card;
		}

	return nullptr;
}

bool DropArea::catchCard(std::shared_ptr<AbstractCard> card) {
	
	if (_card) {
		return false;
	}
	else {

		if (isIntersect(card)) {
			_card = card;
			_card->drop();
			_card->setS();
			_card->setPosition(_sprite.getPosition());
		}

		return (_card != nullptr);
	}
}

void DropArea::removeCard() {
	_card = nullptr;
}

bool DropArea::isFree() {
	return !_card;
}
void DropArea::setColor(sf::Color color) {
	_sprite.setColor(color);
}

bool DropArea::isIntersect(std::shared_ptr<AbstractCard> card) {
	if (!_card){
		int cardCenterX = card->getCenter().x;
		int cardCenterY = card->getCenter().y;
		sf::FloatRect cardCenter(cardCenterX - Config::Instance().SMALL.WIDTH / 2,
								cardCenterY - Config::Instance().SMALL.HEIGHT / 2,
								Config::Instance().SMALL.WIDTH,
								Config::Instance().SMALL.HEIGHT);
		
		bool intersect = _sprite.getGlobalBounds().intersects(cardCenter);

		if (intersect)
			setColor(sf::Color(153, 153, 102, 50));
		else
			setColor(sf::Color::White);
		return intersect;
	}
	return false;


}

void DropArea::draw(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(_sprite);
	if (_card)
		_card->draw(window);
}