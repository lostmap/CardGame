#ifndef PARTY_H
#define PARTY_H

#include "player.h"
#include "deck.h"
#include "field.h"
#include "abstractcard.h"

#include <QMap>

class Party
{
public:
    Party(Player*, Player*);

    bool isMyTern(Player*);
    Deck *getDeck(Player*);

    // ход первого игрока
    void makeMove(Player*, Player*, AbstractCard* );

    // передает ход игроку
    void changeTurnToPlayer(Player*);

    // если игрок сделал пас
    void pass(Player*, Player*);

    // определяет победителей во всей игре
    void setWinners(Player*, Player*);

    // проверяет нужна ли еще игра для определения победителя
    void checkStage(Player*, Player*);

    // определяет победителя в текущей стадии
    void setStageWinner(Player*, Player*);

private:

    Field *_field;
    Player *_turn;

};

#endif // PARTY_H
