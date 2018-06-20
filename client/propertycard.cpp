#include "propertycard.h"

PropertyCard::PropertyCard(int id, std::string info, Property_type property_type,
	float x, float y):
    AbstractCard(id, info, x, y, NO_ENTITY, property_type),
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

void PropertyCard::update(float time) {
	
}
