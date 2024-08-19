#include <iostream>
#include "../include/card.h"

void main()
{
    // Test the card value
    for (int suit = 1; suit <= 4; suit++) {
        for (int number = 1; number <= 8; number++) {
            Card card(suit, number);
            int expected_value = suit * number;
            if (card.GetValue() != expected_value) {
                throw;
            }    
        }
    }
    std::cout << "Card value test passed!" << std::endl;

    // Test random number generation
    for (int i = 0; i < 100; i++) {
        int suit = Card::GetRandomSuit();
        if (suit < 1 || suit > 4) {
            throw;
        }
        int number = Card::GetRandomCardNumber();
        if (number < 1 || number > 8) {
            throw;
        }
    }
    std::cout << "Random number generation test passed!" << std::endl;
    std::cout << "All tests passed!" << std::endl;
}