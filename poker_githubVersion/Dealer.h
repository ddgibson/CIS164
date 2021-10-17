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
void generateDeck(vector<playingCard>& deckToCreate) {
    char currentSuit;
    playingCard currentCard;
    //Assign each card a value and suit
    for(unsigned int i = 2; i < 15; ++i){
        //Determine Suit
        for(unsigned int suitVar = 0; suitVar < 4; suitVar++){

            //Assign Suit
            switch(suitVar) {
                case 0 :
                    currentSuit = 'D';
                break;
            case 1 :
                    currentSuit = 'H';
                break;
            case 2 :
                currentSuit = 'C';
                break;
            case 3 :
                currentSuit = 'S';
                break;
            default :
                currentSuit = 'I';
            }

            currentCard.face = i;
            currentCard.suit = currentSuit;

            //Add current card to vector
            deckToCreate.push_back(currentCard);
        }
    }

}

//Function to deal cards out of main deck -- removes cards from main deck and adds them to hand
void dealHand(vector<playingCard>& totalDeck, vector<playingCard>& handToDeal, unsigned int handSize) {
    unsigned int randomInt;
    //take cards from totalDeck
    for( unsigned int i = 0; i < handSize; i++) {
        //Generate Random Number
        randomInt = rand() % totalDeck.size();
        //Add card from total deck at the random index to the new hand
        handToDeal.push_back(totalDeck.at(randomInt));
        //Remove card from total deck
        totalDeck.erase(totalDeck.begin() + randomInt);
    }
}


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

//Player 2AI Bet
int aiBet(int& totalChips, vector<playingCard>& playerHand, vector<playingCard> dealerCards,
          vector<int> kicker, int roundNumber ){
    //Variables
    int betPercent;
    int randomPercentIncrease;
    int winningHand;
    int bet;
//    cout << playerHand.at(0).face << " " << playerHand.at(1).face << endl;

    //If on first round (no community cards turned) check if ai has pair and bet accordingly
    if(roundNumber == 0){
        if(playerHand.at(0).face == playerHand.at(1).face){
            //determine how high of a pair player has
            int highCardValue = playerHand.at(0).face;
            //Make bigger bet depending on how high the pair is
            if(highCardValue < 5){
                betPercent = 5;
            } else if(highCardValue < 10){
                betPercent = 10;
            } else if(highCardValue < 14){
                betPercent = 20;
            } else {
                betPercent = 30;
            }
            randomPercentIncrease = rand() % (60 - betPercent);
            betPercent = betPercent + randomPercentIncrease;
        } else {
            betPercent = 0;
        }
    }
    //if cards are on the table, evaluate ai player's hand and bet accordingly
    else{
        winningHand = returnBestHand(playerHand, dealerCards, kicker);
//        cout << "Winning hand: " << winningHand << endl;
        //Go all in if player has royal flush, straight flush, or 4 of a kind
       if(winningHand < 3){
           betPercent = 100;
       } else {
           //Make random percentage increase for sake of chance
           randomPercentIncrease = rand() % winningHand;
           //Formula to generate percentage of chips player will bet
           betPercent = ((10 - (winningHand + 1)) * 10);
           if(winningHand < 7){
               betPercent += (randomPercentIncrease * (10 - roundNumber));
           }
       }
    }
    bet = (betPercent/100.00) * totalChips;
    return bet;
}

