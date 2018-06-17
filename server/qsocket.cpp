#include "qsocket.h"

QSocket::QSocket(QObject *parent): Socket(), QTcpSocket(parent)
{

}

void QSocket::writeStdString(std::string str)
{
    QByteArray byteArray(str.c_str(), str.length());
    QTcpSocket::write(byteArray);
}

QSocket::~QSocket()
{

}
