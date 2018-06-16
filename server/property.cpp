#include "property.h"
#include "config.h"

Property::Property(int id, PROPERTY_TYPE property_type, std::string info):
    AbstractCard(id, info),
    _property_type(property_type)
{

}

int Property::getStrength() const
{
    return 0;
}
void Property::setStrength(int strength) {}

PROPERTY_TYPE Property::getPropertyType() const
{
    return _property_type;
}

ENTITY_TYPE Property::getEntityType() const
{
    return NO_ENTITY;
}
