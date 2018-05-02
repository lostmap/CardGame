#include "myserver.h"
#include "interlayer.h"

#include <QTcpSocket>
#include <QRegExp>

MyServer::MyServer(QObject *parent) : QTcpServer(parent),
    _interLayer(nullptr)
{
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
    qDebug() << QString::fromUtf8("New connection!");

    QTcpSocket *client = (QTcpSocket*)sender();

    /*while(client->canReadLine())
    {
        QString line = QString::fromUtf8(client->readLine()).trimmed();
        qDebug() << "Read line:" << line;
    }*/

    qDebug() << "Here";
    QByteArray data;
    data = client->readAll();
    while (!data.contains("</user>") && client->waitForReadyRead()) {
        data += client->readAll();
        qDebug() << data;
    }

    qDebug() << QString::fromUtf8("Send to parse");
    _interLayer->parseData(client, data);

        /*
        QRegExp meRegex("^/me:(.*)$");

        if(meRegex.indexIn(line) != -1)
        {
            QString user = meRegex.cap(1);
            // users[client] = user;
            foreach(QTcpSocket *client, clients)
                client->write(QString("Server:" + user + " has joined.\n").toUtf8());
            sendUserList();
        }
        else if(users.contains(client))
        {
            QString message = line;
            QString user = users[client];
            qDebug() << "User:" << user;
            qDebug() << "Message:" << message;

            foreach(QTcpSocket *otherClient, clients)
                otherClient->write(QString(user + ":" + message + "\n").toUtf8());
        }
        else
        {
            qWarning() << "Got bad message from client:" << client->peerAddress().toString() << line;
        }
    }
    */
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

/*void MyServer::sendUserList()
{

    QStringList userList;
    foreach(QString user, users.values())
        userList << user;

    foreach(QTcpSocket *client, clients)
        client->write(QString("/users:" + userList.join(",") + "\n").toUtf8());

}
*/
