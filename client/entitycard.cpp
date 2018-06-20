#include "entitycard.h"

EntityCard::EntityCard(int id, std::string info, Entity_type entity_type, 
	int strength, float x, float y):

    AbstractCard(id, info, x, y, entity_type),
    _entity_type(entity_type),
    _strength(strength)
{
	setStrengthText(strength);
}

Entity_type EntityCard::getEntityType()
{
    return _entity_type;
}


Property_type EntityCard::getPropertyType()
{
    return NO_PROPERTY;
}


int EntityCard::getStrength()
{
    return _strength;
}
void EntityCard::setStrength(int strength)
{
    _strength = strength;
    setStrengthText(strength);
}

void EntityCard::update(float time) {

}
