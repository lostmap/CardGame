#ifndef PARTY_H
#define PARTY_H

class Player;
class Deck;
class Field;
class AbstractCard;

#include <QMap>
#include <QDomElement>
#include <QDomDocument>

class Party
{
public:
    Party(Player*, Player*);
    ~Party();

    bool isMyTern(Player*);

    // ход игрока
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

    QDomDocument toQDomDocument(Player*,Player*);

private:

    Field *_field;
    Player *_turn;

     QDomElement _domElement(QString elementName, int value);

};

#endif // PARTY_H
