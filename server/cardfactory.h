#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "abstractcard.h"
#include "config.h"

#include <memory>

class CardFactory
{
public:
    CardFactory();
    virtual std::shared_ptr<AbstractCard> createCard(ENTITY_TYPE entity_type, int strength, PROPERTY_TYPE property_type) = 0;
    virtual ~CardFactory() {}

    static int cards;
};

#endif // CARDFACTORY_H
