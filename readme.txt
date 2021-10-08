Changes:
- Added proper naming conventions for faces
- Improved hand recognition


Tests Passed:

//Two pairs
dealerDeck.at(0).face = 4; dealerDeck.at(1).face = 5; dealerDeck.at(2).face = 7; dealerDeck.at(3).face = 9; dealerDeck.at(4).face = 4;
dealerDeck.at(0).suit = 'S';dealerDeck.at(1).suit = 'S'; dealerDeck.at(2).suit = 'S'; dealerDeck.at(3).suit = 'S'; dealerDeck.at(4).suit = 'S';

playerOneHand.at(0).face = 10; playerOneHand.at(1).face = 11;
playerOneHand.at(0).suit = 'D'; playerOneHand.at(1).suit = 'D';

playerTwoHand.at(0).face = 1; playerTwoHand.at(1).face = 1;
playerTwoHand.at(0).suit = 'S'; playerTwoHand.at(1).suit = 'S';


//Pairs
dealerDeck.at(0).face = 2; dealerDeck.at(1).face = 5; dealerDeck.at(2).face = 7; dealerDeck.at(3).face = 9; dealerDeck.at(4).face = 4;
dealerDeck.at(0).suit = 'S';dealerDeck.at(1).suit = 'D'; dealerDeck.at(2).suit = 'D'; dealerDeck.at(3).suit = 'S'; dealerDeck.at(4).suit = 'S';

playerOneHand.at(0).face = 10; playerOneHand.at(1).face = 11;
playerOneHand.at(0).suit = 'D'; playerOneHand.at(1).suit = 'D';

playerTwoHand.at(0).face = 1; playerTwoHand.at(1).face = 2;
playerTwoHand.at(0).suit = 'S'; playerTwoHand.at(1).suit = 'S';


//Flush
dealerDeck.at(0).face = 2; dealerDeck.at(1).face = 5; dealerDeck.at(2).face = 7; dealerDeck.at(3).face = 9; dealerDeck.at(4).face = 4;
dealerDeck.at(0).suit = 'D';dealerDeck.at(1).suit = 'S'; dealerDeck.at(2).suit = 'S'; dealerDeck.at(3).suit = 'S'; dealerDeck.at(4).suit = 'S';

playerOneHand.at(0).face = 10; playerOneHand.at(1).face = 11;
playerOneHand.at(0).suit = 'D'; playerOneHand.at(1).suit = 'D';

playerTwoHand.at(0).face = 1; playerTwoHand.at(1).face = 2;
playerTwoHand.at(0).suit = 'S'; playerTwoHand.at(1).suit = 'S';


//Four of a Kind
dealerDeck.at(0).face = 2; dealerDeck.at(1).face = 2; dealerDeck.at(2).face = 2; dealerDeck.at(3).face = 9; dealerDeck.at(4).face = 5;
dealerDeck.at(0).suit = 'D';dealerDeck.at(1).suit = 'S'; dealerDeck.at(2).suit = 'S'; dealerDeck.at(3).suit = 'S'; dealerDeck.at(4).suit = 'S';

playerOneHand.at(0).face = 10; playerOneHand.at(1).face = 11;
playerOneHand.at(0).suit = 'D'; playerOneHand.at(1).suit = 'D';

playerTwoHand.at(0).face = 2; playerTwoHand.at(1).face = 2;
playerTwoHand.at(0).suit = 'S'; playerTwoHand.at(1).suit = 'D';


//Three of a Kind
dealerDeck.at(0).face = 3; dealerDeck.at(1).face = 1; dealerDeck.at(2).face = 2; dealerDeck.at(3).face = 9; dealerDeck.at(4).face = 5;
dealerDeck.at(0).suit = 'D';dealerDeck.at(1).suit = 'H'; dealerDeck.at(2).suit = 'H'; dealerDeck.at(3).suit = 'S'; dealerDeck.at(4).suit = 'S';

playerOneHand.at(0).face = 10; playerOneHand.at(1).face = 11;
playerOneHand.at(0).suit = 'D'; playerOneHand.at(1).suit = 'D';

playerTwoHand.at(0).face = 2; playerTwoHand.at(1).face = 2;
playerTwoHand.at(0).suit = 'S'; playerTwoHand.at(1).suit = 'D';


//Full House
dealerDeck.at(0).face = 7; dealerDeck.at(1).face = 1; dealerDeck.at(2).face = 11; dealerDeck.at(3).face = 11; dealerDeck.at(4).face = 5;
dealerDeck.at(0).suit = 'D';dealerDeck.at(1).suit = 'H'; dealerDeck.at(2).suit = 'H'; dealerDeck.at(3).suit = 'S'; dealerDeck.at(4).suit = 'S';

playerOneHand.at(0).face = 10; playerOneHand.at(1).face = 11;
playerOneHand.at(0).suit = 'D'; playerOneHand.at(1).suit = 'D';

playerTwoHand.at(0).face = 7; playerTwoHand.at(1).face = 7;
playerTwoHand.at(0).suit = 'S'; playerTwoHand.at(1).suit = 'D';