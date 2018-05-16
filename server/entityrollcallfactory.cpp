#include "entityrollcallfactory.h"
#include "entityrollcall.h"

EntityRollCallFactory::EntityRollCallFactory()
{

}

AbstractCard* EntityRollCallFactory::createCard(QString info, Entity_type entity_type, int strength)
{
    return new EntityRollCall(cards++, info, entity_type, strength);
}
