#include "sfmlcard.h"
#include <iostream>
#include <iomanip>

#include "log.h"

SfmlCard::SfmlCard(float x, float y, Entity_type entity_type = NO_ENTITY, 
									 Property_type property_type = NO_PROPERTY):
				_dx(0), _dy(0), 
				_x(x), _y(y),
				_currentX(x), _currentY(y),
				_speed(0),_moveTimer(0), 
				_width(Config::Instance().MEDIUM.WIDTH), _height(Config::Instance().MEDIUM.HEIGHT),
				_strengthOffsetX(Config::Instance().MEDIUM.STRENGTH.OFFSET_X),
				_strengthOffsetY(Config::Instance().MEDIUM.STRENGTH.OFFSET_Y)
{

	
	
	struct PathStruct {
		std::string S = Config::Instance().CARDS.at("default").IMG_S;
		std::string M = Config::Instance().CARDS.at("default").IMG_M;
		std::string L = Config::Instance().CARDS.at("default").IMG_L;
		
		void setPath(std::string s_path, std::string m_path, std::string l_path) {
					S = s_path;
					M = m_path;
					L = l_path;
				}
	} path;

	
	switch (entity_type) {
		case(BEAR): 
			path.setPath(Config::Instance().CARDS.at("bear").IMG_S, Config::Instance().CARDS.at("bear").IMG_M, Config::Instance().CARDS.at("bear").IMG_L);
			break;

		case(AGLAIS): 
			path.setPath(Config::Instance().CARDS.at("aglais").IMG_S, Config::Instance().CARDS.at("aglais").IMG_M, Config::Instance().CARDS.at("aglais").IMG_L);
			break;

		case(BLUE_BOY): 
			path.setPath(Config::Instance().CARDS.at("blueboy").IMG_S, Config::Instance().CARDS.at("blueboy").IMG_M, Config::Instance().CARDS.at("blueboy").IMG_L);
			break;

		case(CERYS): 
			path.setPath(Config::Instance().CARDS.at("cerys").IMG_S, Config::Instance().CARDS.at("cerys").IMG_M, Config::Instance().CARDS.at("cerys").IMG_L);
			break;

		case(CIRI): 
			path.setPath(Config::Instance().CARDS.at("ciri").IMG_S, Config::Instance().CARDS.at("ciri").IMG_M, Config::Instance().CARDS.at("ciri").IMG_L);
			break;

		case(CORAL): 
			path.setPath(Config::Instance().CARDS.at("coral").IMG_S, Config::Instance().CARDS.at("coral").IMG_M, Config::Instance().CARDS.at("coral").IMG_L);
			break;

		case(EITHNEL): 
			path.setPath(Config::Instance().CARDS.at("eithnel").IMG_S, Config::Instance().CARDS.at("eithnel").IMG_M, Config::Instance().CARDS.at("eithnel").IMG_L);
			break;

		case(EMISSARY): 
			path.setPath(Config::Instance().CARDS.at("emissary").IMG_S, Config::Instance().CARDS.at("emissary").IMG_M, Config::Instance().CARDS.at("emissary").IMG_L);
			break;

		case(ENCHANT): 
			path.setPath(Config::Instance().CARDS.at("enchant").IMG_S, Config::Instance().CARDS.at("enchant").IMG_M, Config::Instance().CARDS.at("enchant").IMG_L);
			break;

		case(EREDIN): 
			path.setPath(Config::Instance().CARDS.at("eredin").IMG_S, Config::Instance().CARDS.at("eredin").IMG_M, Config::Instance().CARDS.at("eredin").IMG_L);
			break;

		case(GERALT): 
			path.setPath(Config::Instance().CARDS.at("geralt").IMG_S, Config::Instance().CARDS.at("geralt").IMG_M, Config::Instance().CARDS.at("geralt").IMG_L);
			break;

		case(GREEN): 
			path.setPath(Config::Instance().CARDS.at("green").IMG_S, Config::Instance().CARDS.at("green").IMG_M, Config::Instance().CARDS.at("green").IMG_L);
			break;

		case(IDA): 
			path.setPath(Config::Instance().CARDS.at("ida").IMG_S, Config::Instance().CARDS.at("ida").IMG_M, Config::Instance().CARDS.at("ida").IMG_L);
			break;

		case(IORVETH): 
			path.setPath(Config::Instance().CARDS.at("iorveth").IMG_S, Config::Instance().CARDS.at("iorveth").IMG_M, Config::Instance().CARDS.at("iorveth").IMG_L);
			break;

		case(KEIRA): 
			path.setPath(Config::Instance().CARDS.at("keira").IMG_S, Config::Instance().CARDS.at("keira").IMG_M, Config::Instance().CARDS.at("keira").IMG_L);
			break;

		case(LAMIA): 
			path.setPath(Config::Instance().CARDS.at("lamia").IMG_S, Config::Instance().CARDS.at("lamia").IMG_M, Config::Instance().CARDS.at("lamia").IMG_L);
			break;

		case(MORENN): 
			path.setPath(Config::Instance().CARDS.at("morenn").IMG_S, Config::Instance().CARDS.at("morenn").IMG_M, Config::Instance().CARDS.at("morenn").IMG_L);
			break;

		case(PIRATEL): 
			path.setPath(Config::Instance().CARDS.at("piratel").IMG_S, Config::Instance().CARDS.at("piratel").IMG_M, Config::Instance().CARDS.at("piratel").IMG_L);
			break;

		case(ROAR_BEAR): 
			path.setPath(Config::Instance().CARDS.at("roar_bear").IMG_S, Config::Instance().CARDS.at("roar_bear").IMG_M, Config::Instance().CARDS.at("roar_bear").IMG_L);
			break;

		case(SCOUT): 
			path.setPath(Config::Instance().CARDS.at("scout").IMG_S, Config::Instance().CARDS.at("scout").IMG_M, Config::Instance().CARDS.at("scout").IMG_L);
			break;

		case(SIREN): 
			path.setPath(Config::Instance().CARDS.at("siren").IMG_S, Config::Instance().CARDS.at("siren").IMG_M, Config::Instance().CARDS.at("siren").IMG_L);
			break;

		case(STENNIS): 
			path.setPath(Config::Instance().CARDS.at("stennis").IMG_S, Config::Instance().CARDS.at("stennis").IMG_M, Config::Instance().CARDS.at("stennis").IMG_L);
			break;

		case(SUPPORT): 
			path.setPath(Config::Instance().CARDS.at("support").IMG_S, Config::Instance().CARDS.at("support").IMG_M, Config::Instance().CARDS.at("support").IMG_L);
			break;

		case(TEMERIAN): 
			path.setPath(Config::Instance().CARDS.at("temerian").IMG_S, Config::Instance().CARDS.at("temerian").IMG_M, Config::Instance().CARDS.at("temerian").IMG_L);
			break;

		case(TRIDAM): 
			path.setPath(Config::Instance().CARDS.at("tridam").IMG_S, Config::Instance().CARDS.at("tridam").IMG_M, Config::Instance().CARDS.at("tridam").IMG_L);
			break;

		case(TRISS): 
			path.setPath(Config::Instance().CARDS.at("triss").IMG_S, Config::Instance().CARDS.at("triss").IMG_M, Config::Instance().CARDS.at("triss").IMG_L);
			break;

		case(YENNEFER): 
			path.setPath(Config::Instance().CARDS.at("yennefer").IMG_S, Config::Instance().CARDS.at("yennefer").IMG_M, Config::Instance().CARDS.at("yennefer").IMG_L);
			break;

		case(YOANA): 
			path.setPath(Config::Instance().CARDS.at("yoana").IMG_S, Config::Instance().CARDS.at("yoana").IMG_M, Config::Instance().CARDS.at("yoana").IMG_L);
			break;

		case(ZIGRIN): 
			path.setPath(Config::Instance().CARDS.at("zigrin").IMG_S, Config::Instance().CARDS.at("zigrin").IMG_M, Config::Instance().CARDS.at("zigrin").IMG_L);
			break;

		case(ZOLTAN): 
			path.setPath(Config::Instance().CARDS.at("zoltan").IMG_S, Config::Instance().CARDS.at("zoltan").IMG_M, Config::Instance().CARDS.at("zoltan").IMG_L);
			break;

	}

	

	if(!_imageS.loadFromFile(path.S))
        Log::Instance().log("couldnt load pathS");

	_textureS.loadFromImage(_imageS);

	if(!_imageM.loadFromFile(path.M))
        Log::Instance().log("couldnt load pathM");
	
	_textureM.loadFromImage(_imageM);


	if(!_imageL.loadFromFile(path.L))
        Log::Instance().log("couldnt load pathL");
	
	_textureL.loadFromImage(_imageL);

	if (!font.loadFromFile(Config::Instance().STRENGTH_FONT)){
		Log::Instance().log("Wrong font");
	}
	_strengthText.setFont(font);
	_strengthText.setString("10");
	_strengthText.setPosition(x + _strengthOffsetX, y + _strengthOffsetY);
	setM();

}


