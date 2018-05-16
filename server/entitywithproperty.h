#ifndef ENTITYWITHPROPERTY_H
#define ENTITYWITHPROPERTY_H

#include "abstractcard.h"
#include <QString>

#include "define.h"

class EntityWithProperty: public AbstractCard
{
public:
    EntityWithProperty(int id, QString info, Entity_type entity_type, int strength, Property_type property_type);

    virtual Property_type property(Deck*) = 0;
    Entity_type getEntityType();
    int getStrength();
    void setStrength(int strength);
    Property_type getPropertyType();

private:
    Entity_type _entity_type;
    int _strength;
    Property_type _property_type;
};

#endif // ENTITYWITHPROPERTY_H
