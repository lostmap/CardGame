#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "socket.h"
#include "myserver.h"
#include <memory>

#include <QByteArray>

class Server: public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent = nullptr);
    ~Server();
    void sendData(Socket *  ,QByteArray) const;
    void setMyServer(std::shared_ptr<MyServer>);

private slots:
    void readyRead();
    void disconnected();

protected:
   void incomingConnection(int socketfd);

private:
   std::shared_ptr<MyServer> _myServer;
};


#endif // SERVER_H
