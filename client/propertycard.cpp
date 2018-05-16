#include "propertycard.h"

PropertyCard::PropertyCard(int id, QString info, Property_type property_type):
    AbstractCard(id, info),
    _property_type(property_type)
{

}

Entity_type PropertyCard::getEntityType()
{
    return NO_ENTITY;
}

Property_type PropertyCard::getPropertyType()
{
    return _property_type;
}


int PropertyCard::getStrength()
{
    return 0;
}
void PropertyCard::setStrength(int strength) {}
