#include "client.h"

#include "config.h"
#include "interlayer.h"
#include "log.h"

#include <iostream>

Client::Client():_interLayer(nullptr){

	sf::Socket::Status status = connect(Config::Instance().ADDRESS, Config::Instance().PORT);
    if (status != sf::Socket::Done)
    
        Log::Instance().error("couldn't connect to " + Config::Instance().ADDRESS);
    else
        Log::Instance().log("connect to " + Config::Instance().ADDRESS);
        
}

void Client::signUp(std::string login, std::string password) {
    sendSignUp(login, password);
}

void Client::signIn(std::string login, std::string password) {
    sendSignIn(login, password);
}

Client::~Client(){

}


sf::Socket::Status Client::connect(const std::string ipaddr, unsigned short port){
    return socket.connect(ipaddr, port);
}

sf::Socket::Status Client::sendData(std::string data){
    return socket.send(data.c_str(), data.size());
}

sf::Socket::Status Client::sendSignIn(std::string login, std::string password){
    std::string sendData = ("<user><signin><login>" + login + "</login><password>" + password +
                             "</password></signin></user>");
    return socket.send(sendData.c_str(), sendData.size());
}

sf::Socket::Status Client::sendSignUp(std::string login, std::string password){
    std::string sendData = ("<user><signup><login>" + login + "</login><password>" + password +
                             "</password></signup></user>");
    return socket.send(sendData.c_str(), sendData.size());
}

sf::Socket::Status Client::sendCard(int id){
    std::string s = "<user><card><id>" + std::to_string(id) + "</id></card></user>";
    return socket.send(s.c_str(), s.size());
}

sf::Socket::Status Client::sendStart(){
    std::string s = "<user><start>1</start></user>";
    return socket.send(s.c_str(), s.size());
}

sf::Socket::Status Client::sendPass(){
    std::string s = "<user><pass>0</pass></user>";
    return socket.send(s.c_str(), s.size());
}

std::string Client::getMessage(){
    socket.setBlocking(false);
    char buffer[BUFFER_LIMIT];
    std::size_t recieved;
    std::string msg = "";
    sf::Socket::Status status;

    while(RECEIVE_LIMIT < 256){
        status = socket.receive(buffer, BUFFER_LIMIT, recieved);
        std::string tmp = std::string(buffer, recieved);
        msg += tmp;
        if(recieved < BUFFER_LIMIT){
            break;
        }
    }

    if (msg != "")
        std::cout<<msg<<std::endl;

    socket.setBlocking(true);
    return msg;
}


void Client::setInterLayer(std::shared_ptr<InterLayer> interLayer)
{
    _interLayer = interLayer;
}

