#ifndef SERVER_H
#define SERVER_H


#include "Socket.h"
class MyServer;
#include <memory>

#include <QByteArray>
#include <QHostAddress>

class Server
{
public:
    Server();
    virtual ~Server();
    virtual void sendData(Socket *, QByteArray) const = 0;
    void setMyServer(std::shared_ptr<MyServer>);
    virtual bool listen(QHostAddress, int) = 0;

protected:
   std::shared_ptr<MyServer> _myServer;
};


#endif // SERVER_H
