#ifndef PROPERTY_H
#define PROPERTY_H

#include "abstractcard.h"

// Карта не являющаяся героем и не обладающая силой
// Но имеющая свойство
class Property : public AbstractCard
{
public:
    Property(int id, Property_type property_type, QString info);

    int getType();
    QString getInfo();
    virtual Property_type property(Deck*) = 0;
    int getStrength();
    void setStrength(int strength);

private:
    Property_type _property_type;
};

#endif // PROPERTY_H
