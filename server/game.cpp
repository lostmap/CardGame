#include "game.h"
#include "interlayer.h"


Game::Game(): _interLayer(nullptr)
{

}

void Game::setInterLayer(std::shared_ptr<InterLayer> interLayer)
{
    _interLayer = interLayer;
}

bool Game::signIn(std::string login, std::string password)
{
    return _user.find(login) == _user.end() && _user.at(login)->checkPassword(password);
}

bool Game::signUp(std::string login, std::string password)
{
    if (_user.find(login) == _user.end()){
        _user[login] = std::make_shared<User>(login, password);
        return true;
    }
    return false;
}

bool Game::_isPlaying(std::string login) const
{
    return _player.find(_getUser(login)) != _player.end();
}

void Game::findCouple(std::string login)
{
    // если вы уже не стоите в очереди на ожидание
    // и еще не играите
    if ( _waitingForCouple != login && !_isPlaying(login)){
        // есть ли ожидающий пользователь
        if (!_waitingForCouple.empty()){

            // создает игроков
            auto player1 = std::make_shared<Player>(_getUser(_waitingForCouple));
            auto player2 = std::make_shared<Player>(_getUser(login));

            // объединяет их в пару
            _player[_getUser(_waitingForCouple)] = player1;
            _player[_getUser(login)] = player2;
            _couple[player1] = player2;
            _couple[player2] = player1;

            // создается партия
            _startParty(player1, player2);
            _waitingForCouple = "";
        }
        else
        {
          _waitingForCouple = login;
          _interLayer->sendWaitingForPartner(login);
        }
    }

}


void Game::_startParty(std::shared_ptr<Player> player1,
                       std::shared_ptr<Player> player2)
{
    auto newParty = std::make_shared<Party>(player1, player2);

    _party[player1] = newParty;
    _party[player2] = newParty;

    // отправляется начальное состояние игрокам
    _interLayer->sendState(_getLogin(player1));
    _interLayer->sendState(_getLogin(player2));
}


void Game::update(std::string login, int cardId)
{
    std::shared_ptr<Player> player = _getPlayerByLogin(login);
    auto party = _getPartyByPlayer(_getPlayerByLogin(login));
    // проверка очереди хода и наличия брошенной карты в руке
    if (party->isMyTern(player) && player->isInHand(cardId)) {
        // делаем ход
        party->makeMove(player, getCouple(player), player->removeFromHand(cardId));
    }

    if (_isPartyOver(player, getCouple(player)))
        _deleteParty(player->getLogin());
    else {
        // отпрвляем данные
        _interLayer->sendState(_getLogin(player));
        _interLayer->sendState(_getLogin(getCouple(player)));
    }
}

bool Game::_isPartyOver(std::shared_ptr<Player> player1,
                        std::shared_ptr<Player> player2) const
{
    if (player1->isWin())
    {
        _interLayer->sendWin(player1->getLogin(), player2->getLogin());
        return true;
    }

    if (player2->isWin())
    {
        _interLayer->sendWin(player2->getLogin(), player1->getLogin());
        return true;
    }
    return false;
}

bool Game::_deleteParty(std::string login)
{
    if (_user.find(login) != _user.end()){
        auto user = _user.at(login);

        if (_player.find(user) != _player.end()){
            auto player = _player.at(user);
            auto partner = _couple.at(player);

            _couple.erase(player);
            _couple.erase(partner);

            _party.erase(player);
            _party.erase(partner);

            _player.erase(user);
            _player.erase(_getUser(partner->getLogin()));
            return true;
        }
    }
    return false;
}

// игрок сделал пас
void Game::pass(std::string login)
{
    auto player1 = _getPlayerByLogin(login);
    std::shared_ptr<Party> party = _getPartyByPlayer(player1);
    auto player2 = getCouple(player1);

    party->pass(player1, player2);

    if (_isPartyOver(player1, player2))
        _deleteParty(player1->getLogin());
    else {
        _interLayer->sendState(_getLogin(player1));
        _interLayer->sendState(_getLogin(player2));
    }
}

std::string Game::getPartnerLogin(std::string login) const
{
    return _getUser(login)->getLogin();
}

std::shared_ptr<Player> Game::_getPartner(std::shared_ptr<Player> player) const
{
    if (_couple.find(player) != _couple.end())
        return _couple.at(player);
    return nullptr;
}

std::shared_ptr<User> Game::_getUser(std::string login) const
{
    if (_user.find(login) != _user.end())
        return _user.at(login);
    return nullptr;
}

std::shared_ptr<Player> Game::getCouple(std::shared_ptr<Player> player) const
{
    if (_couple.find(player) != _couple.end())
        return _couple.at(player);
    return nullptr;
}

std::string Game::_getLogin(std::shared_ptr<Player> player) const
{
    return player->getLogin();
}

std::shared_ptr<Player> Game::_getPlayerByLogin(std::string login) const
{
    if (_player.find(_getUser(login)) != _player.end())
        return _player.at(_getUser(login));
    return nullptr;
}

std::shared_ptr<Party> Game::_getPartyByPlayer(std::shared_ptr<Player> player) const
{
    if (_party.find(player) != _party.end())
        return _party.at(player);
    return nullptr;
}

std::string Game::toXML(std::string login)
{
    std::shared_ptr<Player> player = _getPlayerByLogin(login);
    return partyToXML(_party[player], player, _getPartner(player));
}

void Game::clientDisconnect(std::string login)
{
    if (_deleteParty(login))
            _interLayer->sendPartnerDisconnect(getPartnerLogin(login));
}

