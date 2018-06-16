#include "server.h"

Server::Server(QObject *parent): QTcpServer(parent),
    _myServer(nullptr)
{

}

Server::~Server() {}

void Server::setMyServer(std::shared_ptr<MyServer> myServer)
{
    _myServer = myServer;
}


void Server::incomingConnection(int socketfd)
{
    auto client = new Socket(this);
    client->setSocketDescriptor(socketfd);

    _myServer->newClient(client);
    connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
}


void Server::readyRead()
{
    auto client = (Socket *)sender();
    QByteArray data;
    data = client->readAll();
    _myServer->readData(client, QString(data).toStdString());
}

void Server::disconnected()
{
    auto client = (Socket *)sender();
    _myServer->clientDisconnect(client);
}

void Server::sendData(Socket *   client,QByteArray data) const
{
    client->write(data);
}
