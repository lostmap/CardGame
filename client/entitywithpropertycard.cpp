#include "entitywithpropertycard.h"

EntityWithPropertyCard::EntityWithPropertyCard(int id, QString info, Entity_type entity_type,
                                               int strength, Property_type property_type):
    EntityCard(id, info, entity_type, strength),
    PropertyCard(id, info, property_type),
    AbstractCard(id, info)

{

}

Entity_type EntityWithPropertyCard::getEntityType()
{
    return PropertyCard::getEntityType();
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
