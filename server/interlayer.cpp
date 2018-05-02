#include "interlayer.h"
#include "game.h"

#include <QTcpSocket>
#include <QDomDocument>
#include <QDebug>

InterLayer::InterLayer(Game *game, MyServer *server):
    _game(game), _server(server)
{

}

void InterLayer::newClient(QTcpSocket *client)
{
    // ?????????????????

}


void ListElement(QDomElement root, QString tagname, QString attribute){
    QDomNodeList items = root.elementsByTagName(tagname);

    for (int i =0; i < items.count(); ++i) {
        QDomNode itemnode = items.at(i);

        if (itemnode.isElement()) {
            QDomElement itemelement = itemnode.toElement();
            qDebug() << itemelement.attribute(attribute);
        }
    }
}


void InterLayer::createCardDeck(QByteArray data) {



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

        else{
            if (command == "start")
                _game->findCouple(_getLogin(client));
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

QString  InterLayer::_getLogin(QTcpSocket *client)
{
    return _login[client];
}
