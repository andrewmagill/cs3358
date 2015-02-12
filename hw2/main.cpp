#include "Card.h"
#include "Deck.h"
#include <iostream>

using namespace std;

int main() {
  Card c1(9, Card::spades);  
  Card c2(1, Card::clubs);  
  Card c3(13, Card::hearts);  
  Card c4(1, Card::diamonds);  
  Card c5(10, Card::spades);
  
  cout << "c1 rank ordinal: " << c1.getRank() << ", c1 rank name: " << c1.rankString(c1.getRank()) << endl;
  cout << "c2 rank ordinal: " << c2.getRank() << ", c2 rank name: " << c1.rankString(c2.getRank()) << endl;
  cout << "c3 rank ordinal: " << c3.getRank() << ", c3 rank name: " << c1.rankString(c3.getRank()) << endl;
  cout << "c4 rank ordinal: " << c4.getRank() << ", c4 rank name: " << c1.rankString(c4.getRank()) << endl;
  cout << "c5 rank ordinal: " << c5.getRank() << ", c5 rank name: " << c1.rankString(c5.getRank()) << endl;
  cout << endl;
  cout << "c1 suit ordinal: " << c1.getSuit() << ", c1 suit name: " << c1.suitString(c1.getSuit()) << endl;
  cout << "c2 suit ordinal: " << c2.getSuit() << ", c2 suit name: " << c1.suitString(c2.getSuit()) << endl;
  cout << "c3 suit ordinal: " << c3.getSuit() << ", c3 suit name: " << c1.suitString(c3.getSuit()) << endl;
  cout << "c4 suit ordinal: " << c4.getSuit() << ", c4 suit name: " << c1.suitString(c4.getSuit()) << endl;
  cout << "c5 suit ordinal: " << c5.getSuit() << ", c5 suit name: " << c1.suitString(c5.getSuit()) << endl;
  cout << endl;
  cout << "c1 same suit as c2: " << c1.sameSuitAs(c2) << endl;
  cout << "c1 same suit as c5: " << c1.sameSuitAs(c5) << endl;
  cout << endl;
  cout << "c2 same card as c4: " << (c2 == c4) << endl;
  cout << c1 << endl;
  cout << endl;
  Card c6(10, Card::spades);
  cout << endl;
  cout << "c5 same card as c6: " << (c5 == c6) << endl;
  cout << endl;
  cout << "c2 not same card as c4: " << (c2 != c4) << endl;
  cout << "c5 not same card as c6: " << (c5 != c6) << endl;
  
  Card::Suit s1 = Card::spades;
  
  Deck d1;
  
  return 0;
}