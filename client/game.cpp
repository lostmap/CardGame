#include "game.h"

#include "interlayer.h"


Game::Game(): _interLayer(nullptr), _party(nullptr), _user(nullptr)
{

}

Game::~Game()
{}

void Game::setInterLayer(std::shared_ptr<InterLayer> interLayer)
{
    _interLayer = interLayer;
}

void Game::logIn(std::string login, std::string password)
{
    _user = std::make_shared<User>(login);
}

void Game::signUp(std::string login, std::string password)
{
    
}

std::string Game::getLogin() {
    return _user->getLogin();
}

std::string Game::getPassword() {
    return _user->getPassword();
}

int Game::getScore(){
    return _party->getScore();
}

int Game::getEnemyScore() {
    return _party->getEnemyScore();
}

void Game::pressedEvent(sf::Vector2i mousePosition) {
    _party->pressedEvent(mousePosition);
}

void Game::releasedEvent() {
    int card_id = _party->releasedEvent();
    if(card_id)
        _interLayer->sendCard(card_id);
}

void Game::move(sf::Vector2i mousePosition) {
    _party->move(mousePosition);
}

void Game::startParty()
{
    _party = std::make_shared<Party>(false);
}

void Game::draw(std::shared_ptr<sf::RenderWindow> window, sf::Vector2i mousePosition) {
    _party->draw(window, mousePosition);
}

void Game::pass()
{
    _interLayer->sendPass();
}


void Game::setTurn(int turn) {
    if (_party)
        _party->setTurn(turn);
}
    

void Game::setWin(int win){
    _party->setWin(win);
}

bool Game::passEnemy(){
    return _party->passEnemy();
}

bool Game::myTern() {
    return _party->isMyTern();
}


void Game::setPass() {
    _interLayer->sendPass();
}

void Game::setPlayerInfo(int stageSore,int score, int handSize, int pass) {
    _party->setPlayerInfo(stageSore, score, handSize, pass);
}
    
void Game::setPartnerInfo(int stageScore, int Score, int handSize, int pass) {
    _party->setPartnerInfo(stageScore, Score, handSize, pass);
}

void Game::addHeandCard(std::shared_ptr<AbstractCard> card){
    _party->addHandCard(card);
}
    
void Game::addCardToEnemy(std::shared_ptr<AbstractCard> card) {
    _party->addCardToEnemy(card);
    
}

void Game::addCardToMe(std::shared_ptr<AbstractCard> card) {
    _party->addCardToMe(card);
}
