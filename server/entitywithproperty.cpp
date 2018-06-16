#include "entitywithproperty.h"

EntityWithProperty::EntityWithProperty(int id, std::string info, ENTITY_TYPE entity_type,
                                       int strength, PROPERTY_TYPE property_type):
    AbstractCard(id, info),
    _entity_type(entity_type),
    _strength(strength),
    _property_type(property_type)
{

}

ENTITY_TYPE EntityWithProperty::getEntityType() const
{
    return _entity_type;
}

int EntityWithProperty::getStrength() const
{
   return _strength;
}

void EntityWithProperty::setStrength(int strength)
{
    _strength = strength;
}

PROPERTY_TYPE EntityWithProperty::getPropertyType() const
{
    return _property_type;
}
