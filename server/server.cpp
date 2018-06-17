#include "server.h"

#include "myserver.h"

Server::Server(): _myServer(nullptr)
{

}

Server::~Server() {}

void Server::setMyServer(std::shared_ptr<MyServer> myServer)
{
    _myServer = myServer;
}
