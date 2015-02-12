#include "card.h"
#include "deck.h"
#include <iostream>

int main () {
  Deck deck;  
  
  deck.shuffle();
  
  Card myCard;
  while(deck.dealCard(myCard)) {
    cout << deck.size() << " - " << myCard << endl;
  }
  
  deck.shuffle();
  
  while(deck.size() > 0) {
    cout << deck.size() << " - " << deck.dealCard() << endl;
  }
}