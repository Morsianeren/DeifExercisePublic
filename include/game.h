#ifndef GAME_H
#define GAME_H

#include <vector>
#include "deck.h"
#include "player.h"

class Game {
public:
  Game(Deck* deck);
  ~Game();
  void AddPlayer(Player* player);
  void StartGame(int cards_to_deal);
  void AnnounceWinner();
private:
  Deck* deck_;
  std::vector<Player*> players_;
};

#endif // GAME_H