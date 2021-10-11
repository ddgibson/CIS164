#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include "Player.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Sort cards in vector by value
vector<int> combineFace(vector<playingCard> player, vector<playingCard> dealer) {
    int i = 0;
    int playerSize = 2;
    vector<int> combinedCards;
    for(i = 0; i < playerSize; i++){
        combinedCards.push_back(player.at(i).face);
    }
    for(i = 0; i < dealer.size(); i++){
        combinedCards.push_back(dealer.at(i).face);
    }
    return combinedCards;
}

vector<char> combineSuit(vector<playingCard> player, vector<playingCard> dealer) {
    int i = 0;
    int playerSize = 2;
    vector<char> combinedCards;
    for(i = 0; i < playerSize; i++){
        combinedCards.push_back(player.at(i).suit);
    }
    for(i = 0; i < dealer.size(); i++){
        combinedCards.push_back(dealer.at(i).suit);
    }
    return combinedCards;
}

vector<int> sortFace(vector<playingCard> player, vector<playingCard> dealer) {
    int i = 0;
    int playerSize = 2;
    vector<int> sortedCards;
    for(i = 0; i < playerSize; i++){
        sortedCards.push_back(player.at(i).face);
    }
    for(i = 0; i < dealer.size(); i++){
        sortedCards.push_back(dealer.at(i).face);
    }
    //Sorts vector
    for (int i = 0; i < sortedCards.size(); i++) {
        for (int j = i; j < (sortedCards.size()); j++) {
            if (sortedCards[i] > sortedCards[j]) {
                std::swap(sortedCards[i], sortedCards[j]);
            }
        }
    }
    return sortedCards;
}
bool findAce(vector<playingCard> player, vector<playingCard> dealer) {
    bool isAce = false;
    int i = 0;
    int playerSize = 2;
    vector<char> combinedCards;
    for(i = 0; i < playerSize; i++){
        combinedCards.push_back(player.at(i).face);
    }
    for(i = 0; i < dealer.size(); i++){
        combinedCards.push_back(dealer.at(i).face);
    }
    for(i = 0; i < combinedCards.size(); i++){
        if(combinedCards.at(i) == 14){
            isAce = true;
        }
    }
    return isAce;
}

//Array of Winning Hands
string winningHands[10] = {"Royal Flush", "Straight Flush", "Four of a Kind", "Full House",
                          "Flush", "Straight", "Three of a Kind", "Two Pair", "Pair", "High Card"};


void generateDeck(vector<playingCard>& deckToCreate);
/*
void dealHand(vector<playingCard>& totalDeck, vector<playingCard>& handToDeal, unsigned int handSize);

void sortCards(vector<playingCard>& hand);
int returnBestHand(vector<playingCard>& sortedHand);
*/
void displayCards(vector<playingCard> hand, int amountOfCards);
bool isFlush(vector<char>& suit);
bool isStraight(vector<int> sortedHand);
bool isFourOfAKind(vector<int> sortedFace, vector<int>& kicker);
bool isFullHouse(vector<int> sortedFace);
bool isThreeOfAKind(vector<int> sortedFace, vector<int>& kicker);
bool isTwoPair(vector<int> sortedFace, vector<int>& kicker);
bool isPair(vector<int> sortedFace, vector<int>& kicker);



//Function to create a deck of cards
void generateDeck(vector<playingCard>& deckToCreate, int cards) {

        playingCard currentCard;

        for(int i = 0; i < cards; i++){
        //Assign each card a value and suit
        int randomFace = rand() % 14 + 2;
        int randomSuit = rand() % 4 + 1;

        //Gives random face
        switch(randomFace){
            case 2:
            currentCard.face = 2;
            break;
            case 3:
            currentCard.face = 3;
            break;
            case 4:
            currentCard.face = 4;
            break;
            case 5:
            currentCard.face = 5;
            break;
            case 6:
            currentCard.face = 6;
            break;
            case 7:
            currentCard.face = 7;
            break;
            case 8:
            currentCard.face = 8;
            break;
            case 9:
            currentCard.face = 9;
            break;
            case 10:
            currentCard.face = 10;
            break;
            case 11:
            currentCard.face = 11;
            break;
            case 12:
            currentCard.face = 12;
            break;
            case 13:
            currentCard.face = 13;
            break;
            case 14:
            currentCard.face = 14;
            break;
        }

        //Gives random suit
        switch (randomSuit) {
            case 1:
            currentCard.suit = 'H';
            break;
            case 2:
            currentCard.suit = 'D';
            break;
            case 3:
            currentCard.suit  = 'C';
            break;
            case 4:
            currentCard.suit = 'S';
            break;
        }

        deckToCreate.push_back(currentCard);
    }

    //Add current card to vector


}

