#include "config.h"


Config::Config(const string& filename)
: xml(ClientParsed(filename)), 
    ADDRESS(xml.GetAddress()),
    PORT(xml.GetPort()),
    CARDS(xml.GetCards()),
    STRENGTH_FONT(xml.GetStrengthFont()),
    INFO_FONT(xml.GetInfoFont()),  
    DROP_AREA_QUANTITY(xml.GetDropAreaQuantity()),
    MY_SPACE(xml.GetMySpace()),
    ENEMY_SPACE(xml.GetEnemySpace()),
    CARD(xml.GetCardProperty()),
    SMALL(xml.GetSmall()),
    MEDIUM(xml.GetMedium()),
    LARGE(xml.GetLarge()),
    ENEMYAREA(xml.GetEnemyArea()),
    DECK(xml.GetDeck()),
    INFO(xml.GetInfo())
    {}