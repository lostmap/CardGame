#ifndef SERIALIZER_H
#define SERIALIZER_H

class Party;

#include <string>
#include <memory>

class Serializer
{
public:
    Serializer() {}
    virtual std::string partyToXML(std::shared_ptr<Party>, std::shared_ptr<Player>, std::shared_ptr<Player>) const  = 0;
};

#endif // SERIALIZER_H
