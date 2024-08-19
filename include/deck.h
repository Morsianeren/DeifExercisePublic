#ifndef DECK_H
#define DECK_H

#include <vector>
#include "player.h"
#include "card.h"

class Deck {
public:
  Deck(int size);
  ~Deck();
  void DealCards(Player& player, int num_cards);

private:
  std::vector<Card*> cards_;
};
#endif // DECK_H