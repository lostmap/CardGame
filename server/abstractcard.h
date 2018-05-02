#ifndef ABSTRACTCARD_H
#define ABSTRACTCARD_H

#include <QString>

class AbstractCard
{
public:
    AbstractCard();

    int getId();
    QString getInfo();
    int getType();

private:
    int _id;
    QString _info;
    int _type;


};

#endif // ABSTRACTCARD_H
