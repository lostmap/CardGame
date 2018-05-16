#include "entityspyfactory.h"
#include "entityspy.h"

EntitySpyFactory::EntitySpyFactory()
{

}

AbstractCard* EntitySpyFactory::createCard(QString info, Entity_type entity_type, int strength)
{
    return new EntitySpy(cards++, info, entity_type, strength);
}