int addBets(int& player1Chips, int& player2Chips, int& playerOneCurrentBet,
            int& playerTwoCurrentBet, vector<playingCard>& playerTwoHand,
            vector<playingCard>& dealerCards, vector<int>& kicker, int roundNumber,
            bool& player1Folded, bool& player2Folded){
    int bet = 0;
    int pool = 0;
    int i = 0;
    int opponentBet = 0;
    int responseVar;
    int raiseBy = 0;

    //ai bet
    while(i == 0){
        std::cout << "Player 2: " << std::endl;
        bet = aiBet(player2Chips, playerTwoHand, dealerCards, kicker, roundNumber);
        //Make sure AI Player has enough chips for the bet
        if((player2Chips - bet) >= 0){
        //If bet is more chips than player1 has, change bet to be max amount of chips that player1 has
            if(player1Chips - bet < 0){
                bet = player1Chips;
            }
            player2Chips -= bet;
            pool += bet;
            playerTwoCurrentBet += bet;
            cout << "Player 2 bets: " << bet << endl;
            opponentBet = bet;
            break;
        }
        else{
            std::cout << "Too high of a bet" << std::endl;
        }
    }

    while(i == 0){
        if(opponentBet >= player1Chips) {
            std::cout << "Opponent's bet will put you all in. Do you wish to call[1], or fold[0]?" << endl;
            std::cin >> responseVar;
            while(responseVar < 0 || responseVar > 2){
                std::cout << "Sorry, that was not an option" << endl;
                std::cout << "Player 1: Do you wish to call[1], or fold[0]?" << std::endl;
                cin >> responseVar;
            }
        } else{
        std::cout << "Player 1: Do you wish to call[1], raise[2], or fold[0]?" << std::endl;
        std::cin >> responseVar;
        while(responseVar < 0 || responseVar > 3){
            std::cout << "Sorry, that was not an option" << endl;
            std::cout << "Player 1: Do you wish to call[1], raise[2], or fold[0]?" << std::endl;
            cin >> responseVar;
        }
        }
        if(responseVar == 1){
            bet = opponentBet;
            cout << "You called the bet of: " << opponentBet;
        } else if (responseVar == 2) {
            std::cout << "How much do you wish to raise by?" << endl;
            std::cin >> raiseBy;

            while(opponentBet + raiseBy > player1Chips){
                std::cout << "Sorry, you do not have enough chips to raise by that much" << endl;
                std::cout << "How much do you wish to raise by?" << endl;
                std::cin >> raiseBy;
            }

            //If player tries to raise by more chips than opponent has, change bet to just put ai all in
            while(raiseBy > player2Chips){
                std::cout << "Opponent does not have that many chips" << endl;
                std::cout << "Bet will be reduced to " << player2Chips << " to put opponent all in" << endl;
                raiseBy = player2Chips;
            }
            bet = opponentBet + raiseBy;
        }
        else {
            std::cout << "You folded" << endl;
            player1Folded = true;
            break;
        }

        if((player1Chips - bet) >= 0){
            player1Chips -= bet;
            pool += bet;
            playerOneCurrentBet += bet;
            if(playerOneCurrentBet > playerTwoCurrentBet) {
                int playerTwoCalls = (rand() % 6) + 1;
                if(playerTwoCalls <= 2) {
                    cout << "Player 2 Folds " << endl;
                    player2Folded = true;
                } else {
                    cout << "Player 2 calls your bet " << endl;
                    player2Chips -= raiseBy;
                    pool += raiseBy;
                    playerTwoCurrentBet += raiseBy;
                }
            }
            break;
        }
        else{
            std::cout << "Too high of a bet" << std::endl;
        }
    }
    return pool;
}

int betting(vector<playingCard> player, vector<playingCard>& playerTwoHand,
            vector<playingCard>& dealerCards, int& player1Chips,
            int& player2Chips, int& playerOneCurrentBet, int& playerTwoCurrentBet,
            vector<int>& kicker, bool& player1Folded, bool& player2Folded) {
    const int betRound2Cards = 3;
    const int betRound3Cards = 4;
    const int allCards = 5;
    int pool = 0;
    int roundNumber = 0;

    std::cout << "Please place your blind bets:" << std::endl;

    pool += addBets(player1Chips, player2Chips, playerOneCurrentBet,
                    playerTwoCurrentBet, playerTwoHand, dealerCards,
                    kicker, roundNumber, player1Folded, player2Folded);

    //Continue if neither player has folded
    if(!(player1Folded || player2Folded)){
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
    }

    //increment round number
    roundNumber++;

    //Continue if neither player has folded
    if(!(player1Folded || player2Folded)){
            if(player1Chips > 0 && player2Chips > 0){
    std::cout << "\n\nPlease place your bets:" << std::endl;

    pool += addBets(player1Chips, player2Chips, playerOneCurrentBet,
                    playerTwoCurrentBet, playerTwoHand, dealerCards,
                    kicker, roundNumber, player1Folded, player2Folded);
    }

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
    }
    roundNumber++;

    //Continue if neither player has folded
    if(!(player1Folded || player2Folded)){
            if(player1Chips > 0 && player2Chips > 0){
    std::cout << "\n\nPlease place your bets:" << std::endl;


    pool += addBets(player1Chips, player2Chips, playerOneCurrentBet,
                    playerTwoCurrentBet, playerTwoHand, dealerCards,
                    kicker, roundNumber, player1Folded, player2Folded);
    }

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
    }

    //Continue if neither player has folded
    if(!(player1Folded || player2Folded)){
         if(player1Chips > 0 && player2Chips > 0){
    std::cout << "\n\nPlease place your bets:" << std::endl;

    pool += addBets(player1Chips, player2Chips, playerOneCurrentBet,
                    playerTwoCurrentBet, playerTwoHand, dealerCards,
                    kicker, roundNumber, player1Folded, player2Folded);
    }
    }

    return pool;
}






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
