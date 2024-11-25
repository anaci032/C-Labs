#ifndef CHAINBASE_H
#define CHAINBASE_H

#include <iostream>
#include "Card.h" // Include Card to use in the interface

class ChainBase {
public:
    virtual ~ChainBase() = default;

    // Determines if a card can be added to this chain
    virtual bool canAddCard(Card* card) const = 0;

    // Adds a card to the chain
    virtual ChainBase& operator+=(Card* card) = 0;

    // Sells the chain and returns the number of coins earned
    virtual int sell() const = 0;

    // Prints the chain's content to an output stream
    virtual void print(std::ostream& out) const = 0;
};

// Overload the stream insertion operator for printing chains
inline std::ostream& operator<<(std::ostream& out, const ChainBase& chain) {
    chain.print(out);
    return out;
}

#endif // CHAINBASE_H
