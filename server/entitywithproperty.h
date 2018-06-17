#ifndef ENTITYWITHPROPERTY_H
#define ENTITYWITHPROPERTY_H

#include "abstractcard.h"
#include "config.h"

#include <string>

class EntityWithProperty: public AbstractCard
{
public:
    EntityWithProperty(int id, std::string info, ENTITY_TYPE entity_type, int strength, PROPERTY_TYPE property_type);

    ENTITY_TYPE getEntityType() const;
    int getStrength() const;
    void setStrength(int strength);
    PROPERTY_TYPE getPropertyType() const;

private:
    ENTITY_TYPE _entity_type;
    int _strength;
    PROPERTY_TYPE _property_type;
};

#endif // ENTITYWITHPROPERTY_H
