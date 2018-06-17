#include "qserver.h"

#include "qsocket.h"

#include <QString>

QServer::QServer(QObject *parent): Server(), QTcpServer(parent)
{

}

QServer::~QServer() {}


bool QServer::listen(QHostAddress host, int port)
{
    return QTcpServer::listen(host, port);
}

void QServer::incomingConnection(int socketfd)
{
    auto client = new QSocket(this);
    client->setSocketDescriptor(socketfd);

    _myServer->newClient(client);
    connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
}


void QServer::readyRead()
{
    auto client = (QSocket *)sender();
    QByteArray data;
    data = client->readAll();
    _myServer->readData(client, QString(data).toStdString());
}

void QServer::disconnected()
{
    auto client = (QSocket *)sender();
    _myServer->clientDisconnect(client);
}

void QServer::sendData(Socket* client,QByteArray data) const
{
    client->writeStdString(QString(data.data()).toStdString());
}

