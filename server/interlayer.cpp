#include "interlayer.h"
#include "game.h"

#include <QTcpSocket>
#include <QDomDocument>
#include <QDebug>

InterLayer::InterLayer(Game *game, MyServer *server):
    _game(game), _server(server)
{

}

InterLayer::~InterLayer()
{
    if (_game)
        delete _game;

    if (_server)
        delete _server;
}

void InterLayer::newClient(QTcpSocket *client)
{


}

void InterLayer::parseData(QTcpSocket *client, QByteArray data)
{
    QDomDocument document;

    document.setContent(data);

    QDomElement root = document.documentElement();

    if (root.tagName() == "user")
    {
        QDomNode node = root.firstChild();
        QDomElement root = node.toElement();
        QString command = root.tagName();

        qDebug() << command;

        if (command == "login" or command == "signup")
        {
            node = root.firstChild();

            QString login;
            if (node.firstChild().nodeType() == QDomNode::TextNode)
                      login = node.firstChild().toText().data();

            node = node.nextSibling();

            QString password;
            if (node.firstChild().nodeType() == QDomNode::TextNode)
                      password = node.firstChild().toText().data();

            if (command == "login")
                _game->logIn(login, password);
            else
            {
                _game->signUp(login, password);
                _setConnectionSocketLogin(client, login);
            }
        }

        if (command == "start")
                _game->findCouple(_getLogin(client));


        if (command == "card"){
            node = root.firstChild();

            QString id;
            if (node.firstChild().nodeType() == QDomNode::TextNode)
                id = node.firstChild().toText().data();
            _game->update(_getLogin(client), id.toInt());
        }

        if (command == "pass")
        {
            _game->pass(_getLogin(client));
        }

    }
}

void InterLayer::_setConnectionSocketLogin(QTcpSocket *client, QString login)
{
    _socket[login] = client;
    _login[client] = login;
}

QTcpSocket* InterLayer::_getSocket(QString login)
{
    return _socket[login];
}

QString InterLayer::_getLogin(QTcpSocket *client)
{
    return _login[client];
}


void InterLayer::sendState(QString login)
{
    _server->sendData(_getSocket(login), _game->toQDomDocument(login).toByteArray());
}
