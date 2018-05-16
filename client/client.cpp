#include "client.h"
#include <QTime>

Client::Client(QWidget *parent):
    QMainWindow(parent)
{
    _socket = new QTcpSocket(this);

    _socket->connectToHost("127.0.0.1", 1234);

    connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(_socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(_socket, SIGNAL(disconnected()),this, SLOT(disconnected()));

}

void Client::setInterLayer(InterLayer* interLayer)
{
    _interLayer = interLayer;
}

void Client::connected()
{
    qDebug() << "connected...";
}

void Client::disconnected()
{
    qDebug() << "disconnected...";
}


void Client::readyRead()
{

    QByteArray data;
    data = _socket->readAll();
    while (!data.contains("</server>") && _socket->waitForReadyRead()) {
        data += _socket->readAll();

    }

    _interLayer->parseData(data);
}

void Client::send(QString data)
{
    _socket->write(data.toUtf8());
}
