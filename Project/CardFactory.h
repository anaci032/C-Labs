#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <memory>
#include "Deck.h"
#include "Card.h"

class CardFactory {
private:
    static std::unique_ptr<CardFactory> instance;

    // Private constructor for singleton pattern
    CardFactory() = default;

public:
    // Delete copy constructor and assignment operator to prevent copies
    CardFactory(const CardFactory&) = delete;
    CardFactory& operator=(const CardFactory&) = delete;

    // Static method to access the single instance of CardFactory
    static CardFactory* getFactory();

    // Method to create and return a shuffled deck of cards
    Deck getDeck() const;
};

#endif // CARDFACTORY_H
