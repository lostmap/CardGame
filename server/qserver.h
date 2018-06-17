#ifndef QSERVER_H
#define QSERVER_H

#include "socket.h"
#include "qserver.h"
#include "myserver.h"

#include <memory>

#include <QTcpServer>
#include <QByteArray>

class QServer: public QTcpServer, public Server
{
    Q_OBJECT
public:
    QServer(QObject *parent = nullptr);
    ~QServer();
    void sendData(Socket *  ,QByteArray) const;
    bool listen(QHostAddress, int);


private slots:
    void readyRead();
    void disconnected();

protected:
   void incomingConnection(int socketfd);

};

#endif // QSERVER_H
