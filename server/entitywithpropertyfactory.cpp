#include "entitywithpropertyfactory.h"
#include "entitywithproperty.h"

EntityWithPropertyFactory::EntityWithPropertyFactory()
{

}

std::shared_ptr<AbstractCard> EntityWithPropertyFactory::createCard(ENTITY_TYPE entity_type,
                                                                    int strength,
                                                                    PROPERTY_TYPE property_type)
{
    return std::shared_ptr<AbstractCard>(new EntityWithProperty(cards++,
                                                                Config::Instance().getInfo(entity_type, property_type),
                                                                entity_type,
                                                                strength,
                                                                property_type));
}