//Function to deal cards out of main deck -- removes cards from main deck and adds them to hand
/*
void dealHand(vector<playingCard>& totalDeck, vector<playingCard> player, unsigned int handSize) {
    //seed for random number
    srand (time(NULL));
    unsigned int randomInt;
    //take cards from totalDeck
    for( unsigned int i = 0; i < handSize; i++) {
        //Generate Random Number
        randomInt = rand() % totalDeck.size();
        //Add card from total deck at the random index to the new hand
        player.setPlayerHand(totalDeck.at(randomInt));
        //Remove card from total deck
        totalDeck.erase(totalDeck.begin() + randomInt);
    }
}
*/


//Display cards
void displayCards(vector<playingCard> player, int amountOfCards) {
    for(int i = 0; i < amountOfCards; i++) {
        if(player.at(i).face == 11){
            std::cout << 'J' << player.at(i).suit << ", ";
        }
        else if(player.at(i).face == 12){
            std::cout << 'Q' << player.at(i).suit << ", ";
        }
        else if(player.at(i).face == 13){
            std::cout << 'K' << player.at(i).suit << ", ";
        }
        else if(player.at(i).face == 14){
            std::cout << 'A' << player.at(i).suit << ", ";
        }
        else{
            std::cout << player.at(i).face << player.at(i).suit << ", ";
        }
    }
}

int addBets(int& player1Chips, int& player2Chips, int& playerOneCurrentBet, int& playerTwoCurrentBet){
    int bet = 0;
    int pool = 0;
    int i = 0;

    while(i == 0){
        std::cout << "Player 1: " << std::endl;
        std::cin >> bet;
        if((player1Chips - bet) > 0){
            player1Chips -= bet;
            pool += bet;
            playerOneCurrentBet += bet;
            break;
        }
        else{
            std::cout << "Too high of a bet" << std::endl;
        }
    }


    while(i == 0){
        std::cout << "Player 2: " << std::endl;
        std::cin >> bet;
        if((player1Chips - bet) > 0){
            player2Chips -= bet;
            pool += bet;
            playerTwoCurrentBet += bet;
            break;
        }
        else{
            std::cout << "Too high of a bet" << std::endl;
        }
    }

    return pool;
}

