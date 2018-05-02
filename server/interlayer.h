#ifndef INTERLAYER_H
#define INTERLAYER_H

#include "game.h"
#include "myserver.h"

#include <QTcpSocket>
#include <QString>
#include <QMap>
#include <QByteArray>

class InterLayer
{
public:
    InterLayer(Game *game, MyServer *server);

    void newClient(QTcpSocket *client);
    void parseData(QTcpSocket *client, QByteArray data);
    void createCardDeck(QByteArray data);

private:
    Game *_game;
    MyServer *_server;

    QMap<QString, QTcpSocket *> _socket;
    QMap<QTcpSocket *, QString> _login;

    QTcpSocket *_getSocket(QString login);
    QString _getLogin(QTcpSocket *client);

    void _setConnectionSocketLogin(QTcpSocket *client, QString login);
};

#endif // INTERLAYER_H
