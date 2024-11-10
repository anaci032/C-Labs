#ifndef HAND_H
#define HAND_H

#include <deque>
#include <memory>
#include <iostream>
#include "Card.h"

class Hand {
    std::deque<std::unique_ptr<Card>> cards;

public:
    Hand() = default;
    void addCard(std::unique_ptr<Card> card); // Adds a card to the back of the hand
    Card* play(); // Plays (removes) the top card from the hand
    Card* top() const; // Returns (without removing) the top card of the hand
    Card* operator[](int index); // Returns (and removes) the card at a given index
    void print(std::ostream& out) const; // Prints all cards in the hand in order

    friend std::ostream& operator<<(std::ostream& out, const Hand& hand) {
        hand.print(out);
        return out;
    }
};

#endif // HAND_H
