#ifndef INTERLAYER_H
#define INTERLAYER_H

#include "game.h"
#include "myserver.h"
#include "socket.h"
#include "pugixml.h"
#include "pugiconfig.h"

#include <string>
#include <memory>
#include <map>

class InterLayer
{
public:
    InterLayer(std::shared_ptr<Game> game, std::shared_ptr<MyServer> server);
    ~InterLayer();

    // парсер приходящих данных
    void parseData(Socket* client, std::string data);

    // отправляет текущее состояние игры
    void sendState(std::string login) const;

    void clientDisconnect(Socket* client);
    void sendPartnerDisconnect(std::string login) const;
    void sendWaitingForPartner(std::string login) const;
    void sendWin(std::string login1, std::string login2) const;

private:
    std::shared_ptr<Game> _game;
    std::shared_ptr<MyServer> _server;

    // соответсвие логина и сокета
    std::map<std::string, Socket*> _socket;
    // соответствие сокета и логина
    std::map<Socket*, std::string> _login;

    Socket* _getSocket(std::string login) const;
    std::string _getLogin(Socket* client) const;
    bool _isSignIn(Socket* client) const;

    void _setConnectionSocketLogin(Socket* client, std::string login);

    // парсер карты
    void _parseCard(QByteArray);
    std::string _parseGetStr3(pugi::xml_document &message,std::string ancestor1,
                              std::string ancestor2, std::string parent) const;

    bool _signIn(pugi::xml_document &message, Socket* client);
    bool _signUp(pugi::xml_document &message, Socket* client);
    bool _start(pugi::xml_document &message, Socket* client) const;
    bool _card(pugi::xml_document &message, Socket* client) const;
    bool _pass(pugi::xml_document &message, Socket* client) const;


};

#endif // INTERLAYER_H
