#ifndef QSOCKET_H
#define QSOCKET_H

#include <QTcpSocket>
#include <QObject>

#include "socket.h"

#include <string>

class QSocket: public Socket, public QTcpSocket
{
public:
    QSocket(QObject *parent = nullptr);
    ~QSocket();
    void writeStdString(std::string str);
};

#endif // QSOCKET_H
