#include <iostream>
#include <string>
#include <vector>
#include "../include/deck.h"
#include "../include/player.h"
#include "../include/game.h"

int main() {

  // Initialize players
  std::vector<Player*> players;
  std::string player_name;

  std::cout << "Enter player names. Enter done to start the game." << std::endl;
  do {
    std::cout << "Enter player name: ";
    std::cin >> player_name;
    if (player_name != "done") {
      Player* player = new Player(player_name);
      players.push_back(player);
    }
  } while (player_name != "done");



  // Initialize deck
  std::cout << "Please enter how many cards each player should get: ";
  int number_of_cards;
  std::cin >> number_of_cards;
  
  // TODO: Add deck as a member of the Game class
  Deck deck(players.size() * number_of_cards);

  // Initialize game
  Game game(&deck);

  // Add players to game
  for (Player* player : players) {
    game.AddPlayer(player);
  }

  // Start game
  game.StartGame(number_of_cards);

  // Show hands
  for (Player* player : players) {
    int points = 0; 
    std::cout << player->name << " has: ";
    for (Card* card_ptr : player->ShowHand()) {
      std::cout << *card_ptr << " ";
      points += card_ptr->GetValue();
    }
    std::cout << " for a total of " << points << " points.\n";
  }

  // Announce winner
  game.AnnounceWinner();

  // Clean up
  for (Player* player : players) {
    delete player;
  }

  return 0;

}