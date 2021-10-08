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
bool isFlush(vector<playingCard>& suit);
bool isStraight(vector<int> sortedHand);
bool isFourOfAKind(vector<int> sortedFace, vector<int>& kickerGrabber);
bool isFullHouse(vector<int> sortedFace);
bool isThreeOfAKind(vector<int> sortedFace);
bool isTwoPair(vector<int> sortedFace);
bool isPair(vector<int> sortedFace);



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
        std::cout << player.at(i).face << player.at(i).suit << ", ";
    }
}


//Checking Card Hands
int returnBestHand(vector<playingCard> player, vector<playingCard> dealer) {
    //player and dealer's face combined and sorted
    vector<int> sortedFace = sortFace(player,dealer);
    //player and dealer's face combined
    vector<int> combinedFaces = combineFace(player,dealer);
    //kickers
    vector<int> kicker;
    bool foundAce = findAce(player, dealer);
    int winningHand = 9;
    bool flush = false;
    bool straight = false;

    if(isFlush(player)){
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
    else if(isFlush(player)) {
        winningHand = 4;
    }
    else if(isStraight(sortedFace)) {
        winningHand = 5;
    }
    else if(isThreeOfAKind(sortedFace)){
        winningHand = 6;
    }
    else if(isTwoPair(sortedFace)){
        winningHand = 7;
    }
    else if(isPair(sortedFace)){
        winningHand = 8;
    }
    else {
        winningHand = 9;
    }
    return winningHand;

};


//Functions to check for individual points/hands

bool isFlush(vector<playingCard>& suit) {
    //declare counter variables
    int flushSize = 5;
    int diamonds = 0, hearts = 0, clubs = 0, spades = 0;
    bool isFlush = false;
    for(unsigned int i = 0; i < suit.size(); i++){
        if(suit.at(i).suit == 'D'){
            diamonds++;
        }
        else if(suit.at(i).suit == 'H'){
            hearts++;
        }
        else if(suit.at(i).suit == 'C'){
           clubs++;
         }
        else {
            spades++;
        }

    }
    if(diamonds == flushSize || hearts == flushSize || clubs == flushSize || spades == flushSize) {
        isFlush = true;
    }
    return isFlush;
}

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
        if(sortedFace.at(2) == sortedFace.at(1) + 1
           && sortedFace.at(3) == sortedFace.at(2) + 1
           && sortedFace.at(4) == sortedFace.at(3) + 1
           && sortedFace.at(5) == sortedFace.at(4) + 1)
        {
           isStraight = true;
        }
    }
    if(sortedFace.size() == 7){
        if(sortedFace.at(3) == sortedFace.at(2) + 1
           && sortedFace.at(4) == sortedFace.at(3) + 1
           && sortedFace.at(5) == sortedFace.at(4) + 1
           && sortedFace.at(6) == sortedFace.at(5) + 1)
        {
           isStraight = true;
        }
    }


    return isStraight;
}

bool isFourOfAKind(vector<int> sortedFace, vector<int>& kickerGrabber){
    bool isFourOfAKind = false;
    int face = 0;
    int counter = 0;
    int cardToDelete = 0;
    vector<int> kickers;

    for(int i = 0; i < sortedFace.size(); i++){
        counter = 0;
        face = sortedFace.at(i);
        for(int y = 1; y < sortedFace.size(); y++){
            if(face == sortedFace.at(y)){
                ++counter;
                if(counter == 4){
                    cardToDelete = sortedFace.at(y);
                    isFourOfAKind = true;
                }
            }
        }
    }

    // uses algorithm to remove four of a kind to get kicker
    sortedFace.erase(std::remove(sortedFace.begin(), sortedFace.end(), cardToDelete), sortedFace.end());
    kickerGrabber = sortedFace;

    return isFourOfAKind;
};

bool isFullHouse(vector<int> sortedFace) {
    bool isFullHouse = false;
    bool threeOfKind = false;
    bool pair = false;
    int face = 0;
    int counter = 0;
    int cardToDelete = 0;
    vector<int> kickers;

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

bool isThreeOfAKind(vector<int> sortedFace) {
    bool isThreeOfAKind = false;
    int face = 0;
    int counter = 0;
    int cardToDelete = 0;
    vector<int> kickers;

    for(int i = 0; i < sortedFace.size(); i++){
        counter = 0;
        face = sortedFace.at(i);
        for(int y = 1; y < sortedFace.size(); y++){
            if(face == sortedFace.at(y)){
                ++counter;
                if(counter == 3){
                    cardToDelete = sortedFace.at(y);
                    isThreeOfAKind = true;
                }
            }
        }
    }

    return isThreeOfAKind;
};

bool isTwoPair(vector<int> sortedFace) {
    bool isTwoPair = false;
    bool pair1 = false;
    bool pair2 = false;
    int face = 0;
    int counter = 0;
    int cardToDelete = 0;
    vector<int> kickers;

    for(int i = 0; i < sortedFace.size(); i++){
        counter = 0;
        face = sortedFace.at(i);
        for(int y = 1; y < sortedFace.size(); y++){
            if(face == sortedFace.at(y)){
                ++counter;
                if(counter == 2){
                    cardToDelete = sortedFace.at(y);
                    sortedFace.erase(std::remove(sortedFace.begin(), sortedFace.end(), cardToDelete), sortedFace.end());
                    pair1 = true;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < sortedFace.size(); i++){
        counter = 0;
        face = sortedFace.at(i);
        for(int y = 1; y < sortedFace.size(); y++){
            if(face == sortedFace.at(y)){
                ++counter;
                if(counter == 2){
                    cardToDelete = sortedFace.at(y);
                    pair2 = true;
                }
            }
        }
    }

    if(pair1 == true && pair2 == true){
        isTwoPair = true;
    }

    return isTwoPair;
};

bool isPair(vector<int> sortedFace){
    bool isPair = false;
    int face = 0;
    int counter = 0;
    int cardToDelete = 0;
    vector<int> kickers;

    for(int i = 0; i < sortedFace.size(); i++){
        counter = 0;
        face = sortedFace.at(i);
        for(int y = 1; y < sortedFace.size(); y++){
            if(face == sortedFace.at(y)){
                ++counter;
                if(counter == 2){
                    cardToDelete = sortedFace.at(y);
                    isPair = true;
                }
            }
        }
    }
};

#endif // DEALER_H
