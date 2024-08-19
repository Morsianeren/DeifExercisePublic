#ifndef CARD_H
#define CARD_H

#include <cstdlib> // For rand()
#include <iostream>
#include <unordered_map>

class Card {
public:
  Card();
  Card(int suit, int card_number);
  int GetValue();
  static int GetRandomSuit();
  static int GetRandomCardNumber();
  friend std::ostream& operator<<(std::ostream& os, const Card& card);
  static std::unordered_map<int, std::string> number_to_suit;
  const int suit;
  const int card_number;
private:
  int value_;
};

#endif // CARD_H