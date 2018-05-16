#ifndef ENTITY_H
#define ENTITY_H

#include "abstractcard.h"

#include <QString>

class Entity: public AbstractCard
{
public:
    Entity(int id, QString info, Entity_type entity_type, int strength);

    Entity_type getEntityType();
    int getStrength();
    void setStrength(int strength);


    Property_type property(Deck*);

private:
    Entity_type _entity_type;
    int _strength;
};

#endif // ENTITY_H
