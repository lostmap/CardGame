#include "game.h"
#include "interlayer.h"


Game::Game(): _interLayer(nullptr)
{

}

void Game::setInterLayer(InterLayer *interLayer)
{
    _interLayer = interLayer;
}

void Game::logIn(QString login, QString password)
{

}

int Game::getStageScore(QString login)
{
    return (_getPlayerByLogin(login))->getStageScore();
}

void Game::signUp(QString login, QString password)
{
    qDebug() << "User " << login << " signup with password "<< password;
    _user[login] = new User(login, password);
}

void Game::findCouple(QString login)
{
    // есть ли ожидающий пользователь
    if (!_waitingForCouple.isEmpty()){

        // создает игроков
        Player *player1 = new Player(_getUser(_waitingForCouple));
        Player *player2 = new Player(_getUser(login));

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
    }

}

bool Game::_isMyTern(Player* player)
{
    return _party[player]->isMyTern(player);
}

Deck* Game::_getDeck(Player* player)
{
    return _party[player]->getDeck(player);
}

Deck* Game::getDeck(QString login)
{
    return _getDeck(_getPlayerByLogin(login));
}

Deck* Game::getPartnerDeck(QString login)
{
    return _getDeck(_getPartner(_getPlayerByLogin(login)));
}

Deck* Game::getHeand(QString login)
{
    return _getPlayerByLogin(login)->getHeand();
}

User* Game::_getUser(QString login)
{
    return _user[login];
}

Player* Game::getCouple(Player* player)
{
    return _couple[player];
}


void Game::_startParty(Player* player1, Player* player2)
{
    Party * newParty = new Party(player1, player2);

    _party[player1] = newParty;
    _party[player2] = newParty;

    // отправляется начальное состояние игрокам
    _interLayer->sendState(_getLogin(player1));
    _interLayer->sendState(_getLogin(player2));
}

QString Game::_getLogin(Player *player)
{
    return player->getLogin();
}

Player* Game::_getPlayerByLogin(QString login)
{
    return _player[_user[login]];
}

Party* Game::_getPartyByPlayer(Player *player)
{
    return _party[player];
}

int Game::isMyTern(QString login)
{
    return _isMyTern(_getPlayerByLogin(login));
}

void Game::update(QString login, int cardId)
{
    // находит игроков
    Player *player = _getPlayerByLogin(login);
    Party *party = _getPartyByPlayer(player);
    // проверка очереди хода и наличия брошенной карты в руке
    if (party->isMyTern(player) && player->isInHeand(cardId)) {
        // делаем ход
        party->makeMove(player, getCouple(player), player->removeFromHand(cardId));
    }

    // отпрвляем данные
    _interLayer->sendState(_getLogin(player));
    _interLayer->sendState(_getLogin(getCouple(player)));
}

// игрок сделал пас
void Game::pass(QString login)
{
    Player *player1 = _getPlayerByLogin(login);
    Party *party = _getPartyByPlayer(player1);
    Player *player2 = getCouple(player1);

    party->pass(player1, player2);

    _interLayer->sendState(_getLogin(player1));
    _interLayer->sendState(_getLogin(player2));
}

QString Game::getPartnerLogin(QString login)
{
    return _getUser(login)->getLogin();
}

Player* Game::_getPartner(Player* player)
{
    return _couple[player];
}

int Game::getScore(QString login)
{
    return (_getPlayerByLogin(login))->getScore();
}

int Game::winValue(QString login)
{
    return (_getPlayerByLogin(login))->getWin();
}

int Game::getPartnerScore(QString login)
{
    return _getPartner(_getPlayerByLogin(login))->getScore();
}


