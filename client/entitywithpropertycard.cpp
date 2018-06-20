#include "entitywithpropertycard.h"
#include <iostream>

EntityWithPropertyCard::EntityWithPropertyCard(int id, std::string info, Entity_type entity_type,
                           int strength, Property_type property_type, float x, float y):
    EntityCard(id, info, entity_type, strength, x, y),
    PropertyCard(id, info, property_type, x, y),
    AbstractCard(id, info, x, y, entity_type, property_type)

{
	setStrengthText(strength);
}

Entity_type EntityWithPropertyCard::getEntityType()
{
    return EntityCard::getEntityType();
}
int EntityWithPropertyCard::getStrength()
{
    return EntityCard::getStrength();
}

void EntityWithPropertyCard::setStrength(int strength)
{
    EntityCard::setStrength(strength);
}
Property_type EntityWithPropertyCard::getPropertyType()
{
    return PropertyCard::getPropertyType();
}

void EntityWithPropertyCard::update(float time)
{
    
}