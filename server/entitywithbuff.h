#ifndef ENTITYWITHBUFF_H
#define ENTITYWITHBUFF_H

#include "entitywithproperty.h"
#include "define.h"

#include <QString>

// Герой со свойством удваивания силы,
// если на поле находится то же герой
class EntityWithBuff: public EntityWithProperty
{
public:
    EntityWithBuff(int id, QString info, Entity_type entity_type, int strength);
    Property_type property(Deck *deck = nullptr);
};

#endif // ENTITYWITHBUFF_H