int betting(vector<playingCard> player, int& player1Chips, int& player2Chips, int& playerOneCurrentBet, int& playerTwoCurrentBet) {
    const int betRound2Cards = 3;
    const int betRound3Cards = 4;
    const int allCards = 5;
    int pool = 0;

    std::cout << "Please place your blind bets:" << std::endl;

    pool += addBets(player1Chips, player2Chips, playerOneCurrentBet, playerTwoCurrentBet);

    std::cout << "\nDealers's Cards: ";
    for(int i = 0; i < betRound2Cards; i++) {
        if(player.at(i).face == 11){
            std::cout << 'J' << player.at(i).suit << ", ";
        }
        else if(player.at(i).face == 12){
            std::cout << 'Q' << player.at(i).suit << ", ";
        }
        else if(player.at(i).face == 13){
            std::cout << 'K' << player.at(i).suit << ", ";
        }
        else if(player.at(i).face == 14){
            std::cout << 'A' << player.at(i).suit << ", ";
        }
        else{
            std::cout << player.at(i).face << player.at(i).suit << ", ";
        }
    }

    std::cout << "\n\nPlease place your bets:" << std::endl;

    pool += addBets(player1Chips, player2Chips,playerOneCurrentBet, playerTwoCurrentBet);

    std::cout << "\nDealer's cards: ";
    for(int i = 0; i < betRound3Cards; i++) {
        if(player.at(i).face == 11){
            std::cout << 'J' << player.at(i).suit << ", ";
        }
        else if(player.at(i).face == 12){
            std::cout << 'Q' << player.at(i).suit << ", ";
        }
        else if(player.at(i).face == 13){
            std::cout << 'K' << player.at(i).suit << ", ";
        }
        else if(player.at(i).face == 14){
            std::cout << 'A' << player.at(i).suit << ", ";
        }
        else{
            std::cout << player.at(i).face << player.at(i).suit << ", ";
        }
    }

    std::cout << "\n\nPlease place your bets:" << std::endl;

    pool += addBets(player1Chips, player2Chips,playerOneCurrentBet, playerTwoCurrentBet);

    std::cout << "\nDealer's full hand: ";
    for(int i = 0; i < allCards; i++) {
        if(player.at(i).face == 11){
            std::cout << 'J' << player.at(i).suit << ", ";
        }
        else if(player.at(i).face == 12){
            std::cout << 'Q' << player.at(i).suit << ", ";
        }
        else if(player.at(i).face == 13){
            std::cout << 'K' << player.at(i).suit << ", ";
        }
        else if(player.at(i).face == 14){
            std::cout << 'A' << player.at(i).suit << ", ";
        }
        else{
            std::cout << player.at(i).face << player.at(i).suit << ", ";
        }
    }
    return pool;
}


//Checking Card Hands
int returnBestHand(vector<playingCard> player, vector<playingCard> dealer, vector<int>& kicker) {
    //player and dealer's face combined and sorted
    vector<int> sortedFace = sortFace(player,dealer);
    //player and dealer's face combined
    vector<int> combinedFaces = combineFace(player,dealer);
    //player and dealer's face combined
    vector<char> combinedSuits = combineSuit(player,dealer);
    bool foundAce = findAce(player, dealer);
    int winningHand = 9;
    bool flush = false;
    bool straight = false;

    if(isFlush(combinedSuits)){
        flush = true;
    }
    if(isStraight(sortedFace)){
        straight = true;
    }
    //Checking for straight flush/ Royal Flush
    if(flush && straight) {
        //Checking for Royal Flush (if highest card is Ace)
        if(foundAce == true) {
            winningHand = 0;
        } else {
            winningHand = 1;
        }
    }
    else if(isFourOfAKind(sortedFace, kicker)){
        winningHand = 2;
    }
    else if(isFullHouse(sortedFace)){
        winningHand = 3;
    }
    else if(isFlush(combinedSuits)) {
        winningHand = 4;
    }
    else if(isStraight(sortedFace)) {
        winningHand = 5;
    }
    else if(isThreeOfAKind(sortedFace, kicker)){
        winningHand = 6;
    }
    else if(isTwoPair(sortedFace, kicker)){
        winningHand = 7;
    }
    else if(isPair(sortedFace, kicker)){
        winningHand = 8;
    }
    else {
        winningHand = 9;
    }
    return winningHand;

};


//Functions to check for individual hands

//Checks if player has a flush as a hand
bool isFlush(vector<char>& suit) {
    //declare counter variables
    int flushSize = 5;
    int diamonds = 0, hearts = 0, clubs = 0, spades = 0;
    bool isFlush = false;
    for(unsigned int i = 0; i < suit.size(); i++){
        if(suit.at(i) == 'D'){
            ++diamonds;
        }
        else if(suit.at(i)== 'H'){
            ++hearts;
        }
        else if(suit.at(i) == 'C'){
           ++clubs;
         }
        else if(suit.at(i) == 'S'){
            ++spades;
        }

    }
    if((diamonds >= flushSize) || (hearts >= flushSize) || (clubs >= flushSize) || (spades >= flushSize)) {
        isFlush = true;
    }
    return isFlush;
}

