#include "myserver.h"
#include "interlayer.h"

#include "socket.h"

#include "pugixml.h"
#include "pugiconfig.h"

MyServer::MyServer(std::shared_ptr<Server> server): _server(server)
{

}

MyServer::~MyServer() {}

void MyServer::setInterLayer(std::shared_ptr<InterLayer> interLayer)
{
     _interLayer = interLayer;
}

void MyServer::sendData(Socket* client, std::string data) const
{
    client->writeStdString(data);
}

struct xml_string_writer : pugi::xml_writer
{
    std::string result;

    virtual void write(const void* data, size_t size)
    {
        result += std::string(static_cast<const char*>(data), size);
    }
};

std::string MyServer::_createXmlNode(std::string nodeName, std::string data) const
{
   pugi::xml_document doc;
   pugi::xml_node serverNode = doc.append_child("server");
   pugi::xml_node node = serverNode.append_child(nodeName.c_str());
   node.append_child(pugi::node_pcdata).set_value(data.c_str());
   xml_string_writer writer;
   doc.save(writer);
   return writer.result;
}

void MyServer::sendSuccess(Socket* client, std::string successMessage) const
{
   client->writeStdString(_createXmlNode("success", successMessage));
}


void MyServer::sendFail(Socket* client, std::string failMessage) const
{
   client->writeStdString(_createXmlNode("fail", failMessage));
}

void MyServer::newClient(Socket* client)
{
    _clientData[client] = std::string();
}

void MyServer::_parseData(Socket* client, std::string data) const
{
    _interLayer->parseData(client, data);
}

void MyServer::clientDisconnect(Socket* client)
{
    _interLayer->clientDisconnect(client);
    _clientData.erase(client);
}

bool MyServer::_chekData(std::string data) const
{
    if (data.find("</user>") != std::string::npos) {
        return true;
    }
    return false;
}

void MyServer::readData(Socket* client, std::string data)
{
    _clientData[client] += data;
    if (_chekData(data))
    {
        std::string clentData = _clientData[client];
        _clientData[client].clear();
        _parseData(client, clentData);
    }
}
