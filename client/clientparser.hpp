#ifndef clientparser_hpp
#define clientparser_hpp

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <map>
#include "pugixml.hpp"

using std::vector;
using std::string;
using std::map;

struct Card {
  const string IMG_S;
  const string IMG_M;
  const string IMG_L;
  Card(string _img_s = "default", string _img_m = "default", string _img_l = "default")
  : IMG_S(_img_s), IMG_M(_img_m), IMG_L(_img_l) {}
};

struct CardProperty {
  const int SPACE;
  const int FIELD_SIDE_SPACE;
  const int FIELD_DOWN_SPACE;
  CardProperty(int _space, int _field_side_space, int _field_down_space)
  : SPACE(_space), FIELD_SIDE_SPACE(_field_side_space), FIELD_DOWN_SPACE(_field_down_space) {}
};

struct Cords {
  const int X;
  const int Y;
  Cords(int _x, int _y)
  : X(_x), Y(_y) {}
};

struct CordsSize {
  const int X;
  const int Y;
  const int WIDTH;
  const int HEIGHT;
  CordsSize(int _x, int _y, int _width, int _height)
  : X(_x), Y(_y), WIDTH(_width), HEIGHT(_height) {}
};

struct CardParamStrength{
  const int OFFSET_X;
  const int OFFSET_Y;
  const int SIZE;
  CardParamStrength(int _offset_x, int _offset_y, int _size)
  : OFFSET_X(_offset_x), OFFSET_Y(_offset_y), SIZE(_size) {}
};

struct CardParam {
  const int WIDTH;
  const int HEIGHT;
  const CardParamStrength STRENGTH;
  CardParam(int _width, int _height, CardParamStrength _strength)
  : WIDTH(_width), HEIGHT(_height), STRENGTH(_strength) {}
};

class ClientParsed {
public:
  explicit ClientParsed(std::string xml);
  CardProperty GetCardProperty() const;
  CardParam GetSmall() const;
  CardParam GetMedium() const;
  CardParam GetLarge() const;
  CordsSize GetMySpace() const;
  CordsSize GetEnemySpace() const;
  Cords GetEnemyArea() const;
  Cords GetInfo() const;
  Cords GetDeck() const;
  std::map<std::string, Card> GetCards() const;
  std::string GetInfoFont() const;
  std::string GetStrengthFont() const;
  std::string GetAddress() const;
  int GetPort() const;
  int GetDropAreaQuantity() const;
private:
  pugi::xml_document doc;
};

#endif /* clientparser_hpp */
