#include "card.h"
#include "deck.h"
#include <iostream>

int main () {
  Deck deck;
  //deck.printDeck();
  deck.shuffle();
  deck.printDeck();
}