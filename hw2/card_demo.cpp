#include "card.h"
#include "deck.h"
#include "player.h"
#include <iostream>

using namespace std;

void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

bool gameOver(const Player & player1, const Player & player2) {
  
  if((player1.getBookSize() + player2.getBookSize()) >= 26) {
    if(player1.getHandSize() > player2.getHandSize()) {
      cout << player1.getName() << " wins!";
    } else {
      cout << player2.getName() << " wins!";
    }
    exit(0);
  } else {
    return false;
  }
}

void clearBooks(Player & player) {
  
  Card bookCard1;
  Card bookCard2;
  int rank;
  
  while (player.checkHandForBook(bookCard1, bookCard2)) {
    
    player.removeCardFromHand(bookCard1);
    player.removeCardFromHand(bookCard2);
    player.bookCards(bookCard1, bookCard2);
    rank = bookCard1.getRank();
    cout << player.getName() << " books the " << bookCard1.rankString(rank) << endl;
    break;
    
  } // end loop (looking for books in hand)
} // end function block

void takeCard(Player & player, Deck & deck) {    
  if(deck.size() > 0) {
    
    Card newCardFromDeck = deck.dealCard();    
    cout << player.getName() << " draws " << newCardFromDeck << endl;    
    player.addCard(newCardFromDeck);
  
  } else {
    cout << "There are no cards left in the deck!" << endl;
  }
}

void queryOtherPlayer(Player & turnPlayer, Player & otherPlayer, Card questionCard) {
  
  bool fish = false;
  int rank = questionCard.getRank();
  
  while(!fish) {
    
    cout << turnPlayer.getName() << " ask, 'Do you have a " << questionCard.rankString(rank) << "?'" << endl;
    
    if(otherPlayer.cardInHand(questionCard)) {
      
      cout << otherPlayer.getName() << " says, 'Yes, I have a " << questionCard.rankString(rank) << ".'" << endl;
      
      // transfer card from otherPlayer to turnPlayer      
      turnPlayer.addCard(otherPlayer.removeCardFromHand(questionCard));
      
      // turnplayer will check for books
      clearBooks(turnPlayer);
      
      // after booking cards you always need to check if the game is over.
      if(gameOver(turnPlayer, otherPlayer))
        return;
      
    } else {
      
      fish = true;
      cout << otherPlayer.getName() << " says - Go Fish" << endl;  
      
    } // end conditional (other player cardinhand)
  } // end while loop
} // end function block

void takeTurn(Player & turnPlayer, Player & otherPlayer, Deck & deck) {    
  cout << endl;
  
  clearBooks(turnPlayer);
  if(gameOver(turnPlayer, otherPlayer))
     return;
  
  if(turnPlayer.getHandSize() > 0) {
    Card questionCard = turnPlayer.chooseCardFromHand();
    queryOtherPlayer(turnPlayer, otherPlayer, questionCard);
  }
      
  takeCard(turnPlayer, deck);
}

int main () {
  
  int numCards = 7;
  
  Player player1("Joe");
  Player player2("Jane");
  
  Deck deck;    
  deck.shuffle();

  dealHand(deck, player1, numCards);
  dealHand(deck, player2, numCards);  
  
  Card questionCard;
  Card newCardFromDeck;
  
  bool cardsLeftToBook = true;
  bool fish = false;  
  
  while (!gameOver(player1, player2)) {
    takeTurn(player1, player2, deck);
    takeTurn(player2, player1, deck);        
  }
}