#include "dropspace.h"
#include "config.h"

#include <iostream>
#include <cstdlib>


DropSpace::DropSpace(int x, int y, int width, int height, int quantity) {

	int offsetX = 0, offsetY = y;
	for (int i = 0; i < quantity; ++i) {
		offsetX = x  + i * (Config::Instance().SMALL.WIDTH
		 					+ Config::Instance().CARD.FIELD_SIDE_SPACE) % width;
		offsetY = y + i * (Config::Instance().SMALL.WIDTH
							+ Config::Instance().CARD.FIELD_SIDE_SPACE)
							/ width * (Config::Instance().CARD.FIELD_SIDE_SPACE
							+ Config::Instance().SMALL.HEIGHT);
		_dropArray.push_back(std::make_shared<DropArea>(offsetX, offsetY));
	}
}


DropSpace::~DropSpace() {
}

size_t DropSpace::size() {
	return _dropArray.size();
}


std::shared_ptr<AbstractCard> DropSpace::contains(sf::Vector2i mouse) {
	for (auto area :_dropArray){
		auto card = area->contains(mouse);
        if (card)
           return card;
	}

    return nullptr;
}

std::shared_ptr<DropArea>  DropSpace::findByCardId(int cardId)
{
    for (auto area: _dropArray)
    {
        if (area->getId() == cardId)
            return area;
    }
   return nullptr;
}

void DropSpace::updateStrength(std::shared_ptr<DropArea> area, std::shared_ptr<AbstractCard> card) {
	area->setStrength(card->getStrength());
}


void DropSpace::addCard(std::shared_ptr<AbstractCard> card) {
	auto area = findByCardId(card->getId());
	if (area) {
		updateStrength(area, card);
	}
	else {
		while(true) {
			std::srand(unsigned(std::time(0)));
			int areaIndex = std::rand()%size();
			if(_dropArray[areaIndex]->isFree()){
				_dropArray[areaIndex]->addCard(card);
				break;
			}
		}

	}

}

void DropSpace::draw(std::shared_ptr<sf::RenderWindow> window) {
	for (auto area: _dropArray)
		area->draw(window);
}

bool DropSpace::catchCard(std::shared_ptr<AbstractCard> card) {
	for (auto area: _dropArray)
		if (area->catchCard(card))
			return true;
	return false;
}

