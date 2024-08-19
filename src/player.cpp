#include "../include/player.h"

Player::Player(std::string name) : name(name) {}

Player::~Player() {
  for (Card* card_ptr : hand_) {
    delete card_ptr;
  }
}

void Player::ReceiveCard(Card* card) {
  hand_.push_back(card);
}

int Player::GetHandValue() {
  int hand_value = 0;
  for (Card* card_ptr : hand_) {
    hand_value += card_ptr->GetValue();
  }
  return hand_value;
}

std::vector<Card*> Player::ShowHand() {
  // Return a copy of the hand
  return hand_;
}