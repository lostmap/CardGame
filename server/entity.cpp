#include "entity.h"
#include "define.h"


Entity::Entity(int id, QString info, Entity_type entity_type, int strength):
    AbstractCard(id, info),
    _entity_type(entity_type),
     _strength(strength)
{

}

Property_type Entity::property(Deck* deck)
{
    return NO_PROPERTI;
}

int Entity::getStrength()
{
    return _strength;
}

void Entity::setStrength(int strength)
{
    _strength = strength;
}

Entity_type Entity::getEntityType()
{
    return _entity_type;
}
