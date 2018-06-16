#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "cardfactory.h"
#include "config.h"

#include <memory>

class EntityFactory : public CardFactory
{
public:
    EntityFactory();
    std::shared_ptr<AbstractCard> createCard(ENTITY_TYPE entity_type, int strength, PROPERTY_TYPE property_type = NO_PROPERTY);
};

#endif // ENTITYFACTORY_H
