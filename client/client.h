#ifndef CLIENT_H
#define CLIENT_H


class InterLayer;

#include <SFML/Network.hpp>
#include <string>
#include <memory>

class Client {

public:
    Client();
    ~Client();
    sf::Socket::Status connect(const std::string ipaddr, unsigned short port);
    sf::Socket::Status sendData(std::string data);
    sf::Socket::Status sendSignIn(std::string login, std::string password);
    sf::Socket::Status sendSignUp(std::string login, std::string password);
    sf::Socket::Status sendCard(int id);
    sf::Socket::Status sendStart();
    sf::Socket::Status sendPass();
    
    std::string getMessage();
    void setInterLayer(std::shared_ptr<InterLayer>);

    void signUp(std::string login, std::string password);
    void signIn(std::string login, std::string password);
    

private:
    std::shared_ptr<InterLayer> _interLayer;
    const unsigned short RECEIVE_LIMIT = 255;
    const unsigned short BUFFER_LIMIT = 127;
    sf::TcpSocket socket;
};

#endif // CLIENT_H
