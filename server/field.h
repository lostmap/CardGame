#ifndef FIELD_H
#define FIELD_H

#include "deck.h"
#include "player.h"
#include "abstractcard.h"

#include <QMap>

class Field
{
public:
    Field(Player*, Player*);

    //возвращает колоду пользователя лежвщую на столе
    Deck *getDeck(Player *);

    // добаляет карту на поле к игроку
    void addCardToField(Player*, AbstractCard*);

    // удаляет карты с поля у игрока
    void reset(Player*);

private:
    QMap<Player *, Deck *> _tableDeck;

};

#endif // FIELD_H
