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
 //#define test

    //Variables
    #ifndef test
    vector<playingCard> dealerDeck;
    player playerOne;
    player playerTwo;
    #endif

    #ifdef test
    vector<playingCard> dealerDeck {5};
    player playerOne;
    player playerTwo;
    playerOne.cards.resize(2);
    playerOne.kicker.reserve(3);
    playerTwo.cards.resize(2);
    playerTwo.kicker.resize(3);


    dealerDeck.at(0).face = 2; dealerDeck.at(1).face = 2; dealerDeck.at(2).face = 2; dealerDeck.at(3).face = 9; dealerDeck.at(4).face = 5;
    dealerDeck.at(0).suit = 'D';dealerDeck.at(1).suit = 'D'; dealerDeck.at(2).suit = 'S'; dealerDeck.at(3).suit = 'S'; dealerDeck.at(4).suit = 'S';

    playerOne.cards.at(0).face = 2; playerOne.cards.at(1).face = 11;
    playerOne.cards.at(0).suit = 'D'; playerOne.cards.at(1).suit = 'D';

    playerTwo.cards.at(0).face = 2; playerTwo.cards.at(1).face = 10;
    playerTwo.cards.at(0).suit = 'S'; playerTwo.cards.at(1).suit = 'D';
    #endif

    int playerOneBestHand = 9;
    int playerTwoBestHand = 9;
    const int amountOfDealerCards = 5;
    const int amountOfPlayerCards = 2;
    srand((unsigned int)time(NULL));
    int pool = 0;
    int bust = 0;
    vector<playingCard> totalDeck;
    //Generate Deck of cards
    generateDeck(totalDeck);

    int continueVar = 0;
    cout << "Welcome to the Poker Simulator!" << endl << endl;
    cout <<"Deal Hands?" << endl;
    cout << "[1] To Deal" << endl;
    cin >> continueVar;

while(continueVar == 1){
    int playerOneCurrentBet = 0;
    int playerTwoCurrentBet = 0;
    //Generate Dealer's Deck
    #ifndef test
    dealHand(totalDeck, dealerDeck, amountOfDealerCards);
    //Generate player's Deck
    //player 1
    dealHand(totalDeck, playerOne.cards, amountOfPlayerCards);
    //player 2
    dealHand(totalDeck, playerTwo.cards, amountOfPlayerCards);
    #endif

    /*
    //Deal Player Hands
    dealHand(cardDeck, playerOne, 2);
    dealHand(cardDeck, playerTwo, 2);
    */
    bool player1Folds = false;
    bool player2Folds = false;
    //Display Player's Cards
    cout << "Player 1 : ";
    displayCards(playerOne.cards, amountOfPlayerCards);
    cout << endl;
    std::cout << "Player 1 Chips: " << playerOne.chips << std::endl;
    cout << "Player 2 : ";
    displayCards(playerTwo.cards, amountOfPlayerCards);
    cout << endl;
    std::cout << "Player 2 Chips: " << playerTwo.chips << std::endl;
    cout << "\n";

    /*
     * int betting(vector<playingCard> player, vector<playingCard>& playerTwoHand,
            vector<playingCard>& dealerCards, int& player1Chips,
            int& player2Chips, int& playerOneCurrentBet, int& playerTwoCurrentBet,
            vector<int>& kicker)
            */
    pool = betting(dealerDeck, playerTwo.cards,
                   dealerDeck, playerOne.chips, playerTwo.chips, playerOneCurrentBet, playerTwoCurrentBet,
                   playerTwo.kicker, player1Folds, player2Folds);
    cout << endl;

    //Determine what points players have
    //player 1
    playerOneBestHand = returnBestHand(playerOne.cards, dealerDeck, playerOne.kicker);
    //player 2
    playerTwoBestHand = returnBestHand(playerTwo.cards, dealerDeck, playerTwo.kicker);

    if(player1Folds){
        playerTwo.chips += pool;
        cout << "Player 1 folded" << endl;
    } else if(player2Folds){
        playerOne.chips += pool;
               cout << "Player 2 folded" << endl;
    } else {

    //Check which player has better hand (lower number in is better hand)
    if(playerOneBestHand < playerTwoBestHand) {
        cout << "Player One Wins With A " << winningHands[playerOneBestHand] << "!" << endl;
        std::cout << "They win a pool of " << pool << std::endl;
        playerOne.chips += pool;
    }
    else if(playerTwoBestHand < playerOneBestHand) {
        cout << "Player Two Wins With A " << winningHands[playerTwoBestHand] << "!" << endl;
        std::cout << "They win a pool of " << pool << std::endl;
        playerTwo.chips += pool;
    }
    else if(playerOneBestHand == playerTwoBestHand){
        if(playerOne.kicker.size() > 0){
            for(int i = 0; i < playerOne.kicker.size(); i++){
                if(playerOne.kicker.at(i) > playerTwo.kicker.at(i)){
                    std::cout << "Player 1 wins with a kicker of " << playerOne.kicker.at(i) << std::endl;
                    std::cout << "They win a pool of " << pool << std::endl;
                    playerOne.chips += pool;
                    break;
                }
                else if(playerTwo.kicker.at(i) > playerOne.kicker.at(i)){
                    std::cout << "Player 2 wins with a kicker of " << playerOne.kicker.at(i) << std::endl;
                    std::cout << "They win a pool of " << pool << std::endl;
                    playerTwo.chips += pool;
                    break;
                }
                else if(i == 2){
                    std::cout << "draw" << std::endl;
                    playerOne.chips += playerOneCurrentBet;
                    playerTwo.chips += playerTwoCurrentBet;
                    break;
                }
                else{
                    std::cout << "draw" << std::endl;
                    playerOne.chips += playerOneCurrentBet;
                    playerTwo.chips += playerTwoCurrentBet;
                    break;
                }
            }
        }

    }
    else{
        cout << "draw" << endl;
        playerOne.chips += playerOneCurrentBet;
        playerTwo.chips += playerTwoCurrentBet;
    }
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
    if(playerOne.chips == bust){
        std::cout << "Player 1 is bust, game over" << std::endl;
        break;
    }
    else if(playerTwo.chips == bust){
        std::cout << "Player 2 is bust, game over" << std::endl;
        break;
    }
    cout << endl << "Try Again?" << endl;
    cout << "[1] To Try Again" << endl;
    cin >> continueVar;

    //Empty player and deck hand
    //player 1
    playerOne.cards.clear();
    playerOne.kicker.clear();
    //player 2
    playerTwo.cards.clear();
    playerTwo.kicker.clear();
    dealerDeck.clear();
    pool = 0;


}

    return 0;
}



