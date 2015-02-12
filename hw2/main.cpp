#include "card.h"
#include "deck.h"
#include "player.h"
#include <iostream>

int main () {
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
}