#include "interlayer.h"
#include "mainwindow.h"
#include "client.h"

// for random
#include <QTime>

InterLayer::InterLayer(MainWindow *mainWindow, Client *client):
    _mainWindow(mainWindow),
    _client(client)
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    sendLogin(QString("dlipko" + QString::number(qrand()%1000)), QString::number(12345));

}

void InterLayer::_parseCard(QDomElement node)
{
    _mainWindow->append("card");
    QDomNode parametr = node.firstChild();
    while (!parametr.isNull())
    {
        _parseNode(parametr.toElement());
        parametr = parametr.nextSibling();
    }

}

// вот отсюда можно возвращать колоду
void InterLayer::_parseDeck(QDomElement root)
{
    qDebug() << root.tagName();
    _mainWindow->append(root.tagName());
    QDomNode node = root.firstChild();

    while (!node.isNull()){
        _parseCard(node.toElement());
        node = node.nextSibling();
    }
}

// отсюда можно возвращать карту в
void InterLayer::_parseNode(QDomElement root)
{
        QString tag = root.tagName();
        QDomNode node = root.firstChild();
        QString value;
        if (node.nodeType() == QDomNode::TextNode)
           value = node.toText().data();
        _mainWindow->insertPlainText(tag + ": " + value + "  ");
}

void InterLayer::parseData(QByteArray data)
{
        _mainWindow->clear();
        QDomDocument document;

        document.setContent(data);

        QDomElement root = document.documentElement();

        if (root.tagName() == "server")
        {
            QDomNode node = root.firstChild();
             while (!node.isNull())
             {
                QDomElement root = node.toElement();
                QString command = root.tagName();

                if (command == "turn" || command == "win")
                {
                    _parseNode(root);
                }

                if (command == "me")
                {
                    QDomNode meNode = node.firstChild();

                    while (!meNode.isNull()){
                        if (meNode.toElement().tagName() == "me"){
                            QDomNode meNodeChild = meNode.firstChild();

                            while (!meNodeChild.isNull()){
                                QString command = meNodeChild.toElement().tagName();
                                if (command == "stagescore"||command == "score"
                                        || command == "heandsize" || command == "pass")
                                    _parseNode(meNodeChild.toElement());
                                meNodeChild = meNodeChild.nextSibling();
                             }
                        }
                        else
                            _parseDeck(meNode.toElement());
                        meNode = meNode.nextSibling();
                    }


                }

                if (command == "field")
                {
                    QDomNode fieldNodes = node.firstChild();
                    _parseDeck(fieldNodes.toElement());
                    fieldNodes = fieldNodes.nextSibling();
                    _parseDeck(fieldNodes.toElement());

                }


                if (command == "heand")
                {
                     _parseDeck(root);
                }


                node = node.nextSibling();
             }
        }

}

void InterLayer::sendCard(int id)
{
    _client->send(QString("<user><card><id>" + QString::number(id) + "</id></card></user>").toUtf8());
}

void InterLayer::sendStart()
{
    _client->send("<user><start>1</start></user>");
}

void InterLayer::sendLogin(QString login, QString password)
{
    _client->send(QString("<user><signup><login>") + login + "</login><password>"
                  + password + "</password></signup></user>");
}

void InterLayer::sendPass()
{
    _client->send("<user><pass>0</pass></user>");
}
