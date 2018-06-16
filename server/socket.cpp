#include "socket.h"

Socket::Socket(QObject *parent) : QTcpSocket(parent)
{

}

Socket::~Socket()
{

}

void Socket::writeStdString(std::string str)
{
    QByteArray byteArray(str.c_str(), str.length());
    QTcpSocket::write(byteArray);
}
