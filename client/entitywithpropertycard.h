#ifndef ENTITYWITHPROPERTYCARD_H
#define ENTITYWITHPROPERTYCARD_H

#include "entitycard.h"
#include "propertycard.h"
#include "config.h"

#include <string>

class EntityWithPropertyCard: public EntityCard, public PropertyCard
{
public:
    EntityWithPropertyCard(int id, std::string info, Entity_type entity_type,
                           int strength, Property_type property_type,
                           float x = 0, float y = 0);

    Entity_type getEntityType();
    int getStrength();
    void setStrength(int);
    Property_type getPropertyType();

    void update(float time);

};

#endif // ENTITYWITHPROPERTYCARD_H
