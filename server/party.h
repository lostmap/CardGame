#ifndef PARTY_H
#define PARTY_H

class Player;
class Deck;
class Field;
class AbstractCard;

#include <memory>

class Party
{
public:
    Party(std::shared_ptr<Player>, std::shared_ptr<Player>);
    ~Party();

    bool isMyTern(std::shared_ptr<Player>) const;

    // ход игрока
    void makeMove(std::shared_ptr<Player>, std::shared_ptr<Player>, std::shared_ptr<AbstractCard>);

    // передает ход игроку
    void changeTurnToPlayer(std::shared_ptr<Player>);

    // если игрок сделал пас
    void pass(std::shared_ptr<Player>, std::shared_ptr<Player>);

    // определяет победителей во всей игре
    void setWinners(std::shared_ptr<Player>, std::shared_ptr<Player>);

    // проверяет нужна ли еще игра для определения победителя
    void checkStage(std::shared_ptr<Player>, std::shared_ptr<Player>);

    // определяет победителя в текущей стадии
    void setStageWinner(std::shared_ptr<Player>, std::shared_ptr<Player>);

    std::shared_ptr<Field> getField() const;

private:
    std::shared_ptr<Field> _field;
    std::shared_ptr<Player> _turn;
};

#endif // PARTY_H
