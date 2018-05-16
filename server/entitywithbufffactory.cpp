#include "entitywithbufffactory.h"
#include "entitywithbuff.h"

EntityWithBuffFactory::EntityWithBuffFactory()
{

}

AbstractCard* EntityWithBuffFactory::createCard(QString info, Entity_type entity_type, int strength)
{
    return new EntityWithBuff(cards++, info, entity_type, strength);
}
