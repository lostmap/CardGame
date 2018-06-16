#include "config.h"

Config::Config(const std::string& filename):
    _xml(ConfigParser(filename)),
    _entityInfo(_xml.getEntitiesInfo()),
    _propertyInfo(_xml.getPropertiesInfo()),
    PORT(_xml.getPort()),
    HAND_SIZE(_xml.getHandSize()),
    DECK_SIZE(_xml.getDeckSize()),
    MAX_STRENGTH(_xml.getMaxStrength()),
    BUFF_RATE(_xml.getBuffRate()),
    WIN_SCORE(_xml.getWinScore())

{}

std::string Config::getInfo(ENTITY_TYPE entityType) const
{
   return _entityInfo.at(entityType);
}

std::string Config::getInfo(PROPERTY_TYPE propertyType) const
{
    return _propertyInfo.at(propertyType);
}

std::string Config::getInfo(ENTITY_TYPE entityType, PROPERTY_TYPE propertyType) const
{
    return getInfo(entityType) + getInfo(propertyType);
}