//Checks if player has a straight as a hand
bool isStraight(vector<int> sortedFace){
    //removes duplicates
    sortedFace.erase(std::unique(std::begin(sortedFace),std::end(sortedFace)), std::end(sortedFace));

    bool isStraight = false;
    if(sortedFace.size() == 5){
        if(sortedFace.at(1) == sortedFace.at(0) + 1
           && sortedFace.at(2) == sortedFace.at(1) + 1
           && sortedFace.at(3) == sortedFace.at(2) + 1
           && sortedFace.at(4) == sortedFace.at(3) + 1)
        {
           isStraight = true;
        }
    }
    if(sortedFace.size() == 6){
        if(sortedFace.at(1) == sortedFace.at(0) + 1
            && sortedFace.at(2) == sortedFace.at(1) + 1
            && sortedFace.at(3) == sortedFace.at(2) + 1
            && sortedFace.at(4) == sortedFace.at(3) + 1
            //&& sortedFace.at(5) == sortedFace.at(4) + 1
            )
        {
           isStraight = true;
        }
    }
    if(sortedFace.size() == 7){
        if(sortedFace.at(1) == sortedFace.at(0) + 1
            && sortedFace.at(2) == sortedFace.at(1) + 1
            && sortedFace.at(3) == sortedFace.at(2) + 1
            && sortedFace.at(4) == sortedFace.at(3) + 1
            //&& sortedFace.at(5) == sortedFace.at(4) + 1
            //&& sortedFace.at(6) == sortedFace.at(5) + 1
            )
        {
           isStraight = true;
        }
    }


    return isStraight;
}

//Checks if player has a four of a kind as a hand
bool isFourOfAKind(vector<int> sortedFace, vector<int>& kickers){
    bool isFourOfAKind = false;
    int face = 0;
    int counter = 0;
    int cardToDelete1 = 0;
    int cardToDelete2 = 0;
    int cardToDelete3 = 0;
    int cardToDelete4 = 0;

    for(int i = 0; i < sortedFace.size(); i++){
        counter = 0;
        face = sortedFace.at(i);
        for(int y = 1; y < sortedFace.size(); y++){
            if(face == sortedFace.at(y)){
                ++counter;
                if(counter == 1){
                    cardToDelete1 = y;
                }
                if(counter == 2){
                    cardToDelete2 = y;
                }
                if(counter == 3){
                    cardToDelete3 = y;
                }
                if(counter == 4){
                    cardToDelete4 = y;
                    sortedFace.erase(sortedFace.begin() + cardToDelete1);
                    sortedFace.erase(sortedFace.begin() + cardToDelete2-1);
                    sortedFace.erase(sortedFace.begin() + cardToDelete3-2);
                    sortedFace.erase(sortedFace.begin() + cardToDelete4-3);

                    kickers.push_back(sortedFace.at(2));
                    kickers.push_back(sortedFace.at(1));
                    isFourOfAKind = true;
                }
            }
        }
    }

    return isFourOfAKind;
};

//Checks if player has a full house as a hand
bool isFullHouse(vector<int> sortedFace) {
    bool isFullHouse = false;
    bool threeOfKind = false;
    bool pair = false;
    int face = 0;
    int counter = 0;
    int cardToDelete = 0;
    vector<int> kickers;

    //First pair
    for(int i = 0; i < sortedFace.size(); i++){
        counter = 0;
        face = sortedFace.at(i);
        for(int y = 1; y < sortedFace.size(); y++){
            if(face == sortedFace.at(y)){
                ++counter;
                if(counter == 3){
                    cardToDelete = sortedFace.at(y);
                    sortedFace.erase(std::remove(sortedFace.begin(), sortedFace.end(), cardToDelete), sortedFace.end());
                    threeOfKind = true;
                    break;
                }
            }
        }
    }

    //Second pair
    for(int i = 0; i < sortedFace.size(); i++){
        counter = 0;
        face = sortedFace.at(i);
        for(int y = 1; y < sortedFace.size(); y++){
            if(face == sortedFace.at(y)){
                ++counter;
                if(counter == 2){
                    cardToDelete = sortedFace.at(y);
                    pair = true;
                }
            }
        }
    }

    if(threeOfKind == true && pair == true){
        isFullHouse = true;
    }

    return isFullHouse;
};

