#include "entity.h"
#include "config.h"


Entity::Entity(int id, std::string info, ENTITY_TYPE entity_type, int strength):
    AbstractCard(id, info),
    _entity_type(entity_type),
     _strength(strength)
{

}

PROPERTY_TYPE Entity::getPropertyType() const
{
    return NO_PROPERTY;
}

int Entity::getStrength() const
{
    return _strength;
}

void Entity::setStrength(int strength)
{
    _strength = strength;
}

ENTITY_TYPE Entity::getEntityType() const
{
    return _entity_type;
}
