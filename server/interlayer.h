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

    void newClient(QTcpSocket *client);

    // парсер приходящих данных
    void parseData(QTcpSocket *client, QByteArray data);

    // отправляет текущее состояние игры
    // пока что сам генерирует все данные опрашивая game
    // переделаю на генерацию xml в каждом классе
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

    // методы для опроса game
    QString _getPartnerLogin(QString login);
    int _getPartnerScore(QString login);
    int _getScore(QString login);
    bool isMyTern(QString login);
    int winValue(QString login);
    Deck* getDeck(QString login);
    Deck* getPartnerDeck(QString login);
    Deck* getHeand(QString login);
    int _getStageScore(QString login);

    void _setConnectionSocketLogin(QTcpSocket *client, QString login);

    // методы для генерации xml документа
    QDomElement _createChild(QString elementName, int value);
    QDomElement _createChild(QString elementName, QString value);
    QDomElement _createCard(int id, int type, QString info, int strength);
    QDomElement _createDeck(QString elementName, Deck *deck);

    // парсер карты
    void _parseCard(QByteArray);

};

#endif // INTERLAYER_H
