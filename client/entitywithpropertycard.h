#ifndef ENTITYWITHPROPERTYCARD_H
#define ENTITYWITHPROPERTYCARD_H

#include "entitycard.h"
#include "propertycard.h"
#include "define.h"

class EntityWithPropertyCard: public EntityCard, public PropertyCard
{
public:
    EntityWithPropertyCard(int id, QString info, Entity_type entity_type,
                           int strength, Property_type property_type);

    Entity_type getEntityType();
    int getStrength();
    void setStrength(int);
    Property_type getPropertyType();

};

#endif // ENTITYWITHPROPERTYCARD_H
