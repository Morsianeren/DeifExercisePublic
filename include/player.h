#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"

class Player {
public:
  Player(std::string name);
  ~Player();	
  void ReceiveCard(Card* card);
  int GetHandValue();
  std::vector<Card*> ShowHand();
  const std::string name;
private:
  std::vector<Card*> hand_;
};
#endif // PLAYER_H