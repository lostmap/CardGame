#ifndef INTERLAYER_H
#define INTERLAYER_H


#include <string>
#include "game.h"
#include "client.h"

class InterLayer
{
public:
    InterLayer(std::shared_ptr<Game> , std::shared_ptr <Client>);

    void parseData(std::string xml);
    void sendCard(int id);
    void sendStart();
    void sendSignIn(std::string login, std::string password);
    void sendPass();
    void update();

private:
    std::shared_ptr <Client> _client;
    std::shared_ptr<Game> _game;

    void _parseCard();

	// вот отсюда можно возвращать колоду
	void _parseDeck();

	// отсюда можно возвращать карту в
	void _parseNode();
};

#endif // INTERLAYER_H
