#include "configparser.h"
#include "config.h"
#include "log.h"

#include "pugixml.h"
#include "pugiconfig.h"

ConfigParser::ConfigParser(std::string xml): doc(std::make_shared<pugi::xml_document>())

{
    doc->load_file(xml.c_str());
    if (doc->empty())
        Log::Instance().error("Config load - fail");
    else
        Log::Instance().log("Config load - success");
}

ConfigParser::~ConfigParser() {}

int ConfigParser::_parseGetInt2(std::string ancestor, std::string parent) const
{
    pugi::xml_node node = doc->child(ancestor.c_str()).child(parent.c_str());
    if (!node.empty()){
        Log::Instance().log(ancestor + " " + parent + " parsing " + std::to_string(node.text().as_int()));
        return node.text().as_int();
    }

    Log::Instance().error(ancestor + " " + parent + " parsing - fail");
    return 0;
}

int ConfigParser::getPort() const {

    return _parseGetInt2("server", "port");
}

int ConfigParser::getHandSize() const
{
   return _parseGetInt2("server", "handsize");
}

int ConfigParser::getDeckSize() const
{
    return _parseGetInt2("server", "decksize");
}

int ConfigParser::getMaxStrength() const
{
    return _parseGetInt2("server", "maxstrength");
}

int ConfigParser::getBuffRate() const {
    return _parseGetInt2("server", "buffrate");
}

int ConfigParser::getWinScore() const {
     return _parseGetInt2("server", "winscore");
}

std::map<ENTITY_TYPE, std::string> ConfigParser::getEntitiesInfo() const
{

    std::map<ENTITY_TYPE, std::string> buff;
    int entity = NO_ENTITY;
    pugi::xml_node entities = doc->child("server").child("entities");

    if (!entities.empty())
        for (pugi::xml_node entityNode: entities.children()) {
            buff.insert(std::make_pair((ENTITY_TYPE)entity++, entityNode.text().as_string()));
          }
    else
        Log::Instance().error("Entities parsing - fail");

    return buff;
}

std::map<PROPERTY_TYPE, std::string> ConfigParser::getPropertiesInfo() const {
    std::map<PROPERTY_TYPE, std::string> buff;
    int property = NO_PROPERTY;
    pugi::xml_node properties = doc->child("server").child("properties");

    if (!properties.empty()){
        for (pugi::xml_node propetyNode: properties.children())
            buff.insert(std::make_pair((PROPERTY_TYPE)property++, propetyNode.text().as_string()));
          }
    else
        Log::Instance().error("Properties parsing - fail");

    return buff;
}

