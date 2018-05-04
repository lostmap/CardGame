#include "entity.h"

Entity::Entity(int strength):
    _strength(strength)
{

}

int Entity::getStrength()
{
    return _strength;
}

void Entity::setStrength(int strength)
{
    _strength = strength;
}
