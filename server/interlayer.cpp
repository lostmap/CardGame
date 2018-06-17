#include "interlayer.h"

#include "game.h"
#include "log.h"

#include "pugixml.h"
#include "pugiconfig.h"

InterLayer::InterLayer(std::shared_ptr<Game> game,
                       std::shared_ptr<MyServer> server):
    _game(game), _server(server)
{

}

InterLayer::~InterLayer() {

    for (auto socket: _socket)
        delete socket.second;
    _socket.clear();
}

std::string InterLayer::_parseGetStr3(pugi::xml_document &message,
                                      std::string ancestor1,
                                      std::string ancestor2,
                                      std::string parent) const
{
    pugi::xml_node node = message.child(ancestor1.c_str()).child(ancestor2.c_str()).child(parent.c_str());
    if (!node.empty())
        return node.text().as_string();

    Log::Instance().error(ancestor1 + " " + ancestor2 + " " + parent + " parsing - fail");
    return std::string();
}

bool InterLayer::_signIn(pugi::xml_document &message, Socket* client)
{
    std::string login = _parseGetStr3(message,"user", "signin", "login");
    std::string password = _parseGetStr3(message,"user", "signin", "password");

    if (!login.empty() && !password.empty()){
        if (_game->signIn(login, password)){
            _setConnectionSocketLogin(client, login);
            _server->sendSuccess(client, "You're successfully sign in");
        }
        else
            _server->sendFail(client, "Sign in fail");
        return true;
    }
    return false;
}

bool InterLayer::_signUp(pugi::xml_document &message, Socket* client)
{
    std::string login = _parseGetStr3(message,"user", "signup", "login");
    std::string password = _parseGetStr3(message,"user", "signup", "password");

    if (!login.empty() && !password.empty()) {
        if (_game->signUp(login, password)) {
            _setConnectionSocketLogin(client, login);
            _server->sendSuccess(client, "You're successfully sign up");
            return true;
        }
        else
            _server->sendFail(client, "Login or password is incorrect");
    }
    return false;
}

bool InterLayer::_start(pugi::xml_document &message, Socket* client) const
{
    pugi::xml_node start = message.child("user").child("start");
    if (start) {
        _game->findCouple(_getLogin(client));
        return true;
    }
    return false;
}

bool InterLayer::_card(pugi::xml_document &message, Socket* client) const
{
    pugi::xml_node cardId = message.child("user").child("card").child("id");
    if (cardId){
        _game->update(_getLogin(client), cardId.text().as_int());
        return true;
    }
    return false;
}

bool InterLayer::_pass(pugi::xml_document &message, Socket* client) const
{
    pugi::xml_node pass = message.child("user").child("pass");
    if (pass) {
        _game->pass(_getLogin(client));
        return true;
    }
    return false;
}

bool InterLayer::_isSignIn(Socket* client) const
{
    return _login.find(client) != _login.end();
}

void InterLayer::parseData(Socket* client, std::string str)
{
    pugi::xml_document message;
    pugi::xml_parse_result result = message.load_string(str.c_str());
    if (result) {
        if (_isSignIn(client)){
            _card(message, client);
            _pass(message, client);
            _start(message, client);
        }
        _signIn(message, client);
        _signUp(message, client);
    }

}

void InterLayer::_setConnectionSocketLogin(Socket* client, std::string login)
{
    if (_socket.find(login) == _socket.end()) {
        _socket[login] = client;
        _login[client] = login;
    }

}

Socket* InterLayer::_getSocket(std::string login) const
{
    if (_socket.find(login) != _socket.end())
        return _socket.at(login);
    return nullptr;
}

std::string InterLayer::_getLogin(Socket *   client) const
{
    if(_login.find(client) != _login.end())
        return _login.at(client);
    return std::string();
}

void InterLayer::sendState(std::string login) const
{
    std::string data = _game->toXML(login);
    _server->sendData(_getSocket(login), data);
}

void InterLayer::clientDisconnect(Socket* client)
{
    auto login = _getLogin(client);
    if (!login.empty()){
        _game->clientDisconnect(login);
        _login.erase(client);
    }
}

void InterLayer::sendPartnerDisconnect(std::string login) const
{
    _server->sendFail(_getSocket(login), "Your partner is disconnected");
}

void InterLayer::sendWaitingForPartner(std::string login) const
{
    _server->sendSuccess(_getSocket(login), "Please wait for a partner");
}

void InterLayer::sendWin(std::string login1, std::string login2) const
{
    _server->sendSuccess(_getSocket(login1), "You win");
    _server->sendFail(_getSocket(login2), "You lose");
}
