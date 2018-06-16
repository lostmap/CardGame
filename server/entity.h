#ifndef ENTITY_H
#define ENTITY_H

#include "abstractcard.h"
#include "config.h"

#include <string>

class Entity: public AbstractCard
{
public:
    Entity(int id, std::string info, ENTITY_TYPE entity_type, int strength);

    ENTITY_TYPE getEntityType() const;
    int getStrength() const;
    void setStrength(int strength);

    PROPERTY_TYPE getPropertyType() const;

private:
    ENTITY_TYPE _entity_type;
    int _strength;
};

#endif // ENTITY_H
