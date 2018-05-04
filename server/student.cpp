#include "student.h"

Student::Student(int id, int type, QString info, int strength):
    AbstractCard(id, type, info), Entity(strength)
{

}
