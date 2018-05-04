#ifndef STUDENT_H
#define STUDENT_H

#include "abstractcard.h"
#include "entity.h"

#include <QString>

class Student: public AbstractCard, public Entity
{
public:
    Student(int id, int type, QString info, int strength);
};

#endif // STUDENT_H
