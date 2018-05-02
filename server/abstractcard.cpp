#include "abstractcard.h"

AbstractCard::AbstractCard()
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
