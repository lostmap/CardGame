#include "abstractcard.h"

AbstractCard::AbstractCard(int id, int type, QString info):
    _id(id), _type(type), _info(info)
{

}

QString AbstractCard::getInfo()
{
    return _info;
}

int AbstractCard::getType()
{
    return _type;
}

int AbstractCard::getId()
{
    return _id;
}
