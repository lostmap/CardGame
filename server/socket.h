#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>
#include <QObject>

#include <string>

class Socket: public QTcpSocket
{
public:
        Socket(QObject *parent = nullptr);
        ~Socket();
        void writeStdString(std::string str);
};

#endif // SOCKET_H
