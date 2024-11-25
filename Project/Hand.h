#ifndef HAND_H
#define HAND_H

#include <deque>
#include <memory>
#include <iostream>
#include "Card.h"

class Hand {
private:
    std::deque<std::unique_ptr<Card>> cards;  // Using deque for efficient removal of cards from the front

public:
    Hand() = default;

    void addCard(Card* card);  // Adds a card to the back of the hand
    std::unique_ptr<Card> play();  // Plays (removes) the top card from the hand
    Card* top() const;  // Returns (without removing) the top card of the hand
    std::unique_ptr<Card> operator[](size_t index);  // Returns (and removes) the card at a given index
    void print(std::ostream& out) const;  // Prints all cards in the hand in order
    bool isEmpty() const { return cards.empty(); }

    // Overloading stream insertion operator to print hand
    friend std::ostream& operator<<(std::ostream& out, const Hand& hand) {
        hand.print(out);
        return out;
    }
};

#endif // HAND_H
