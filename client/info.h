#ifndef INFO_H
#define INFO_H

#include "abstractcard.h"
#include <string>
#include "config.h"

#include <memory>

class Info
{
public:
    Info();
    ~Info() {}

	void draw(std::shared_ptr<sf::RenderWindow> window, 
		std::shared_ptr<AbstractCard> card1, 
		std::shared_ptr<AbstractCard> card2);

private:
	sf::Text _infoText;
	sf::Font _font;
};

#endif