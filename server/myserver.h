#ifndef MYSERVER_H
#define MYSERVER_H

class InterLayer;
class Server;
class Socket;

#include <memory>
#include <string>
#include <map>

class MyServer
{
public:
    MyServer(std::shared_ptr<Server>);
    ~MyServer();

    void newClient(Socket* client);

    void setInterLayer(std::shared_ptr<InterLayer> interLayer);
    void readData(Socket* client, std::string data);
    void sendData(Socket* client,std::string data) const;
    void sendSuccess(Socket* client, std::string successMessage) const;
    void sendFail(Socket* client, std::string failMessage) const;
    void sendPartnerDisconnect(Socket *client) const;

    void clientDisconnect(Socket* client);

private:
       std::shared_ptr<InterLayer> _interLayer;
       std::map<Socket*, std::string> _clientData;
       std::shared_ptr<Server> _server;

       void _parseData(Socket*  client, std::string data) const;
       bool _chekData(std::string data) const;
       std::string _createXmlNode(std::string nodeName, std::string data) const;
};

#endif // MYSERVER_H
