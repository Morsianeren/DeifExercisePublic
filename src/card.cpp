#include "../include/card.h"

std::unordered_map<int, std::string> Card::number_to_suit = {
    {1, "Red"}, {2, "Blue"}, {3, "Green"}, {4, "Yellow"}
};

Card::Card() : suit(GetRandomSuit()), card_number(GetRandomCardNumber()){
  value_ = suit * card_number;
}

Card::Card(int suit, int card_number) : suit(suit), card_number(card_number) {
  value_ = suit * card_number;
}

int Card::GetValue() {
  return value_;
}

int Card::GetRandomSuit() {
  // Get a random number between 1 and 4
  return rand() % 4 + 1;
}
int Card::GetRandomCardNumber() {
  // Get a random number between 1 and 8
  return rand() % 8 + 1;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    std::string suit_str = Card::number_to_suit[card.suit];
    os << suit_str << " " << card.card_number;
    return os;
}