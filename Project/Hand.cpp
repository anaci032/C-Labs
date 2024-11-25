#include "Hand.h"
#include <iostream>

// Adds a card to the back of the hand
void Hand::addCard(Card* card) {
    cards.push_back(std::unique_ptr<Card>(card));  // Wrap the card in a unique_ptr and add to the deque
}

// Plays (removes) the top card from the hand
std::unique_ptr<Card> Hand::play() {
    if (!cards.empty()) {
        auto card = std::move(cards.front());  // Move the top card out of the deque
        cards.pop_front();  // Remove the card from the front of the deque
        return card;  // Return the card
    }
    return nullptr;  // If hand is empty, return nullptr
}

// Returns (without removing) the top card of the hand
Card* Hand::top() const {
    return cards.empty() ? nullptr : cards.front().get();  // Return the top card or nullptr if empty
}

// Returns (and removes) the card at a given index
std::unique_ptr<Card> Hand::operator[](size_t index) {
    if (index < cards.size()) {
        auto it = cards.begin() + index;  // Get iterator to the specified index
        auto card = std::move(*it);  // Move the card out of the deque
        cards.erase(it);  // Erase the card from the deque
        return card;  // Return the card
    }
    return nullptr;  // Return nullptr if the index is out of bounds
}

// Prints all cards in the hand in order
void Hand::print(std::ostream& out) const {
    if (cards.empty()) {
        out << "No cards in hand.";  // If hand is empty, print a message
    } else {
        for (const auto& card : cards) {
            card->print(out);  // Print each card in the hand
            out << " ";
        }
    }
}
