#include "abstractcard.h"

AbstractCard::AbstractCard(int id, std::string info):
    _id(id), _info(info)
{

}

std::string AbstractCard::getInfo() const
{
    return _info;
}

int AbstractCard::getId() const
{
    return _id;
}
