#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
using namespace std;

//Declare struct for playing cards
struct playingCard{
    int face;
    char suit;
};

struct player{
    vector<playingCard> cards;
    int chips = 1000;
    vector<int> kicker;
};

/*
class PlayerClass{
    private:
    std::vector<playingCard> playerHand;

    public:
    std::vector<playingCard> getPlayerHand()
    {
        return playerHand;
    }
    void setPlayerHand(playingCard value)
    {
        &playerHand.push_back(value);
    }
    void emptyPlayerHand()
    {
        playerHand.clear();
    }

};

//AI class
class CPU:PlayerClass{

};
*/

#endif // PLAYER_H
