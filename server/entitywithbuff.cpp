#include "entitywithbuff.h"
#include "deck.h"

EntityWithBuff::EntityWithBuff(int id, QString info, Entity_type entity_type, int strength):
    EntityWithProperty(id, info, entity_type, strength, Buff)
{

}

// Если на поле есть карта тогоже типа
// удваивает силу обоих
Property_type EntityWithBuff::property(Deck *deck){
    if (deck)
    {
        AbstractCard *same_card = deck->findByEntityType(getEntityType());
        if (same_card)
        {
            same_card->setStrength(same_card->getStrength()*2);
            setStrength(getStrength()*2);
        }
    }
    return getPropertyType();
}
