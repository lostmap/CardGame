#ifndef PROPERTY_H
#define PROPERTY_H

#include "abstractcard.h"
#include "config.h"

#include <string>

// Карта не являющаяся героем и не обладающая силой
// Но имеющая свойство
class Property : public AbstractCard
{
public:
    Property(int id, PROPERTY_TYPE property_type, std::string info);

    int getType() const;
    std::string getInfo() const;
    PROPERTY_TYPE getPropertyType() const;
    int getStrength()const;
    void setStrength(int strength);
    ENTITY_TYPE getEntityType() const;

private:
    PROPERTY_TYPE _property_type;
};

#endif // PROPERTY_H
