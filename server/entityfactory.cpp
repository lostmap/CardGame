#include "entityfactory.h"
#include "entity.h"
#include "config.h"

EntityFactory::EntityFactory()
{

}

std::shared_ptr<AbstractCard> EntityFactory::createCard(ENTITY_TYPE entity_type, int strength, PROPERTY_TYPE property_type)
{
    return std::shared_ptr<AbstractCard>(new Entity(cards++, Config::Instance().getInfo(entity_type), entity_type, strength));
}
