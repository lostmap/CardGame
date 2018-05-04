#include "player.h"
#include "student.h"
#include <QTime>
#include <QDebug>


#define MAX_STRENGTH 15

Player::Player(User *user):
    _score(0), _pass(false), _win(-1),
    _stageScore(0), _user(user),
    _deck(_deckGenerator()),
    _heand(_heandGenerator())
{
    // куда лучше деть колоду
    // и карты в руке
}

Deck* Player::_deckGenerator()
{
    Deck *newDeck = new Deck();

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));


    for (int i= 0; i < 20; ++i)
    {
        newDeck->addCard(new Student(11 + i, 0, "Student", qrand() % MAX_STRENGTH + 1));
    }

    return newDeck;
}

Deck* Player::_heandGenerator()
{

    Deck *newDeck = new Deck();

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));


    for (int i= 0; i < 10; ++i)
    {
        newDeck->addCard(new Student(i, 0, "Student", qrand() % MAX_STRENGTH + 1));
    }

    return newDeck;

}

void Player::addCardToHeand()
{
    _heand->addCard(_deck->takeLast());
}

QString Player::getLogin()
{
    return _user->getLogin();

}

bool Player::isWin()
{
    return _win == 1;
}

bool Player::isLose()
{
    return _win == 0;
}

Deck* Player::getHeand()
{
    return _heand;
}

bool Player::isPass()
{
    return _pass;
}

void Player::setPass()
{
    _pass = true;
}

void Player::resetPass()
{
    _pass = false;
}

void Player::resetScore()
{
    _score = 0;
}

int Player::getWin()
{
    return _win;
}

bool Player::isInHeand(int cardId)
{
    return _heand->findByCardId(cardId);
}

AbstractCard* Player::removeFromHand(int cardId)
{
    addCardToHeand();
    return _heand->removeCardByCardId(cardId);
}

void Player::addToScore(int cardStrength)
{
    _score += cardStrength;
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

void Player::setWin()
{
    _win = 1;
}

void Player::setLose()
{
    _win = 0;
}

int Player::getStageScore()
{
    return _stageScore;
}

void Player::addStageWin()
{
    _stageScore++;
}
