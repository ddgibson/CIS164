//created by apestotnik, 9/24/21
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Player.h"
#include "Dealer.h"
using namespace std;

int main()
{
// #define test

    //Variables
    #ifndef test
    vector<playingCard> dealerDeck;
    vector<playingCard> playerOneHand;
    vector<playingCard> playerTwoHand;
    #endif

    #ifdef test
    vector<playingCard> dealerDeck {5};
    vector<playingCard> playerOneHand {2};
    vector<playingCard> playerTwoHand {2};

    dealerDeck.at(0).face = 7; dealerDeck.at(1).face = 1; dealerDeck.at(2).face = 11; dealerDeck.at(3).face = 11; dealerDeck.at(4).face = 5;
    dealerDeck.at(0).suit = 'D';dealerDeck.at(1).suit = 'H'; dealerDeck.at(2).suit = 'H'; dealerDeck.at(3).suit = 'S'; dealerDeck.at(4).suit = 'S';

    playerOneHand.at(0).face = 10; playerOneHand.at(1).face = 11;
    playerOneHand.at(0).suit = 'D'; playerOneHand.at(1).suit = 'D';

    playerTwoHand.at(0).face = 7; playerTwoHand.at(1).face = 7;
    playerTwoHand.at(0).suit = 'S'; playerTwoHand.at(1).suit = 'D';
    #endif

    int playerOneBestHand = 9;
    int playerTwoBestHand = 9;
    const int amountOfDealerCards = 5;
    const int amountOfPlayerCards = 2;
    srand((unsigned int)time(NULL));

    int continueVar = 0;
    cout << "Welcome to the Poker Simulator!" << endl << endl;
    cout <<"Deal Hands?" << endl;
    cout << "[1] To Deal" << endl;
    cin >> continueVar;

while(continueVar == 1){
    //Generate Dealer's Deck
    #ifndef test
    generateDeck(dealerDeck, amountOfDealerCards);
    //Generate player's Deck
    generateDeck(playerOneHand, amountOfPlayerCards);
    generateDeck(playerTwoHand, amountOfPlayerCards);
    #endif

    /*
    //Deal Player Hands
    dealHand(cardDeck, playerOne, 2);
    dealHand(cardDeck, playerTwo, 2);
    */

    //Display Player's Cards
    cout << "Player 1 : ";
    displayCards(playerOneHand, amountOfPlayerCards);
    cout << endl;
    cout << "Player 2 : ";
    displayCards(playerTwoHand, amountOfPlayerCards);
    cout << endl;
    cout << "Dealer : ";
    displayCards(dealerDeck, amountOfDealerCards);
    cout << endl;

    //Determine what points players have
    playerOneBestHand = returnBestHand(playerOneHand, dealerDeck);
    playerTwoBestHand = returnBestHand(playerTwoHand, dealerDeck);

    //Check which player has better hand (lower number in is better hand)
    if(playerOneBestHand < playerTwoBestHand) {
        cout << "Player One Wins With A " << winningHands[playerOneBestHand] << "!" << endl;
    }
    else if(playerTwoBestHand < playerOneBestHand) {
        cout << "Player Two Wins With A " << winningHands[playerTwoBestHand] << "!" << endl;
    }
    else{
        cout << "draw" << endl;
    }
    //Start comparing high cards if both players have same point
    /*
    else {
        for(unsigned int i = playerOneHand.size(); i > 0; --i){
            if(playerOneHand.at(i-1).value > playerTwoHand.at(i-1).value) {
                cout << "Player One Wins With A " << winningHands[playerOneBestHand] << "!" << endl;
                break;
        }
            else if(playerTwoHand.at(i-1).value > playerOneHand.at(i-1).value) {
                cout << "Player Two Wins With A " << winningHands[playerOneBestHand] << "!" << endl;
                break;
        }
            if(i == 1) {
                cout << "Draw!" << endl << endl;
            }
        }
    }
    */
    cout << endl << "Try Again?" << endl;
    cout << "[1] To Try Again" << endl;
    cin >> continueVar;
	
	//Empty player and deck hand
    playerOneHand.clear();
    playerTwoHand.clear();
    dealerDeck.clear();
}

    return 0;
}



