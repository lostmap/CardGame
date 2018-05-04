#include "party.h"

Party::Party(Player *player1, Player *player2):
    _field(new Field(player1, player2)), _turn(player1)
{
}

bool Party::isMyTern(Player* player)
{
    return _turn == player;
}

Deck* Party::getDeck(Player* player)
{
    return _field->getDeck(player);
}

void Party::changeTurnToPlayer(Player* player)
{
    _turn = player;
}

void Party::makeMove(Player *player1, Player *player2, AbstractCard *card)
{
    // добавляем карту на поле
    _field->addCardToField(player1, card);

    // если соперник не пасанул в предыдущих ходах
    // передаем ход ему
    if (!player2->isPass())
        changeTurnToPlayer(player2);
}

void Party::checkStage(Player *player1, Player *player2)
{
    if (player1->getStageScore() == 2
            || player2->getStageScore() == 2)
        setWinners(player1, player2);
}

void Party::setStageWinner(Player *player1, Player *player2)
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
    _field->reset(player1);
    _field->reset(player2);
}

void Party::pass(Player *player1, Player *player2)
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

void Party::setWinners(Player *player1, Player *player2)
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
