#ifndef DECK_H
#define DECK_H

#include <vector>
#include <memory>
#include <iostream>
#include "Card.h"

class Deck {
    std::vector<std::unique_ptr<Card>> cards;

public:
    Deck() noexcept; // Initialize and shuffle deck

    Card* draw(); // Draw a card from the top
    void shuffleDeck(); // Shuffle the deck
    size_t size() const; // Get the number of cards remaining
    bool empty() const; // Check if the deck is empty
    void print(std::ostream& out) const; // Print the deck
    void addCard(std::unique_ptr<Card> card); // Add a card back to the deck
};

#endif // DECK_H
