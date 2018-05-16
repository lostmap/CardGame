#ifndef PROPERTYCARD_H
#define PROPERTYCARD_H

#include "abstractcard.h"

class PropertyCard: virtual public AbstractCard
{
public:
    PropertyCard(int id, QString info, Property_type property_type);

    Entity_type getEntityType();
    int getStrength();
    void setStrength(int);
    Property_type getPropertyType();

private:
    Property_type _property_type;
};

#endif // PROPERTYCARD_H
