#ifndef ENTITYSPYFACTORY_H
#define ENTITYSPYFACTORY_H

#include "cardfactory.h"

class EntitySpyFactory: public CardFactory
{
public:
    EntitySpyFactory();
    AbstractCard *createCard(QString info, Entity_type entity_type, int strength);
};

#endif // ENTITYSPYFACTORY_H
