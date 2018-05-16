#include "entityspy.h"

EntitySpy::EntitySpy(int id, QString info, Entity_type entity_type, int strength):
     EntityWithProperty(id, info, entity_type, strength, Spy)

{

}

// Добавляется на поле соперника
// Игрок получает две карты в руку
Property_type EntitySpy::property(Deck *deck){
    return getPropertyType();
}

