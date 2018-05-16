#ifndef ENTITYWITHBUFFFACTORY_H
#define ENTITYWITHBUFFFACTORY_H

#include "cardfactory.h"

class EntityWithBuffFactory: public CardFactory
{
public:
    EntityWithBuffFactory();
    AbstractCard *createCard(QString info, Entity_type entity_type, int strength);
};

#endif // ENTITYWITHBUFFFACTORY_H
