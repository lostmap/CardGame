#ifndef PROPERTYFACTORY_H
#define PROPERTYFACTORY_H

#include "cardfactory.h"
#include "config.h"

#include <memory>

class PropertyFactory: public CardFactory
{
public:
    PropertyFactory();
    std::shared_ptr<AbstractCard> createCard(ENTITY_TYPE entity_type, int strength, PROPERTY_TYPE property_type);
};


#endif // PROPERTYFACTORY_H