//Checks if player has a three of a kind as a hand
bool isThreeOfAKind(vector<int> sortedFace, vector<int>& kickers) {
    bool isThreeOfAKind = false;
    int face = 0;
    int counter = 0;
    int cardToDelete1 = 0;
    int cardToDelete2 = 0;
    int cardToDelete3 = 0;

    for(int i = 0; i < sortedFace.size(); i++){
        counter = 0;
        face = sortedFace.at(i);
        for(int y = 1; y < sortedFace.size(); y++){
            if(face == sortedFace.at(y)){
                ++counter;
                if(counter == 1){
                    cardToDelete1 = y;
                }
                if(counter == 2){
                    cardToDelete2 = y;
                }
                if(counter == 3){
                    cardToDelete3 = y;

                    sortedFace.erase(sortedFace.begin() + cardToDelete1);
                    sortedFace.erase(sortedFace.begin() + cardToDelete2-1);
                    sortedFace.erase(sortedFace.begin() + cardToDelete3-2);

                    kickers.push_back(sortedFace.at(3));
                    kickers.push_back(sortedFace.at(2));

                    isThreeOfAKind = true;
                }
            }
        }
    }

    return isThreeOfAKind;
};

//Checks if player has a two pairs as a hand.

/* Sorts faces and then looks for similarities.
 * If a pair is found, the 1st pair is deleted
 * and searches for another. */
bool isTwoPair(vector<int> sortedFace, vector<int>& kickers) {
    bool isTwoPair = false;
    bool pair1 = false;
    bool pair2 = false;
    int face = 0;
    int counter = 0;
    int y = 1;

    for(int i = 0; i < sortedFace.size(); i++){
        if(pair1 == true){
            break;
        }
        counter = 0;
        face = sortedFace.at(i);
        for(y = 0; y < sortedFace.size(); y++){
            if(face == sortedFace.at(y)){
                ++counter;
                if(counter == 2){
                    sortedFace.erase(sortedFace.begin() + i);
                    sortedFace.erase(sortedFace.begin() + y-1);
                    pair1 = true;
                    break;
                }
            }
        }
    }
    if(pair1 == true){
        for(int i = 0; i < sortedFace.size(); i++){
            if(pair2 == true){
                break;
            }
            counter = 0;
            face = sortedFace.at(i);
            for(int y = 0; y < sortedFace.size(); y++){
                if(face == sortedFace.at(y)){
                    ++counter;
                    if(counter == 2){
                        sortedFace.erase(sortedFace.begin() + i);
                        sortedFace.erase(sortedFace.begin() + y-1);

                        kickers.push_back(sortedFace.at(2));

                        pair2 = true;
                        break;
                    }
                }
            }
        }
    }

    if(pair1 == true && pair2 == true){
        isTwoPair = true;
    }

    return isTwoPair;
};

//Checks if player has a pair as a hand
bool isPair(vector<int> sortedFace, vector<int>& kickers){
    bool isPair = false;
    int face = 0;
    int counter = 0;
    kickers.resize(0);

    for(int i = 0; i < sortedFace.size(); i++){
        counter = 0;
        face = sortedFace.at(i);
        for(int y = 0; y < sortedFace.size(); y++){
            if(face == sortedFace.at(y)){
                ++counter;
                if(counter == 2){
                    isPair = true;

                    sortedFace.erase(sortedFace.begin() + i);
                    sortedFace.erase(sortedFace.begin() + y-1);

                    kickers.push_back(sortedFace.at(4));
                    kickers.push_back(sortedFace.at(3));
                    kickers.push_back(sortedFace.at(2));
                    break;
                }
            }
        }
    }

    return isPair;
};

#endif // DEALER_H
