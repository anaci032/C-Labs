// Chain.h
#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <memory>
#include "Card.h"
#include "ChainBase.h"

template <typename T>
class Chain : public ChainBase {
    std::vector<std::unique_ptr<T>> cards;

public:
    Chain() = default;

    // Adds a card to the chain
    Chain& operator+=(Card* card) {
        T* typedCard = dynamic_cast<T*>(card);
        if (typedCard) {
            cards.push_back(std::unique_ptr<T>(typedCard));
        } else {
            throw std::runtime_error("Cannot add card of a different type to the chain");
        }
        return *this;
    }

    // Sells the chain, returning the number of coins earned
    int sell() const override {
        if (cards.empty()) return 0;
        int numCards = cards.size();
        int coins = 0;
        for (int i = 4; i >= 1; --i) {
            int cardsNeeded = cards.front()->getCardsPerCoin(i);
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
                card->print(out);
                out << " ";
            }
        }
    }
};

#endif // CHAIN_H
