#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"
#include "user.h"

class Player
{
public:
    Player(User *);

private:

    int score;
    int win;

    User *_user;
    Deck *_heand;
    Deck *_deck;
};

#endif // PLAYER_H
