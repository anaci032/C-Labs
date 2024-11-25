#include "CardFactory.h"
#include <algorithm>
#include <random>

// Define the static instance variable
std::unique_ptr<CardFactory> CardFactory::instance = nullptr;

// Method to access the singleton instance of CardFactory
CardFactory* CardFactory::getFactory() {
    if (!instance) {
        instance = std::unique_ptr<CardFactory>(new CardFactory());
    }
    return instance.get();
}

// Method to create and return a shuffled deck of cards
Deck CardFactory::getDeck() const {
    Deck deck;

    // Add the required number of each card type using addCard
    for (int i = 0; i < 20; ++i) { deck.addCard(std::make_unique<Blue>()); }
    for (int i = 0; i < 18; ++i) { deck.addCard(std::make_unique<Chili>()); }
    for (int i = 0; i < 16; ++i) { deck.addCard(std::make_unique<Stink>()); }
    for (int i = 0; i < 14; ++i) { deck.addCard(std::make_unique<Green>()); }
    for (int i = 0; i < 12; ++i) { deck.addCard(std::make_unique<Soy>()); }
    for (int i = 0; i < 10; ++i) { deck.addCard(std::make_unique<Black>()); }
    for (int i = 0; i < 8; ++i) { deck.addCard(std::make_unique<Red>()); }
    for (int i = 0; i < 6; ++i) { deck.addCard(std::make_unique<Garden>()); }


    // Shuffle the deck
    std::random_device rd;
    std::mt19937 g(rd());
    deck.shuffleDeck();

    return deck;
}
