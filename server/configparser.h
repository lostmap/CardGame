#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include "pugixml.h"
#include "pugiconfig.h"

#include <string>
#include <map>

enum PROPERTY_TYPE: int;
enum ENTITY_TYPE: int;

class ConfigParser
{
public:
    explicit ConfigParser(std::string xml);

    int getPort() const;
    int getHandSize() const;
    int getDeckSize() const;
    int getMaxStrength() const;
    int getBuffRate() const;
    int getWinScore() const;
    std::map<ENTITY_TYPE, std::string> getEntitiesInfo() const;
    std::map<PROPERTY_TYPE, std::string> getPropertiesInfo() const;

private:
  pugi::xml_document doc;

  int _parseGetInt2(std::string ancestor, std::string parent) const;
};

#endif // CONFIGPARSER_H
