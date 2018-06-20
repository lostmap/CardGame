#ifndef PROPERTYCARD_H
#define PROPERTYCARD_H

#include "abstractcard.h"
#include "sfmlcard.h"
#include "config.h"
#include <string>

class PropertyCard: virtual public AbstractCard
{
public:
    PropertyCard(int id, std::string info, Property_type property_type,
    	float x, float y);

    Entity_type getEntityType();
    int getStrength();
    void setStrength(int);
    Property_type getPropertyType();
    void update(float time);

private:
    Property_type _property_type;
};

#endif // PROPERTYCARD_H
