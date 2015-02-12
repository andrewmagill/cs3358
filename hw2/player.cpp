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
  // not imlpemented yet
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
  // not imlpemented yet
  return "";
}

string Player::showBooks() const {
  // not imlpemented yet
  return "";
}

int Player::getHandSize() const {
  // not imlpemented yet
  return -1;
}

int Player::getBookSize() const {
  // not imlpemented yet
  return -1;
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
  // not imlpemented yet
  return false;
}

bool Player::sameRankInHand(Card c) const {
  // not imlpemented yet
  return false;
}