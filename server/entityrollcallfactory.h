#ifndef ENTITYROLLCALLFACTORY_H
#define ENTITYROLLCALLFACTORY_H

#include "cardfactory.h"

class EntityRollCallFactory: public CardFactory
{
public:
    EntityRollCallFactory();
    AbstractCard *createCard(QString info, Entity_type entity_type, int strength);
};

#endif // ENTITYROLLCALLFACTORY_H
