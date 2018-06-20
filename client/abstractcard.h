#ifndef ABSTRACTCARD_H
#define ABSTRACTCARD_H

#include <string>

#include "sfmlcard.h"
#include "config.h"

class AbstractCard: public SfmlCard
{
public:
    AbstractCard(int id, std::string info, float x, float y, 
    			Entity_type entity_typy = NO_ENTITY, Property_type property_type = NO_PROPERTY);

    virtual ~AbstractCard() {};

    int getId();
    std::string getInfo();

    virtual Entity_type getEntityType() = 0;
    virtual int getStrength() = 0;
    virtual void setStrength(int) = 0;
    virtual Property_type getPropertyType() = 0;
    
    virtual void update(float time) = 0;

private:
    int _id;
    std::string _info;
};

#endif // ABSTRACTCARD_H
