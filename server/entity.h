#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
public:
    Entity(int strength);
    int getStrength();
    void setStrength(int strength);

private:
    int _strength;
};

#endif // ENTITY_H
