#ifndef ABSTRACTCARD_H
#define ABSTRACTCARD_H

#include <QString>
#include "define.h"

class AbstractCard
{
public:
    AbstractCard(int id, QString info);

    int getId();
    QString getInfo();

    virtual Entity_type getEntityType() = 0;
    virtual int getStrength() = 0;
    virtual void setStrength(int) = 0;
    virtual Property_type getPropertyType() = 0;

private:
    int _id;
    QString _info;
};

#endif // ABSTRACTCARD_H
