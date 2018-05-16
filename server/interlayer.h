#ifndef INTERLAYER_H
#define INTERLAYER_H

#include "game.h"
#include "myserver.h"

#include <QTcpSocket>
#include <QString>
#include <QMap>
#include <QByteArray>
#include <QDomDocument>
#include <QDomText>

class InterLayer
{
public:
    InterLayer(Game *game, MyServer *server);
    ~InterLayer();

    void newClient(QTcpSocket *client);

    // парсер приходящих данных
    void parseData(QTcpSocket *client, QByteArray data);

    // отправляет текущее состояние игры
    void sendState(QString login);

private:
    Game *_game;
    MyServer *_server;

    // соответсвие логина и сокета
    QMap<QString, QTcpSocket *> _socket;
    // соответствие сокета и логина
    QMap<QTcpSocket *, QString> _login;

    QTcpSocket *_getSocket(QString login);
    QString _getLogin(QTcpSocket *client);


    void _setConnectionSocketLogin(QTcpSocket *client, QString login);

    // парсер карты
    void _parseCard(QByteArray);

};

#endif // INTERLAYER_H
