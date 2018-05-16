#include "entityfactory.h"
#include "entity.h"

EntityFactory::EntityFactory()
{

}

AbstractCard *EntityFactory::createCard(QString info, Entity_type entity_type, int strength)
{
    return new Entity(cards++, info, entity_type, strength);
}
