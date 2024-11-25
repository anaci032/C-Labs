#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include <vector>
#include <memory>
#include <iostream>
#include "Card.h"

class DiscardPile {
    std::vector<std::unique_ptr<Card>> cards;

public:
    // Adds a card to the discard pile
    void addCard(Card* card);

    // Removes and returns the top card
    Card* pickUp();

    // Prints all cards in the discard pile
    void print(std::ostream& out) const;

    // Overloads the stream operator for printing
    friend std::ostream& operator<<(std::ostream& out, const DiscardPile& dp) {
        dp.print(out);
        return out;
    }
};

#endif // DISCARDPILE_H
