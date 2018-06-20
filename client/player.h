#ifndef PLAYER_H
#define PLAYER_H

#include "config.h"

#include <string>

class Player
{
public:
    Player();

    bool isWin();
    void setWin(int);
    int getWin();

    void setLose();
    bool isLose();

    bool isPass();
    void setPass();
    void resetPass();

    void setScore(int);
    int getScore();

    void setStageScore(int);
    int getStageScore();

    void setHandSize(int);

    void addStageWin();
    void resetScore();
    void reset();
    void setInfo(int stageSore,int score, int heandSize, int pass);

private:

    // количество очков в стадии
    int _score;
    bool _pas;
    bool _win;
    int _handSize;
    // количество побед в партии
    int _stageScore;
};

#endif // PLAYER_H
