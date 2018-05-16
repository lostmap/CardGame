#ifndef ENTITYROLLCALL_H
#define ENTITYROLLCALL_H

#include "entitywithproperty.h"
#include "deck.h"
#include "define.h"

#include <QString>
// Сущность со свойством вызыва карты из колоды
class EntityRollCall: public EntityWithProperty
{
public:
    EntityRollCall(int id, QString info, Entity_type entity_type, int strength);
    Property_type property(Deck *deck = nullptr);
};

#endif // ENTITYROLLCALL_H
