#include <iostream>
#include <string>
#include "../include/deck.h"
#include "../include/player.h"


int main() {
  // Create players
  Player player1("Alice");
  Player player2("Bob");
  Player player3("Charlie");

  // Create deck
  Deck deck(52);

  // Deal cards
  deck.DealCards(player1, 5);
  deck.DealCards(player2, 5);
  deck.DealCards(player3, 5);

  // Show hands
  std::cout << player1.name << " has: ";
  for (Card* card_ptr : player1.ShowHand()) {
    std::cout << *card_ptr << " ";
  }

  std::cout << "\n" << player2.name << " has: ";
  for (Card* card_ptr : player2.ShowHand()) {
    std::cout << card_ptr->suit << card_ptr->card_number << " ";
  }

  std::cout << "\n" << player3.name << " has: ";
  for (Card* card_ptr : player3.ShowHand()) {
    std::cout << card_ptr->suit << card_ptr->card_number << " ";
  }

  return 0;
}