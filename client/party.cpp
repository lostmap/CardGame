#include "party.h"


Party::Party(bool turn):
    _field(new Field()), 
    _hand(new Deck()),
    _turn(turn),
    _me(new Player()),
    _partner(new Player()),
    _info(new Info())
{
}

Party::~Party()
{}

int Party::getScore() {
    return _me->getScore();
    
}

int Party::getEnemyScore() {
    return _partner->getScore();
}


void Party::setTurn(int turn) {
    _turn = turn;
}

bool Party::isMyTern() {
    return _turn;
}

bool Party::passEnemy() {
    return _partner->isPass();
}

void Party::pressedEvent(sf::Vector2i mousePosition) {
    _hand->pressedEvent(mousePosition);
}

int Party::releasedEvent() {
    if (_field)
        return _hand->releasedEvent(_field, _turn);
    return 0;
}

void Party::move(sf::Vector2i mousePosition) {
    _hand->move(mousePosition);
}

void Party::draw(std::shared_ptr<sf::RenderWindow> window, sf::Vector2i mousePosition) {
    _field->draw(window);
    _info->draw(window, _hand->contains(mousePosition), _field->contains(mousePosition));
    _hand->draw(window);
}
    

void Party::setWin(int win){
    _me->setWin(win);
    if (win)
        _partner->setWin(0);
    else
        if (win == -1)
            _partner->setWin(-1);
        else
            _partner->setWin(1);
}

void Party::setPlayerInfo(int stageScore,int score, int handSize, int pass) {
    _me->setInfo(stageScore, score, handSize, pass);
}
    
void Party::setPartnerInfo(int stageScore, int Score, int handSize, int pass) {
    _partner->setInfo(stageScore, Score, handSize, pass);
}

void Party::addHandCard(std::shared_ptr<AbstractCard> card){
    _hand->addCard(card);
}
    
void Party::addCardToEnemy(std::shared_ptr<AbstractCard> card) {
    _field->addCardToEnemy(card);
    
}

void Party::addCardToMe(std::shared_ptr<AbstractCard> card) {
    _field->addCardToMe(card);
}
