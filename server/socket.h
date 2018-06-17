#ifndef SOCKET_H
#define SOCKET_H

#include <string>

class Socket
{
public:
    Socket() {}
    virtual ~Socket() {}
    virtual void writeStdString(std::string str) = 0;

};

#endif // SOCKET_H
