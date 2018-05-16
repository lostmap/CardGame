#include "player.h"
#include <QTime>
#include <QDebug>

#include "entitywithbuff.h"
#include "entityspy.h"


Player::Player(User *user):
    _score(0), _pas(false), _win(-1),
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


    for (int i= HEAND_SIZE; i < 4; ++i)
    {
        newDeck->addCard(new EntityWithBuff(i, "Dragon with couple buff", Dragon, qrand() % MAX_STRENGTH + 1));
    }

    for (int i= 4; i < DECK_SIZE; ++i)
    {
        newDeck->addCard(new EntitySpy(i, "Woodcutter Spy", Woodcutter, qrand() % MAX_STRENGTH + 1));
    }

    return newDeck;
}

Deck* Player::_heandGenerator()
{

    Deck *newDeck = new Deck();

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));


    for (int i= 0; i < 4; ++i)
    {
        newDeck->addCard(new EntityWithBuff(i, "Dragon", Dragon, qrand() % MAX_STRENGTH + 1));
    }

    for (int i= 4; i < HEAND_SIZE; ++i)
    {
        newDeck->addCard(new EntitySpy(i, "Woodcutter Spy", Woodcutter, qrand() % MAX_STRENGTH + 1));
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

bool Player::isInHeand(int cardId)
{
    return _heand->findByCardId(cardId);
}

AbstractCard* Player::removeFromHand(int cardId)
{
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

void Player::ReestablishHand()
{
    while(_heand->size() < HEAND_SIZE)
    {
        addCardToHeand();
    }

}

QDomElement Player::toQDomElementWithHeand(QString playerName)
{
    QDomDocument document;
    QDomElement node = document.createElement(playerName);

    node.appendChild(toQDomElement(playerName));
    node.appendChild(_heand->toQDomElement("heand"));

   return node;
}

QDomElement Player::toQDomElement(QString playerName)
{
    QDomDocument document;
    QDomElement node = document.createElement(playerName);

    node.appendChild(_domElement("stagescore", getStageScore()));
    node.appendChild(_domElement("score", getScore()));
    node.appendChild(_domElement("heandsize", _heand->size()));

    isPass()?node.appendChild(_domElement("pass", 1)):
             node.appendChild(_domElement("pass", 0));

    return node;
}

QDomElement Player::_domElement(QString elementName, int value)
{
    QDomDocument document;

    QDomElement element = document.createElement(elementName);
    QDomText text = document.createTextNode(QString::number(value));
    element.appendChild(text);

    return element;
}

