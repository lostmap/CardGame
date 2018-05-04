#ifndef ABSTRACTCARD_H
#define ABSTRACTCARD_H

#include <QString>

class AbstractCard
{
public:
    AbstractCard(int id, int type, QString info);

    int getId();
    int getType();
    QString getInfo();

private:
    int _id;
    int _type;
    QString _info;

};

#endif // ABSTRACTCARD_H
