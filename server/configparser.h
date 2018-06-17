#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

namespace pugi {
    class xml_document;
}

#include <string>
#include <map>
#include <memory>

enum PROPERTY_TYPE: int;
enum ENTITY_TYPE: int;

class ConfigParser
{
public:
    explicit ConfigParser(std::string xml);
    ~ConfigParser();

    int getPort() const;
    int getHandSize() const;
    int getDeckSize() const;
    int getMaxStrength() const;
    int getBuffRate() const;
    int getWinScore() const;
    std::map<ENTITY_TYPE, std::string> getEntitiesInfo() const;
    std::map<PROPERTY_TYPE, std::string> getPropertiesInfo() const;

private:
    std::shared_ptr<pugi::xml_document> doc;

  int _parseGetInt2(std::string ancestor, std::string parent) const;
};

#endif // CONFIGPARSER_H
