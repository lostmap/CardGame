#ifndef FIELD_H
#define FIELD_H

#include "deck.h"
#include "player.h"

#include <QMap>

class Field
{
public:
    Field();

private:
    QMap<Player *, Deck *> _field;

};

#endif // FIELD_H
