#include "myserver.h"
#include "interlayer.h"

#include <QTcpSocket>
#include <QRegExp>

MyServer::MyServer(QObject *parent) : QTcpServer(parent),
    _interLayer(nullptr)
{
}

MyServer::~MyServer()
{
    if (_interLayer)
        delete _interLayer;
}

void MyServer::setInterLayer(InterLayer *interLayer)
{
     _interLayer = interLayer;
}

void MyServer::incomingConnection(int socketfd)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);

    _interLayer->newClient(client);

    qDebug() << "New client from:" << client->peerAddress().toString();

    connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
}


void MyServer::readyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();

    QByteArray data;
    data = client->readAll();
    while (!data.contains("</user>") && client->waitForReadyRead()) {
        data += client->readAll();
        qDebug() << data;
    }

    _interLayer->parseData(client, data);
}

void MyServer::disconnected()
{
    /*
    QTcpSocket *client = (QTcpSocket*)sender();
    qDebug() << "Client disconnected:" << client->peerAddress().toString();

    clients.remove(client);

    QString user = users[client];
    users.remove(client);

    sendUserList();
    foreach(QTcpSocket *client, clients)
        client->write(QString("Server:" + user + " has left.\n").toUtf8());
*/
}

void MyServer::sendData(QTcpSocket *client,QByteArray data)
{
    client->write(data);
}
