#include "card.h"
#include <iostream>

using namespace std;

Card::Card() {}

Card::Card(int rank, Suit s)
: myRank(rank), mySuit(s) {}

string Card::toString() const {  
  return rankString(myRank) + suitString(mySuit);
}

bool Card::sameSuitAs(const Card& c) const {
  return c.getSuit() == mySuit;
}

int Card::getRank() const { 
  return myRank;
}

Card::Suit Card::getSuit() const { 
  return mySuit;
}

/*
Card::Suit Card::intToSuit(int n) const {
  Card::Suit suit;
  
  switch(n) {
     case 0: suit = Card::spades; break;
     case 1: suit = Card::hearts; break;
     case 2: suit = Card::diamonds; break;
     case 3: suit = Card::clubs; break;
  };
  
  return suit;   
}
*/

string Card::suitString(Suit s) const {
  string strSuit = "";

  switch(s) {
     case spades: strSuit = "s"; break;
     case hearts: strSuit = "h"; break;
     case diamonds: strSuit = "d"; break;
     case clubs: strSuit = "c"; break;
  };
  
  return strSuit;
}
    
string Card::rankString(int r) const {
  string strRank = "";

  switch(r) {
     case 13: strRank = "K"; break;
     case 12: strRank = "Q"; break;
     case 11: strRank = "J"; break;
     case 1: strRank = "A"; break;
     default: strRank = to_string(myRank); break;
  };
  
  return strRank;
}

bool Card::operator == (const Card& rhs) const {
  return strcmp(toString().c_str(), rhs.toString().c_str()) == 0;
}

bool Card::operator != (const Card& rhs) const {
  return strcmp(toString().c_str(), rhs.toString().c_str()) != 0;
}

ostream& operator << (ostream& out, const Card& c) {
 return out << c.toString();
}
