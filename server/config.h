#ifndef CONFIG_H
#define CONFIG_H

#include "configparser.h"

#include <string>
#include <map>

enum PROPERTY_TYPE: int {
                    NO_PROPERTY,
                    Buff,
                    Spy,
                    RollCall,
                    PROPERTIES};

enum ENTITY_TYPE: int {
                    NO_ENTITY, BEAR,
                    AGLAIS, BLUE_BOY,
                    CERYS, CIRI,
                    CORAL, EITHNEL,
                    EMISSARY, ENCHANT,
                    EREDIN, GERALT,
                    GREEN, IDA,
                    IORVETH, KEIRA,
                    LAMIA, MORENN,
                    PIRATEL, ROAR_BEAR,
                    SCOUT, SIREN,
                    STENNIS, SUPPORT,
                    TEMERIAN, TRIDAM,
                    TRISS, YENNEFER,
                    YOANA, ZIGRIN,
                    ZOLTAN,
                    ENTITIES
                    };


//singleton
class Config {
private:
    ConfigParser _xml;

    Config(const std::string& filename);
    Config(Config const&) = delete;
    Config& operator= (Config const&) = delete;

    std::map<ENTITY_TYPE, std::string> _entityInfo;
    std::map<PROPERTY_TYPE, std::string> _propertyInfo;

public:
    static Config& Instance(const std::string& filename = "") {
        static Config instance(filename);
        return instance;
    }

    const int PORT;
    const int HAND_SIZE;
    const int DECK_SIZE;
    const int MAX_STRENGTH;
    const int BUFF_RATE;
    const int WIN_SCORE;

    std::string getInfo(ENTITY_TYPE) const;
    std::string getInfo(PROPERTY_TYPE) const;
    std::string getInfo(ENTITY_TYPE, PROPERTY_TYPE) const;

};
#endif // CONFIG_H
