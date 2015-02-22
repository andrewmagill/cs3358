#include "card.h"
#include "deck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Deck::Deck() {
  topCardIndex = 0;
  int index = 0;
  
  for (int intSuit = 0; intSuit < SUIT_SIZE; intSuit++) { 
    for (int intRank = 0; intRank < RANK_SIZE; intRank++) { 
      Card::Suit suit = (Card::Suit)intSuit;
  
      index = intSuit*13+intRank;
      myCards[index] = Card(intRank+1, suit);
    }
  }
}

void Deck::shuffle() {
  topCardIndex = 0;
  int randCardIndex;  
  Card tempCard;
  
  srand(time(0));
  
  for (int i = 0; i < SIZE; i++) {    
    randCardIndex = rand() % 52;
    
    if(randCardIndex != i) {
      tempCard = myCards[i];
      myCards[i] = myCards[randCardIndex];
      myCards[randCardIndex] = tempCard;
    }    
  }  
}

Card Deck::dealCard() {
  // the last card will have index equal to SIZE - 1
  if(topCardIndex == SIZE)
    return Card();
  
  Card topCard = myCards[topCardIndex];  
  topCardIndex++;
  
  return topCard;
}

bool Deck::dealCard(Card & card) {
  // the last card will have index equal to SIZE - 1
  if(topCardIndex == SIZE)
    return false;
  
  card = myCards[topCardIndex];  
  topCardIndex++;
  
  return true;
}

int Deck::size() const {
  return SIZE - topCardIndex;
}