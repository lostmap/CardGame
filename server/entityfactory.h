#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "cardfactory.h"

class EntityFactory : public CardFactory
{
public:
    EntityFactory();
    AbstractCard *createCard(QString info, Entity_type entity_type, int strength);
};

#endif // ENTITYFACTORY_H
