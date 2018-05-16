#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "abstractcard.h"
class CardFactory
{
public:
    CardFactory();
    virtual AbstractCard* createCard() = 0;
    virtual ~CardFactory() {}

    static int cards;
};

#endif // CARDFACTORY_H
