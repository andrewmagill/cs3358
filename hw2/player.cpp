#include "card.h"
#include <iostream>

using namespace std;

Player::Player() {}

Player::Player(string name) {
   myName = name;
}

string Player::getName() const {
   return myName;
}

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
}

string Player::showBooks() const {
  // not imlpemented yet
}

int Player::getHandSize() const {
  // not imlpemented yet
}

int getBookSize() const {
  // not imlpemented yet
}

bool checkHandForPair(Card &c1, Card &c2) {
  // not imlpemented yet
}

bool sameRankInHand(Card c) const {
  // not imlpemented yet
}