void SfmlCard::setPosition(sf::Vector2f vector) {
	setX(vector.x);
	setY(vector.y);
	setStrengthTextPosition();
}

void SfmlCard::setCenter(float x, float y) {
	_currentX = x - _width/2;
	_currentY = y - _height/2;
	setStrengthTextPosition();
}

void SfmlCard::move(float x, float y) {
	setCenter(x, y);
}

void SfmlCard::setSize(int width, int height, int offsetX, int offsetY, int characterSize) {
	_width = width;
	_height = height;
	_strengthOffsetX = offsetX;
	_strengthOffsetY = offsetY;
	_strengthText.setCharacterSize(characterSize);

}

void SfmlCard::setS() {

	_currentSprite.setTexture(_textureS);
	_currentSprite.setTextureRect(sf::IntRect(0, 0, Config::Instance().SMALL.WIDTH, Config::Instance().SMALL.HEIGHT)); 
	setSize(Config::Instance().SMALL.WIDTH, Config::Instance().SMALL.HEIGHT,
			Config::Instance().SMALL.STRENGTH.OFFSET_X, Config::Instance().SMALL.STRENGTH.OFFSET_Y,
			Config::Instance().SMALL.STRENGTH.SIZE);
	setStrengthTextPosition();
}

void SfmlCard::setM() {

	_currentSprite.setTexture(_textureM);
	_currentSprite.setTextureRect(sf::IntRect(0, 0, Config::Instance().MEDIUM.WIDTH, Config::Instance().MEDIUM.HEIGHT));
	setSize(Config::Instance().MEDIUM.WIDTH, Config::Instance().MEDIUM.HEIGHT,
			Config::Instance().MEDIUM.STRENGTH.OFFSET_X, Config::Instance().MEDIUM.STRENGTH.OFFSET_Y,
			Config::Instance().MEDIUM.STRENGTH.SIZE);
	setStrengthTextPosition();

}

