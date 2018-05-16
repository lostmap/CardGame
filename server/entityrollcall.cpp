#include "entityrollcall.h"

EntityRollCall::EntityRollCall(int id, QString info, Entity_type entity_type, int strength):
    EntityWithProperty(id, info, entity_type, strength, RollCall)
{

}

// Добавляется на поле соперника
// Игрок получает две карты в руку
Property_type EntityRollCall::property(Deck *deck){
    if (deck)
    {
        deck->addCard(this);
    }
    return getPropertyType();
}
