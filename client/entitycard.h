#ifndef ENTITYCARD_H
#define ENTITYCARD_H

#include "abstractcard.h"

class EntityCard: virtual public AbstractCard
{
public:
    EntityCard(int id, QString info, Entity_type entity_type, int strength);

    Entity_type getEntityType();
    int getStrength();
    void setStrength(int);
    Property_type getPropertyType();

private:
    Entity_type _entity_type;
    int _strength;

};

#endif // ENTITYCARD_H
