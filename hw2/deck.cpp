#include "card.h"
#include "deck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Deck::Deck() {
  int index = 0;
  
  // construct deck
  for (int i = 0; i < SUIT_SIZE; i++) { 
    for (int j = 1; j < RANK_SIZE; j++) { 
      Card::Suit suit;
  
      switch(i) {
         case 0: suit = Card::spades; break;
         case 1: suit = Card::hearts; break;
         case 2: suit = Card::diamonds; break;
         case 3: suit = Card::clubs; break;
      };
  
      index = i*10+j-1;
      myCards[index] = Card(j+1, suit);
    }
  }
  
  // not sure why, but it works better if i do this here
  // as opposed to in the random number function
  srand(time(0));
}

void Deck::shuffle() {  
  int index = 0;
  int randCardIndex;
  
  //Card tempCard;
  
  for (int i = 0; i < SUIT_SIZE; i++) { 
    for (int j = 1; j <= RANK_SIZE; j++) {       
      index = index = i*10+j-1;
      randCardIndex = rand() % 52;
      
      if(randCardIndex != index) {
        //tempCard = myCards[randCardIndex];
        //myCards[i+j] = tempCard;
        //swap(myCards[i+j], myCards[randCardIndex]);
        //cout << myCards[50] << endl;
      }      
    }
  }
}

void Deck::printDeck() {  
  int index = 0;
  
  for (int i = 0; i < SUIT_SIZE; i++) { 
    for (int j = 1; j <= RANK_SIZE; j++) { 
      index = i*10+j-1;
      cout << (index) << ": " << myCards[index] << endl;
    }
  }
}