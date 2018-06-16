#include "propertyfactory.h"
#include "property.h"

PropertyFactory::PropertyFactory()
{

}

std::shared_ptr<AbstractCard> PropertyFactory::createCard(ENTITY_TYPE entity_type, int strength, PROPERTY_TYPE property_type)
{
    return std::shared_ptr<AbstractCard>(new Property(cards++, property_type, Config::Instance().getInfo(property_type)));
}
