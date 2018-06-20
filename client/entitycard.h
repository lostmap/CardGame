#ifndef ENTITYCARD_H
#define ENTITYCARD_H

#include "abstractcard.h"
#include <string>
#include "config.h"
#include "sfmlcard.h"

class EntityCard: virtual public AbstractCard
{
public:
    EntityCard(int id, std::string info, Entity_type entity_type, 
    	int strength, float x, float y);

    ~EntityCard() {}

    Entity_type getEntityType();
    int getStrength();
    void setStrength(int);
    Property_type getPropertyType();

	void update(float time);

private:
    Entity_type _entity_type;
    int _strength;

};

#endif // ENTITYCARD_H
