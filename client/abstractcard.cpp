#include "abstractcard.h"

AbstractCard::AbstractCard(int id, QString info):
    _id(id), _info(info)
{

}

int AbstractCard::getId()
{
    return _id;
}

QString AbstractCard::getInfo()
{
    return _info;
}
