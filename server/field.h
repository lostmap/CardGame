#ifndef FIELD_H
#define FIELD_H

#include "deck.h"
#include "player.h"
#include "abstractcard.h"

#include <QMap>
#include <QDomElement>

class Field
{
public:
    Field(Player*, Player*);
    ~Field();

    //возвращает колоду пользователя лежвщую на столе
    Deck *getDeck(Player *);

    // добаляет карту на поле к игроку
    void addCardToField(Player*, Player*, AbstractCard*);

    void addCardToDeck(Player *player, AbstractCard *card);

    // удаляет карты с поля у игрока
    void reset(Player*);

    QDomElement toQDomElement(Player*, Player*);

private:
    QMap<Player *, Deck *> _tableDeck;

};

#endif // FIELD_H
