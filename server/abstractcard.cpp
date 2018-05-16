#include "abstractcard.h"

AbstractCard::AbstractCard(int id, QString info):
    _id(id), _info(info)
{

}

QString AbstractCard::getInfo()
{
    return _info;
}

int AbstractCard::getId()
{
    return _id;
}

QDomElement AbstractCard::toDomElement()
{
    QDomDocument document;
    QDomElement card = document.createElement("card");

    card.appendChild(_domElement("id", getId()));
    card.appendChild(_domElement("info", getInfo()));
    card.appendChild(_domElement("type", getEntityType()));
    card.appendChild(_domElement("strength", getStrength()));
    card.appendChild(_domElement("strength", property()));

    return card;
}

QDomElement AbstractCard::_domElement(QString elementName, int value)
{
    QDomDocument document;

    QDomElement element = document.createElement(elementName);
    QDomText text = document.createTextNode(QString::number(value));
    element.appendChild(text);

    return element;
}

QDomElement AbstractCard::_domElement(QString elementName, QString value)
{
    QDomDocument document;

    QDomElement element = document.createElement(elementName);
    QDomText text = document.createTextNode(value);
    element.appendChild(text);

    return element;
}
