#ifndef FIELD_H
#define FIELD_H

#include "deck.h"
#include "player.h"
#include "abstractcard.h"
#include "cardproperty.h"

#include <map>
#include <memory>

class Field: public std::enable_shared_from_this<Field>
{
public:
    Field(std::shared_ptr<Player>, std::shared_ptr<Player>);
    ~Field();

    //возвращает колоду пользователя лежвщую на столе
    std::shared_ptr<Deck> getDeck(std::shared_ptr<Player>) const;

    // добаляет карту на поле к игроку
    void addCardToField(std::shared_ptr<Player>, std::shared_ptr<Player>, std::shared_ptr<AbstractCard>);

    void addCardToDeck(std::shared_ptr<Player>, std::shared_ptr<AbstractCard>);

    // удаляет карты с поля у игрока
    void reset();

private:
    std::map<std::shared_ptr<Player>, std::shared_ptr<Deck>> _tableDeck;
    CardProperty _cardProperty;

};

#endif // FIELD_H
