#ifndef CARD_H
#define CARD_H

#include <cstdlib> // For rand()
#include <iostream>

class Card {
public:
  Card();
  Card(int suit, int card_number);
  int GetValue();
  static int GetRandomSuit();
  static int GetRandomCardNumber();
  friend std::ostream& operator<<(std::ostream& os, const Card& card);
  const int suit;
  const int card_number;
private:
  int value_;
};

#endif // CARD_H