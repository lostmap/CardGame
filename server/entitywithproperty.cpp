#include "entitywithproperty.h"

EntityWithProperty::EntityWithProperty(int id, QString info, Entity_type entity_type,
                                       int strength, Property_type property_type):
    AbstractCard(id, info),
    _entity_type(entity_type),
    _strength(strength),
    _property_type(property_type)
{

}

Entity_type EntityWithProperty::getEntityType()
{
    return _entity_type;
}

int EntityWithProperty::getStrength()
{
   return _strength;
}

void EntityWithProperty::setStrength(int strength)
{
    _strength = strength;
}

Property_type EntityWithProperty::getPropertyType()
{
    return _property_type;
}
