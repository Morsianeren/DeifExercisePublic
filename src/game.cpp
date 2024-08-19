#include "../include/game.h"

Game::Game(Deck* deck) : deck_(deck) {}

Game::~Game() {

}

void Game::AddPlayer(Player* player) {
  players_.push_back(player);
}

void Game::StartGame(int cards_to_deal) {
  for (Player* player : players_) {
    deck_->DealCards(*player, cards_to_deal);
  }
}

void Game::AnnounceWinner() {
  int max_score = 0;
  Player* winner = nullptr;
  for (Player* player : players_) {
    int player_score = player->GetHandValue();
    if (player_score > max_score) {
      max_score = player_score;
      winner = player;
    }
  }
  if (winner == nullptr) {
    std::cout << "No winner" << std::endl;
    return;
  }
  std::cout << "The winner is: " << winner->name << std::endl;
}