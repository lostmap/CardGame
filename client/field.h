#ifndef FIELD_H
#define FIELD_H

#include "dropspace.h"
#include "abstractcard.h"

#include <memory>

class Field {

public:
	Field();
	~Field();

	void draw(std::shared_ptr<sf::RenderWindow> window);
	int catchCard(std::shared_ptr<AbstractCard>);
	void addCardToMe(std::shared_ptr<AbstractCard>);
	void addCardToEnemy(std::shared_ptr<AbstractCard>);
	std::shared_ptr<AbstractCard> contains(sf::Vector2i mouse);
	void setBlocked();
	void unblock();

private:
	std::shared_ptr<DropSpace> _myDropSpace;
	std::shared_ptr<DropSpace> _enemyDropSpace;
	bool _blocked;
};



#endif // FIELD_H