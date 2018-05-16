#ifndef ENTITYSPY_H
#define ENTITYSPY_H

#include "entitywithproperty.h"
#include "deck.h"
#include "define.h"

#include <QString>

class EntitySpy : public EntityWithProperty
{
public:
    EntitySpy(int id, QString info, Entity_type entity_type, int strength);
    Property_type property(Deck *deck = nullptr);
};

#endif // ENTITYSPY_H
