#include "player.h"
#include "card.h"
#include <iostream>

using namespace std;
/*
Player::Player() {}

Player::Player(string name) {
   myName = name;
}

string Player::getName() const {
   return myName;
}
*/
void Player::addCard(Card c) {
  myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
  // not imlpemented yet
}

bool Player::checkHandForBook(Card &c1, Card &c2) {
  // not imlpemented yet
  return false;
}

bool Player::rankInHand(Card c) const {
  
  for(int i = 0; i < myHand.size(); i++)
    if(myHand[i].getRank() == c.getRank())
      return true;
  
  return false;
}

Card Player::chooseCardFromHand() const {
  // this is where the strategy comes in
  // would probably be a good idea to avoid
  // chosing ranks that you have already booked
  // but for now we'll just chose the first
  // card in hand (if you're asking this q you have cards)
  // i think, maybe i should look at the rules
  if(myHand.size() > 0)
    return myHand[0];
  return Card();
}

bool Player::cardInHand(Card c) const {
  // not imlpemented yet
  return false;
}

Card Player::removeCardFromHand(Card c) {
  // so right now this is removing any card with the same rank
  Card tempCard;
  
  for(int i = 0; i < myHand.size(); i++)
    if(myHand[i].getRank() == c.getRank()) {
      tempCard = myHand[i];
      myHand.erase(myHand.begin()+i);
    }
    
  return tempCard;
}

string Player::showHand() const {
  string strHand = "";
  
  for(int i = 0; i < myHand.size(); i++)
    strHand += myHand[i].toString() + " ";

  return strHand;
}

string Player::showBooks() const {
  string strBooks = "";
  
  for(int i = 0; i < myBook.size(); i++)
    strBooks += myBook[i].toString() + " ";

  return strBooks;
}

int Player::getHandSize() const {
  return myHand.size();
}

int Player::getBookSize() const {
  return myBook.size();
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
  // not imlpemented yet
  return false;
}