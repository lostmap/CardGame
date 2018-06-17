#ifndef GAME_H
#define GAME_H

class InterLayer;

#include "player.h"
#include "user.h"
#include "party.h"
#include "qdomserializer.h"


#include <string>
#include <map>
#include <memory>


class Game: QDomSerializer
{
public:
    Game();
    ~Game() = default;


    void setInterLayer(std::shared_ptr<InterLayer> interLayer);
    bool signIn(std::string login, std::string password);
    bool signUp(std::string login, std::string password);

    // поиск соперника для игры
    void findCouple(std::string login);
    std::shared_ptr<Player> getCouple(std::shared_ptr<Player>) const;

    // обновление игры после хода игрока
    void update(std::string login, int cardId);
    // игрок пасанул
    void pass(std::string login);

    // методы для взаимодействия с промежуточным слоем
    std::string getPartnerLogin(std::string login) const;

    void clientDisconnect(std::string login);

    std::string toXML(std::string login);

private:
    std::shared_ptr<InterLayer> _interLayer;
    // соттветствие логина и пользователя
    std::map<std::string, std::shared_ptr<User>> _user;
    // соответствие пользователя и игрока
    std::map<std::shared_ptr<User>, std::shared_ptr<Player>> _player;
    // соответствие двух игроков в партии
    std::map<std::shared_ptr<Player>, std::shared_ptr<Player>> _couple;
    // соответствие игрока и текущей партии
    std::map<std::shared_ptr<Player>, std::shared_ptr<Party>> _party;

    // пользоваель ожидающий соперника
    std::string _waitingForCouple;

    std::shared_ptr<User> _getUser(std::string) const;
    std::shared_ptr<Player> _getPlayerByLogin(std::string) const;
    void _startParty(std::shared_ptr<Player>, std::shared_ptr<Player>);
    std::shared_ptr<Party> _getPartyByPlayer(std::shared_ptr<Player>) const;
    std::shared_ptr<Player> _getPartner(std::shared_ptr<Player>) const;
    std::string _getLogin(std::shared_ptr<Player>) const;
    bool _isPlaying(std::string login) const;
    bool _isPartyOver(std::shared_ptr<Player>, std::shared_ptr<Player>) const;
    bool _deleteParty(std::string login);

};

#endif // GAME_H
