#include "../include/deck.h"

Deck::Deck(int size) {
  for (int i = 0; i < size; i++) {
    Card* card_ptr = new Card();
    cards_.push_back(card_ptr);
  }
}

Deck::~Deck() {
  for (Card* card_ptr : cards_) {
    delete card_ptr;
  }
}

void Deck::DealCards(Player& player, int num_cards) {
  for (int i = 0; i < num_cards; i++) {
    Card* card_ptr = cards_.back();
    player.ReceiveCard(card_ptr);
    cards_.pop_back();
  }
}