void SfmlCard::setL() {

	_currentSprite.setTexture(_textureL);
	_currentSprite.setTextureRect(sf::IntRect(0, 0, Config::Instance().LARGE.WIDTH, Config::Instance().LARGE.HEIGHT));
	setSize(Config::Instance().LARGE.WIDTH, Config::Instance().LARGE.HEIGHT,
	 		Config::Instance().LARGE.STRENGTH.OFFSET_X, Config::Instance().LARGE.STRENGTH.OFFSET_Y,
	 		Config::Instance().LARGE.STRENGTH.SIZE);
	setStrengthTextPosition();
}

void SfmlCard::setStrengthTextPosition() {

	_strengthText.setPosition(_currentX + _strengthOffsetX, _currentY + _strengthOffsetY);
}

void SfmlCard::setOffset(int offsetX, int offsetY, int characterSize) {
	if (characterSize)
		_strengthText.setString("10");
	
	_strengthOffsetX = offsetX;
	_strengthOffsetY = offsetY;
	setStrengthTextPosition();

}


void SfmlCard::hold() {
	setL();
}


bool SfmlCard::contains(float x, float y) {
	return _currentSprite.getGlobalBounds().contains(x, y);
}

sf::FloatRect SfmlCard::getGlobalBounds() {
	return _currentSprite.getGlobalBounds();
}


void SfmlCard::setColor(sf::Color color) {
	_currentSprite.setColor(color);
}


void SfmlCard::setX(float x) {
	_x = x;
	_currentX = _x;
}

void SfmlCard::setStrengthText(int strength) {
	_strengthText.setString(std::to_string(strength));
}


void SfmlCard::setY(float y) {
	_y = y;
	_currentY = _y;
}


sf::Vector2f SfmlCard::getPosition() {
	return _currentSprite.getPosition();
}

sf::Vector2f SfmlCard::getCenter() {
	return sf::Vector2f(_currentSprite.getPosition().x + _width/2,
						_currentSprite.getPosition().y + _height/2);
}


void SfmlCard::draw(std::shared_ptr<sf::RenderWindow> window)
{
	_currentSprite.setPosition(_currentX, _currentY);
	window->draw(_currentSprite);
	window->draw(_strengthText);
}

void SfmlCard::drop() {
	_currentX = _x;
	_currentY = _y;
	setM();

}

sf::Sprite SfmlCard::getSprite()
{
	return _currentSprite;
}