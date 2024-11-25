#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <memory>
#include "Card.h"
#include "ChainBase.h"

// Template class for managing chains of specific card types
template <typename T>
class Chain : public ChainBase {
    std::vector<std::unique_ptr<T>> cards;

public:
    Chain() = default;

    // Checks if a card can be added to this chain
    bool canAddCard(Card* card) const override {
        // Check if the card is of the correct type
        T* typedCard = dynamic_cast<T*>(card);
        return typedCard != nullptr;
    }

    // Adds a card to the chain
    ChainBase& operator+=(Card* card) override {
        // Ensure the card is of the correct type
        T* typedCard = dynamic_cast<T*>(card);
        if (typedCard) {
            cards.push_back(std::unique_ptr<T>(typedCard));  // Add card to the chain
        } else {
            throw std::runtime_error("Cannot add card of a different type to the chain.");
        }
        return *this;
    }

    // Sells the chain and returns the number of coins earned
    int sell() const override {
        if (cards.empty()) return 0;  // No cards in the chain

        int numCards = cards.size();
        int coins = 0;

        // Determine the number of coins based on the chain's card count
        for (int i = 4; i >= 1; --i) {
            int cardsNeeded = cards.front()->getCardsPerCoin(i);  // Get the number of cards needed for each coin value
            if (numCards >= cardsNeeded) {
                coins = i;
                break;
            }
        }

        return coins;
    }

    // Prints the chain to an output stream
    void print(std::ostream& out) const override {
        if (cards.empty()) {
            out << "Empty Chain";
        } else {
            out << cards.front()->getName() << " Chain: ";
            for (const auto& card : cards) {
                card->print(out);  // Print each card in the chain
                out << " ";
            }
        }
    }
};

#endif // CHAIN_H
