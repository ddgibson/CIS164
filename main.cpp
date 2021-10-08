//Andy Pestotnik | ampestotnik@dmacc.edu | September 2021
//Working model of poker simulator, demonstrating ability to deal cards and evaluate poker hands

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Declare struct for playing cards
struct playingCard{
    string face;
    string suit;
    int value;
};

//Array of Winning Hands
string winningHands[10] = {"Royal Flush", "Straight Flush", "Four of a Kind", "Full House",
                          "Flush", "Straight", "Three of a Kind", "Two Pair", "Pair", "High Card"};


void generateDeck(vector<playingCard>& deckToCreate);
void dealHand(vector<playingCard>& totalDeck, vector<playingCard>& handToDeal, unsigned int handSize);
void displayCards(vector<playingCard>& hand);
void sortCards(vector<playingCard>& hand);

int returnBestHand(vector<playingCard>& sortedHand);

bool isFlush(vector<playingCard>& sortedHand);
bool isStraight(vector<playingCard>& sortedHand);
bool isFourOfAKind(vector<playingCard>& sortedHand);
bool isFullHouse(vector<playingCard>& sortedHand);
bool isThreeOfAKind(vector<playingCard>& sortedHand);
bool isTwoPair(vector<playingCard>& sortedHand);
bool isPair(vector<playingCard>& sortedHand);


int main()
{
    //Variables
    vector<playingCard> cardDeck;
    vector<playingCard> playerOneHand;
    vector<playingCard> playerTwoHand;
    int playerOneBestHand = 9;
    int playerTwoBestHand = 9;

    int continueVar = 0;
    cout << "Welcome to the Poker Simulator!" << endl << endl;
    cout <<"Deal Hands?" << endl;
    cout << "[1] To Deal" << endl;
    cin >> continueVar;

while(continueVar == 1){
    //Generate Card Deck
    generateDeck(cardDeck);

    //Deal Player Hands
    dealHand(cardDeck, playerOneHand, 5);
    dealHand(cardDeck, playerTwoHand, 5);

    //Sort Player Hands
    sortCards(playerOneHand);
    sortCards(playerTwoHand);

    //Display Player's Cards
    cout << "Player 1 : ";
    displayCards(playerOneHand);
    cout << endl;
    cout << "Player 2 : ";
    displayCards(playerTwoHand);
    cout << endl;

    //Determine what points players have
    playerOneBestHand = returnBestHand(playerOneHand);
    playerTwoBestHand = returnBestHand(playerTwoHand);

    //Check which player has better hand (lower number in is better hand)
    if(playerOneBestHand < playerTwoBestHand) {
        cout << "Player One Wins With A " << winningHands[playerOneBestHand] << "!" << endl;
    }
    else if(playerTwoBestHand < playerOneBestHand) {
        cout << "Player Two Wins With A " << winningHands[playerTwoBestHand] << "!" << endl;
    }
    //Start comparing high cards if both players have same point
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
    cout << endl << "Try Again?" << endl;
    cout << "[1] To Try Again" << endl;
    cin >> continueVar;
    playerOneHand = {};
    playerTwoHand = {};
    cardDeck = {};
}

    return 0;
}



