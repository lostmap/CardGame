#include "entitycard.h"

EntityCard::EntityCard(int id, QString info, Entity_type entity_type, int strength):
    AbstractCard(id, info),
    _entity_type(entity_type),
    _strength(strength)
{

}

Entity_type EntityCard::getEntityType()
{
    return _entity_type;
}

Property_type EntityCard::getPropertyType()
{
    return NO_PROPERTI;
}


int EntityCard::getStrength()
{
    return _strength;
}
void EntityCard::setStrength(int strength)
{
    _strength = strength;
}
