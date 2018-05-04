#include "interlayer.h"
#include "game.h"
#include "student.h"

#include <QTcpSocket>
#include <QDomDocument>
#include <QDebug>

InterLayer::InterLayer(Game *game, MyServer *server):
    _game(game), _server(server)
{

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

QDomElement InterLayer::_createChild(QString elementName, int value)
{
    QDomDocument document;

    QDomElement element = document.createElement(elementName);
    QDomText text = document.createTextNode(QString::number(value));
    element.appendChild(text);

    return element;
}

QDomElement InterLayer::_createChild(QString elementName, QString value)
{
    QDomDocument document;

    QDomElement element = document.createElement(elementName);
    QDomText text = document.createTextNode(value);
    element.appendChild(text);

    return element;
}

QDomElement InterLayer::_createCard(int id, int type, QString info, int strength)
{
    QDomDocument document;
    QDomElement card = document.createElement("card");

    card.appendChild(_createChild("id", id));
    card.appendChild(_createChild("type", type));
    card.appendChild(_createChild("info", info));
    card.appendChild(_createChild("strength", strength));

    return card;
}

QDomElement InterLayer::_createDeck(QString elementName, Deck *deck)
{
    QDomDocument document;
    QDomElement element = document.createElement(elementName);

    for (auto i = deck->begin(); i != deck->end(); ++i)
    {
        element.appendChild(_createCard((*i)->getId(), (*i)->getType(),
                                        (*i)->getInfo(), static_cast<Student*>(*i)->getStrength()));
    }

    return element;
}

QString InterLayer::_getPartnerLogin(QString login)
{
    return _game->getPartnerLogin(login);
}

int InterLayer::_getPartnerScore(QString login)
{
    return _game->getPartnerScore(login);
}

int InterLayer::_getScore(QString login)
{
    return _game->getScore(login);
}

bool InterLayer::isMyTern(QString login)
{
    return _game->isMyTern(login);
}

int InterLayer::winValue(QString login)
{
    return _game->winValue(login);
}

Deck* InterLayer::getPartnerDeck(QString login)
{
    return _game->getPartnerDeck(login);

}

Deck* InterLayer::getDeck(QString login)
{
    return _game->getDeck(login);

}

Deck* InterLayer::getHeand(QString login)
{
    return _game->getHeand(login);

}

int InterLayer::_getStageScore(QString login)
{
    return _game->getStageScore(login);
}

void InterLayer::sendState(QString login)
{

    QDomDocument document;

    QDomElement root = document.createElement("server");

    document.appendChild(root);

    qDebug() << "personal info";

    root.appendChild(_createChild("partnername",
                                 _getPartnerLogin(login)));
    root.appendChild(_createChild("partnerscore",
                                 _getPartnerScore(login)));
    root.appendChild(_createChild("mystagescore",
                                 _getStageScore(login)));
    root.appendChild(_createChild("myscore",
                                 _getScore(login)));


    isMyTern(login)?root.appendChild(_createChild("turn", 1))
                         :root.appendChild(_createChild("turn", 0));


    root.appendChild(_createChild("win", winValue(login)));

    QDomElement node = document.createElement("field");
    root.appendChild(node);

    node.appendChild(_createDeck("partner", getPartnerDeck(login)));

    node.appendChild(_createDeck("mycards", getDeck(login)));

    root.appendChild(_createDeck("heand", getHeand(login)));

    _server->sendData(_getSocket(login), document.toByteArray());

}
