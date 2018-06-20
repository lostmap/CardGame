#ifndef DROPAREA_H
#define DROPAREA_H

#include "abstractcard.h"
#include <SFML/Graphics.hpp>
#include "config.h"

#include <memory>

class DropArea {

public:

	DropArea(int x, int y);
	~DropArea();
	void addCard(std::shared_ptr<AbstractCard>);
	void removeCard();
	bool isFree();
	bool isIntersect(std::shared_ptr<AbstractCard>);
	void setColor(sf::Color);
	std::shared_ptr<AbstractCard> contains(sf::Vector2i mouse);

	int getId();
	int getStrength();
	void setStrength(int);

	void draw(std::shared_ptr<sf::RenderWindow> window);
	bool catchCard(std::shared_ptr<AbstractCard>);
	

private:
	//sf::Image _image;
	//sf::Texture _texture;
	sf::Sprite _sprite;

	std::shared_ptr<AbstractCard> _card;
};



#endif