#include "party.h"

#include "player.h"
#include "deck.h"
#include "field.h"
#include "abstractcard.h"


Party::Party(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2):
    _field(std::move(std::unique_ptr<Field>(new Field(player1, player2)))), _turn(player1)
{
}

Party::~Party() {}

bool Party::isMyTern(std::shared_ptr<Player> player) const
{
    return _turn == player;
}

void Party::changeTurnToPlayer(std::shared_ptr<Player> player)
{
    _turn = player;
}

void Party::makeMove(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2, std::shared_ptr<AbstractCard> card)
{
    // добавляем карту на поле
    _field->addCardToField(player1, player2,  card);

    // увеличиваем счет игрока
    player1->addToScore(card->getStrength());

    // если соперник не пасанул в предыдущих ходах
    // передаем ход ему
    if (!player2->isPass())
        changeTurnToPlayer(player2);
}

void Party::checkStage(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2)
{
    if (player1->getStageScore() == 2
            || player2->getStageScore() == 2)
        setWinners(player1, player2);
}

void Party::setStageWinner(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2)
{
    if (player1->getScore() > player2->getScore())
    {
        player1->addStageWin();
        changeTurnToPlayer(player1);
    }
    else{
        player2->addStageWin();
        changeTurnToPlayer(player2);
    }
    player1->reset();
    player2->reset();
    _field->reset();
}

void Party::pass(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2)
{
    if (isMyTern(player1))
    {
        player1->setPass();

        // если противник уже пасанул
        // конец игры, объявляем победителей
        if (player2->isPass()){
            setStageWinner(player1, player2);
            checkStage(player1, player2);
        }
        else
        {
            changeTurnToPlayer(player2);
        }
    }
}

void Party::setWinners(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2)
{
    if (player1->getStageScore() > player2->getStageScore())
    {
        player1->setWin();
        player2->setLose();
    }
    else
    {
        player2->setWin();
        player1->setLose();
    }
}

std::shared_ptr<Field> Party::getField() const
{
    return _field;
}

