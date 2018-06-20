#ifndef CONFIG_H
#define CONFIG_H
#include "clientparser.hpp"


enum Property_type {NO_PROPERTY, 
                    Buff, 
                    Spy, 
                    RollCall};

enum Entity_type {NO_ENTITY, BEAR,
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
                    ZOLTAN
                    };

//singleton
class Config {
private:
    Config(const string& filename);
    Config(Config const&) = delete;
    Config& operator= (Config const&) = delete;

    ClientParsed xml;
public:
    static Config& Instance(const string& filename = "") {
        static Config instance(filename);
        return instance;
    }

    const string ADDRESS;
    const int PORT;

    const map<string, Card> CARDS;
    const string STRENGTH_FONT;
    const string INFO_FONT;
    
    const int DROP_AREA_QUANTITY;
    const CordsSize ENEMY_SPACE;
    const CordsSize MY_SPACE;
    
    const CardProperty CARD;

    const CardParam SMALL;
    const CardParam MEDIUM;
    const CardParam LARGE;
    
    const Cords ENEMYAREA;
    const Cords DECK; 
    const Cords INFO;
};

#endif // CONFIG_H
