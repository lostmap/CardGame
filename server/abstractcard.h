#ifndef ABSTRACTCARD_H
#define ABSTRACTCARD_H

class Deck;
#include "define.h"
#include <QString>
#include <QDomElement>

class AbstractCard
{
public:
    AbstractCard(int id, QString info);

    int getId();
    QString getInfo();

    virtual Entity_type getEntityType() = 0;
    virtual int getStrength() = 0;
    virtual void setStrength(int strength) = 0;

    virtual Property_type property(Deck *deck = nullptr) = 0;

    QDomElement toDomElement();

private:
    int _id;
    QString _info;

    QDomElement _domElement(QString elementName, QString value);
    QDomElement _domElement(QString elementName, int value);

};

#endif // ABSTRACTCARD_H
