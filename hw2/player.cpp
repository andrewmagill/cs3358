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
  // not imlpemented yet
  return false;
}

Card Player::chooseCardFromHand() const {
  // not imlpemented yet
  return Card();
}

bool Player::cardInHand(Card c) const {
  // not imlpemented yet
  return false;
}

Card Player::removeCardFromHand(Card c) {
  // not imlpemented yet
  return Card();
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

bool Player::sameRankInHand(Card c) const {
  // not imlpemented yet
  return false;
}