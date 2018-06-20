#include "clientparser.hpp"

ClientParsed::ClientParsed(std::string xml) {
  pugi::xml_parse_result result = doc.load_file(xml.c_str()); //use for filenames
  //pugi::xml_parse_result result = doc.load_string(xml.c_str());
  assert(result);
}

CardProperty ClientParsed::GetCardProperty() const {
  pugi::xml_node cardproperty = doc.child("client").child("card");
  return CardProperty(cardproperty.child("space").text().as_int(),
                      cardproperty.child("field_side_space").text().as_int(),
                      cardproperty.child("field_down_space").text().as_int());
}

CardParam ClientParsed::GetSmall() const {
  pugi::xml_node small = doc.child("client").child("small");
  pugi::xml_node strength = small.child("strength");
  return CardParam(small.child("width").text().as_int(),
                   small.child("height").text().as_int(),
                   CardParamStrength(strength.child("offset_x").text().as_int(),
                                     strength.child("offset_y").text().as_int(),
                                     strength.child("size").text().as_int()));
}

CardParam ClientParsed::GetMedium() const {
  pugi::xml_node medium = doc.child("client").child("medium");
  pugi::xml_node strength = medium.child("strength");
  return CardParam(medium.child("width").text().as_int(),
                   medium.child("height").text().as_int(),
                   CardParamStrength(strength.child("offset_x").text().as_int(),
                                     strength.child("offset_y").text().as_int(),
                                     strength.child("size").text().as_int()));
}

CardParam ClientParsed::GetLarge() const {
  pugi::xml_node large = doc.child("client").child("large");
  pugi::xml_node strength = large.child("strength");
  return CardParam(large.child("width").text().as_int(),
                   large.child("height").text().as_int(),
                   CardParamStrength(strength.child("offset_x").text().as_int(),
                                     strength.child("offset_y").text().as_int(),
                                     strength.child("size").text().as_int()));
}

CordsSize ClientParsed::GetMySpace() const {
  pugi::xml_node my = doc.child("client").child("my_space");
  return CordsSize(my.child("x").text().as_int(),
                   my.child("y").text().as_int(),
                   my.child("width").text().as_int(),
                   my.child("height").text().as_int());
}

CordsSize ClientParsed::GetEnemySpace() const {
  pugi::xml_node enemy = doc.child("client").child("enemy_space");
  return CordsSize(enemy.child("x").text().as_int(),
                   enemy.child("y").text().as_int(),
                   enemy.child("width").text().as_int(),
                   enemy.child("height").text().as_int());
}

Cords ClientParsed::GetEnemyArea() const {
  pugi::xml_node enemyarea = doc.child("client").child("enemyarea");
  return Cords(enemyarea.child("x").text().as_int(),
               enemyarea.child("y").text().as_int());
}

Cords ClientParsed::GetInfo() const {
  pugi::xml_node info = doc.child("client").child("info");
  return Cords(info.child("x").text().as_int(),
               info.child("y").text().as_int());
}

Cords ClientParsed::GetDeck() const {
  pugi::xml_node deck = doc.child("client").child("deck");
  return Cords(deck.child("x").text().as_int(),
               deck.child("y").text().as_int());
}

std::map<std::string, Card> ClientParsed::GetCards() const {
  std::map<std::string, Card> buff;
  pugi::xml_node cards = doc.child("client").child("cards");
  for (pugi::xml_node card: cards.children("card")) {
    buff.insert(std::make_pair(card.attribute("name").value(),
                               Card(card.child("img_s").text().as_string(),
                                    card.child("img_m").text().as_string(),
                                    card.child("img_l").text().as_string())));
  }
  return buff;
}

std::string ClientParsed::GetInfoFont() const {
  return doc.child("client").child("info_font").text().as_string();
}

std::string ClientParsed::GetStrengthFont() const {
  return doc.child("client").child("strength_font").text().as_string();
}

int ClientParsed::GetDropAreaQuantity() const {
  return doc.child("client").child("drop_area_quantity").text().as_int();
}

std::string ClientParsed::GetAddress() const {
  return doc.child("client").child("address").text().as_string();
}

int ClientParsed::GetPort() const {
  return doc.child("client").child("port").text().as_int();
}

