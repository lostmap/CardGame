#ifndef ABSTRACTCARD_H
#define ABSTRACTCARD_H

class Deck;

#include "config.h"
#include <string>

class AbstractCard
{
public:
    AbstractCard(int id, std::string info);

    int getId() const;
    std::string getInfo() const;

    virtual ENTITY_TYPE getEntityType() const = 0;
    virtual int getStrength() const = 0;
    virtual void setStrength(int strength) = 0;
    virtual PROPERTY_TYPE getPropertyType() const = 0;

private:
    int _id;
    std::string _info;

};

#endif // ABSTRACTCARD_H
