#include "abstractcard.h"


AbstractCard::AbstractCard(int id, std::string info, float x, float y, 
						Entity_type entity_typy, Property_type property_type):
	SfmlCard(x, y, entity_typy, property_type),
    _id(id), _info(info)
{

}

int AbstractCard::getId()
{
    return _id;
}

std::string AbstractCard::getInfo()
{
    return _info;
}
