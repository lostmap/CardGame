#include "interlayer.h"
#include <iostream>
#include <cassert>
#include <vector>
#include "pugixml.hpp"

#include "client.h"
#include "game.h"
#include "entitywithpropertycard.h"
#include "config.h"
#include "abstractcard.h"

#include <memory>

InterLayer::InterLayer(std::shared_ptr<Game> game, std::shared_ptr <Client> client):
    _client(client), _game(game)
{

  _game->startParty();
  _client->sendStart();


}

void InterLayer::update() {
  std::string data = _client->getMessage();
  if(data != "")
      parseData(data);
      
}


void InterLayer::parseData(std::string xml)
{
   pugi::xml_document doc;
  //pugi::xml_parse_result result = doc.load_file(xml.c_str()); use for filenames
  pugi::xml_parse_result result = doc.load_string(xml.c_str());
  assert(result);
  pugi::xml_node server = doc.child("server");

  // tutn must be first
  _game->setTurn(server.child("turn").text().as_int());
  _game->setWin(server.child("win").text().as_int());

  pugi::xml_node mecard = server.child("me").child("me");
  _game->setPlayerInfo(mecard.child("stagescore").text().as_int(),
               mecard.child("score").text().as_int(),
               mecard.child("handsize").text().as_int(),
               mecard.child("pass").text().as_int());
  
  pugi::xml_node cards = server.child("me").child("hand");
  for (pugi::xml_node card: cards.children("card"))
  {
    auto newCard = std::shared_ptr<AbstractCard>(new EntityWithPropertyCard(card.child("id").text().as_int(),
                card.child("info").text().as_string(),
                (Entity_type)card.child("type").text().as_uint(),
                card.child("strength").text().as_int(),
                (Property_type)card.child("propertytype").text().as_uint()));
    _game->addHeandCard(newCard);
  }
  
  pugi::xml_node partcard = server.child("partner");
  _game->setPartnerInfo(partcard.child("stagescore").text().as_int(),
                 partcard.child("score").text().as_int(),
                 partcard.child("heandsize").text().as_int(),
                 partcard.child("pass").text().as_int());
  
  pugi::xml_node partcards = server.child("field").child("partner");
  
  for (pugi::xml_node card: partcards.children("card"))
  {
    auto newCard = std::shared_ptr<AbstractCard>(new EntityWithPropertyCard(card.child("id").text().as_int(),
                card.child("info").text().as_string(),
                (Entity_type)card.child("type").text().as_uint(),
                card.child("strength").text().as_int(),
                (Property_type)card.child("propertytype").text().as_uint()));
    _game->addCardToEnemy(newCard);
  }

  pugi::xml_node mycards = server.child("field").child("mycards");
  for (pugi::xml_node card: mycards.children("card"))
  {
    auto newCard = std::shared_ptr<AbstractCard>(new EntityWithPropertyCard(card.child("id").text().as_int(),
                card.child("info").text().as_string(),
                (Entity_type)card.child("type").text().as_int(),
                card.child("strength").text().as_int(),
                (Property_type)card.child("propertytype").text().as_int()));
    _game->addCardToMe(newCard);
  } 



}

void InterLayer::sendCard(int id)
{
    _client->sendCard(id);
}

void InterLayer::sendStart()
{
    _client->sendStart();
}

void InterLayer::sendSignIn(std::string login, std::string password)
{
    _client->sendSignIn(login, password);
}

void InterLayer::sendPass()
{
    _client->sendPass();
}
