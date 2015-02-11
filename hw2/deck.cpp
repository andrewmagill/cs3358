#include "card.h"
#include "deck.h"

using namespace std;

Deck::Deck() {
  // construct deck
  for (int i = 0; i < SUIT_SIZE; i++) { 
    for (int j = 0; j < RANK_SIZE; j++) { 
      Card::Suit suit;
  
      switch(i) {
         case 0: suit = Card::spades; break;
         case 1: suit = Card::hearts; break;
         case 2: suit = Card::diamonds; break;
         case 3: suit = Card::clubs; break;
      };
  
      Card c(j,suit);
      
      //
      
      cout << c << endl;
    }
  }
}