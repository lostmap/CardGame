#include "info.h"

#include "config.h"
#include "entitywithpropertycard.h"
#include "log.h"

Info::Info() {
	if (!_font.loadFromFile(Config::Instance().INFO_FONT)){
		Log::Instance().log("couldn't load info font");
	}

	_infoText.setFont(_font);
	_infoText.setCharacterSize(10);
	_infoText.setPosition(Config::Instance().INFO.X, Config::Instance().INFO.Y + Config::Instance().LARGE.HEIGHT);
}


void Info::draw(std::shared_ptr<sf::RenderWindow> window, 
				std::shared_ptr<AbstractCard> card1, 
				std::shared_ptr<AbstractCard> card2) {
	
	std::shared_ptr<AbstractCard> card = nullptr;
	if (card2)
		card = card2;

	if (card1)
		card = card1;

	if (card) {
		
		auto newCard  = std::shared_ptr<AbstractCard>(new EntityWithPropertyCard(100, card->getInfo(),
		card->getEntityType(), card->getStrength(), NO_PROPERTY, Config::Instance().INFO.X, Config::Instance().INFO.Y));
		

		_infoText.setString(newCard->getInfo());
		newCard->setL();
		newCard->draw(window);
		window->draw(_infoText);
	}
	
	
}