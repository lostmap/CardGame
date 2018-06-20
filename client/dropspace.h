#ifndef DROPSPACE_H
#define DROPSPACE_H

#include "droparea.h"
#include "abstractcard.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class DropSpace {

public:
	DropSpace(int x, int y, int width, int height, int qyantity);
	~DropSpace();

	size_t size();

	void addCard(std::shared_ptr<AbstractCard>);
	void draw(std::shared_ptr<sf::RenderWindow>);
	bool catchCard(std::shared_ptr<AbstractCard>);
	void updateStrength(std::shared_ptr <DropArea> area, std::shared_ptr<AbstractCard> card);
	std::shared_ptr<DropArea> findByCardId(int cardId);
	std::shared_ptr<AbstractCard> contains(sf::Vector2i mouse);


private:
	std::vector<std::shared_ptr<DropArea>> _dropArray;
};


#endif
