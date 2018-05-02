#ifndef GAME_H
#define GAME_H

class InterLayer;

#include "player.h"
#include "user.h"
#include "party.h"

#include <QMap>
#include <QString>
#include <QSet>
#include <QPair>
#include <QDebug>


class Game
{
public:
    Game();


    void setInterLayer(InterLayer *interLayer);
    void logIn(QString login, QString password);
    void signUp(QString login, QString password);
    void findCouple(QString login);

private:
    InterLayer *_interLayer;
    QMap<QString, User *> _user;
    QMap<Player *, Player *> _couple;
    QMap<Player *, Party *> _party;
    QString _waitingForCouple;

    User *_getUser(QString);
    void _startParty(Player*, Player*);

};

#endif // GAME_H
