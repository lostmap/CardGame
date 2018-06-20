#ifndef SFMLCARD_H
#define SFMLCARD_H

#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <memory>

#include "config.h"

class SfmlCard {

public:
	SfmlCard(float x, float y, Entity_type entity_typy, Property_type property_type);
	virtual ~SfmlCard() {};

	virtual void update(float time) = 0;

	bool contains(float x, float y);
	sf::FloatRect getGlobalBounds();

	void setPosition(sf::Vector2f);
	
	void draw(std::shared_ptr<sf::RenderWindow> window);
	
	sf::Sprite getSprite();
	void setColor(sf::Color color);

	void setSize(int width, int height, int offsetX, int offsetY, int charachterSize);

	void setX(float x);
	void setY(float y);
	void setCenter(float x, float y);

	void move(float x, float y);
	void drop();

	void hold();

	void setS();
	void setM();
	void setL();


	sf::Vector2f getPosition();
	sf::Vector2f getCenter();

	void setOffset(int offsetX, int offsetY, int charachterSize = 0);
	void setStrengthText(int);
	void setStrengthTextPosition();
	void strengthS();
	void strengthM();
	void strengthL();

	

private:
	float _dx;
	float _dy;
	float _x;
	float _y;
	float _currentX;
	float _currentY;
	float _speed;
	float _moveTimer;

	int _width;
	int _height;

	sf::Text _strengthText;
	float _strengthOffsetX;
	float _strengthOffsetY;
	sf::Font font;

	sf::Image _imageS;
	sf::Texture _textureS;

	sf::Image _imageM;
	sf::Texture _textureM;

	sf::Image _imageL;
	sf::Texture _textureL;

	sf::Sprite _currentSprite;

};

#endif
