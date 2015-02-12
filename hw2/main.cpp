#include "card.h"
#include "deck.h"
#include "player.h"
#include <iostream>

void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

int main () {
  int numCards = 7;
  
  Deck deck;    
  deck.shuffle();
  
  /*
  Card myCard;
  while(deck.dealCard(myCard)) {
    cout << deck.size() << " - " << myCard << endl;
  }  
  deck.shuffle();  
  while(deck.size() > 0) {
    cout << deck.size() << " - " << deck.dealCard() << endl;
  }
  */
  
  Player p1("Joe");
  Player p2("Jane");
  
  dealHand(deck, p1, numCards);
  dealHand(deck, p2, numCards);
    
  cout << p1.getName() <<" has : " << p1.showHand() << "- " << p1.getHandSize() << " cards."<< endl;
  cout << p2.getName() <<" has : " << p2.showHand() << "- " << p1.getHandSize() << " cards."<< endl;
  
  cout << p1.getName() <<" has : " << p1.showBooks() << "- " << p1.getBookSize() << " books."<< endl;
  cout << p2.getName() <<" has : " << p2.showBooks() << "- " << p1.getBookSize() << " books."<< endl;
}