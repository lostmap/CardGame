#include "game.h"


Game::Game(): _interLayer(nullptr), _waitingForCouple("")
{

}

void Game::setInterLayer(InterLayer *interLayer)
{
    _interLayer = interLayer;
}

void Game::logIn(QString login, QString password)
{


}

void Game::signUp(QString login, QString password)
{
    qDebug() << "User " << login << " signup with password "<< password;
    _user[login] = new User(login, password);
}

void Game::findCouple(QString login)
{
    /*if (_waitingForCouple){
        Player *player1 = new Player(_getUser(_waitingForCouple));
        Player *player2 = new Player(_getUser(login));
        startParty(player1, player2);
    }
    else
    {
      _waitingForCouple = login;
    }
    */
}

User* Game::_getUser(QString login)
{
    return _user[login];
}

void Game::_startParty(Player*, Player*)
{
    /*generate
    QMap<Player *, Party *> _party;
    */
}
