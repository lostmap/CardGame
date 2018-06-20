#include "player.h"


Player::Player():
    _score(0), _pas(false), _win(false),
    _stageScore(0), _handSize(0)
{
    
}


bool Player::isWin()
{
    return _win;
}

bool Player::isLose()
{
    return !_win;
}


bool Player::isPass()
{
    return _pas;
}

void Player::setPass()
{
    _pas = true;
}

void Player::resetPass()
{
    _pas = false;
}

void Player::resetScore()
{
    _score = 0;
}

int Player::getWin()
{
    return _win;
}


int Player::getScore()
{
    return _score;
}

void Player::reset()
{
    resetScore();
    resetPass();

}

void Player::setWin(int win)
{
    _win = win;
}

void Player::setLose()
{
    _win = false;
}

int Player::getStageScore()
{
    return _stageScore;
}

void Player::addStageWin()
{
    _stageScore++;
}

void Player::setInfo(int stageScore,int score, int handSize, int pass) {
    setStageScore(stageScore);
    setScore(score);
    setHandSize(handSize);
    if (pass)
        setPass();
}

void Player::setStageScore(int stageScore) {
    _stageScore = stageScore;
}

void Player::setScore(int score) {
    _score = score;
}

void Player::setHandSize(int handSize) {
    _handSize = handSize;
}