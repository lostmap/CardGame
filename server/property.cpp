#include "property.h"
#include "define.h"

Property::Property(int id, Property_type property_type, QString info):
    AbstractCard(id, info),
    _property_type(property_type)
{

}

int Property::getStrength()
{
    return 0;
}
void Property::setStrength(int strength) {}