//Function to create a deck of cards
void generateDeck(vector<playingCard>& deckToCreate) {
    string currentSuit;
    string currentFace;
    playingCard currentCard;
    //Assign each card a value and suit
    for(unsigned int i = 2; i < 15; ++i){
        //Determine Suit
        for(unsigned int suitVar = 0; suitVar < 4; suitVar++){

            //Assign Suit
            switch(suitVar) {
                case 0 :
                    currentSuit = "D";
                break;
            case 1 :
                    currentSuit = "H";
                break;
            case 2 :
                currentSuit = "C";
                break;
            case 3 :
                currentSuit = "S";
                break;
            default :
                currentSuit = "Invalid";
            }

            //Assign Face
            switch(i) {
            case 11 :
                currentFace = "J";
                break;
            case 12 :
                currentFace = "Q";
                break;
            case 13 :
                currentFace = "K";
                break;
            case 14 :
                currentFace = "A";
                break;
            default :
                currentFace = to_string(i);
            }

            currentCard.value = i;
            currentCard.face = currentFace;
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

//Sort cards in vector by value
void sortCards(vector<playingCard>& hand) {
    sort(hand.begin(), hand.end(), [](playingCard a, playingCard b){
        return a.value < b.value;
    });
}

//Display cards
void displayCards(vector<playingCard>& hand) {
    for(unsigned int i = 0; i < hand.size(); ++i) {
        cout << hand.at(i).face << hand.at(i).suit << " ";
    }
}


//Checking Card Hands
int returnBestHand(vector<playingCard>& sortedHand) {
    int winningHand = 9;
    bool flush = false;
    bool straight = false;

    if(isFlush(sortedHand)){
        flush = true;
    }
    if(isStraight(sortedHand)){
        straight = true;
    }
    //Checking for straight flush/ Royal Flush
    if(flush && straight) {
        //Checking for Roayl Flush (if highest card is Ace)
        if(sortedHand.at(4).value == 14) {
            winningHand = 0;
        } else {
            winningHand = 1;
        }
    }
    else if(isFourOfAKind(sortedHand)){
        winningHand = 2;
    }
    else if(isFullHouse(sortedHand)){
        winningHand = 3;
    }
    else if(flush) {
        winningHand = 4;
    }
    else if(straight) {
        winningHand = 5;
    }
    else if(isThreeOfAKind(sortedHand)){
        winningHand = 6;
    }
    else if(isTwoPair(sortedHand)){
        winningHand = 7;
    }
    else if(isPair(sortedHand)){
        winningHand = 8;
    }
    else {
        winningHand = 9;
    }
    return winningHand;

};


//Functions to check for individual points/hands

bool isFlush(vector<playingCard>& sortedHand) {
    //declare counter variables
    int diamonds = 0, hearts = 0, clubs = 0, spades = 0;
    bool isFlush = false;
    for(unsigned int i = 0; i < sortedHand.size(); i++){
        if(sortedHand.at(i).suit == "D"){
            diamonds++;
        }
        else if(sortedHand.at(i).suit == "H"){
            hearts++;
        }
        else if(sortedHand.at(i).suit == "C"){
           clubs++;
         }
        else {
            spades++;
        }

    }
    if(diamonds == 5 || hearts == 5 || clubs == 5 || spades == 5) {
        isFlush = true;
    }
    return isFlush;
}

bool isStraight(vector<playingCard>& sortedHand){
    bool isStraight = false;
    if((sortedHand.at(0).value + 1) == sortedHand.at(1).value &&
            (sortedHand.at(1).value + 1) == sortedHand.at(2).value &&
            (sortedHand.at(2).value + 1) == sortedHand.at(3).value &&
            (sortedHand.at(3).value + 1) == sortedHand.at(4).value) {
        isStraight = true;
    }
    return isStraight;
}

bool isFourOfAKind(vector<playingCard>& sortedHand){
    bool isFourOfAKind = false;

    if(sortedHand.at(0).value == sortedHand.at(1).value &&
            sortedHand.at(1).value == sortedHand.at(2).value &&
            sortedHand.at(2).value == sortedHand.at(3).value) {
        isFourOfAKind = true;
    }
    else if(sortedHand.at(1).value == sortedHand.at(2).value &&
            sortedHand.at(2).value == sortedHand.at(3).value &&
            sortedHand.at(3).value == sortedHand.at(4).value) {
        isFourOfAKind = true;
    }
    return isFourOfAKind;
};

bool isFullHouse(vector<playingCard>& sortedHand) {
    bool isFullHouse = false;
    if((sortedHand.at(0).value == sortedHand.at(1).value && sortedHand.at(1).value == sortedHand.at(2).value) &&
            (sortedHand.at(3).value == sortedHand.at(4).value)) {
        isFullHouse = true;
    }
    else if((sortedHand.at(0).value == sortedHand.at(1).value) &&
            (sortedHand.at(2).value == sortedHand.at(3).value) && sortedHand.at(3).value == sortedHand.at(4).value) {
        isFullHouse = true;
    }
    return isFullHouse;
};

bool isThreeOfAKind(vector<playingCard>& sortedHand) {
    bool isThreeOfAKind = false;
    if((sortedHand.at(0).value == sortedHand.at(1).value) && (sortedHand.at(1).value == sortedHand.at(2).value)) {
        isThreeOfAKind = true;
    }
    else if((sortedHand.at(1).value == sortedHand.at(2).value) && (sortedHand.at(3).value == sortedHand.at(2).value)) {
        isThreeOfAKind = true;
    }
    else if((sortedHand.at(2).value == sortedHand.at(3).value) && (sortedHand.at(3).value == sortedHand.at(4).value)) {
        isThreeOfAKind = true;
    }
    return isThreeOfAKind;
};

bool isTwoPair(vector<playingCard>& sortedHand) {
    bool isTwoPair = false;
    if((sortedHand.at(0).value == sortedHand.at(1).value) && sortedHand.at(2).value == sortedHand.at(3).value) {
        isTwoPair = true;
    }
    else if((sortedHand.at(1).value == sortedHand.at(2).value) && sortedHand.at(3).value == sortedHand.at(4).value) {
        isTwoPair = true;
    }
    return isTwoPair;
};

bool isPair(vector<playingCard>& sortedHand){
    bool isPair = false;
    if(sortedHand.at(0).value == sortedHand.at(1).value) {
        isPair = true;
    }
    else if(sortedHand.at(1).value == sortedHand.at(2).value) {
        isPair = true;
    }
    else if(sortedHand.at(2).value == sortedHand.at(3).value) {
        isPair = true;
    }
    else if(sortedHand.at(3).value == sortedHand.at(4).value) {
        isPair = true;
    }
    return isPair;
};

/*Testing
 * Hands deal correctly, without duplicating cards
 * On repeated simulations, points are evaluated and winner is chosen correctly
 * */

