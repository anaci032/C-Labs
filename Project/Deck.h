#ifndef DECK_H
#define DECK_H

#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include "Card.h"

class Deck : public std::vector<std::unique_ptr<Card>> {
public:
    Deck(); // Initialize and shuffle deck
    Card* draw();
    void shuffleDeck(); // Shuffle the deck
};

#endif // DECK_H
