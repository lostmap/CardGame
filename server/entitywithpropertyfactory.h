#ifndef ENTITYWITHPROPERTYFACTORY_H
#define ENTITYWITHPROPERTYFACTORY_H

#include "cardfactory.h"
#include "config.h"

#include <memory>

class EntityWithPropertyFactory: public CardFactory
{
public:
    EntityWithPropertyFactory();
    std::shared_ptr<AbstractCard> createCard(ENTITY_TYPE entity_type, int strength, PROPERTY_TYPE property_type);
};

#endif // ENTITYWITHPROPERTYFACTORY_H
