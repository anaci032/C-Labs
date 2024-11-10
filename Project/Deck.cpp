#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <random>
#include <ctime>

Deck::Deck() {
    // Initialize the deck with the appropriate number of each type of card
    for (int i = 0; i < 20; ++i) { this->emplace_back(std::make_unique<Blue>()); }
    for (int i = 0; i < 18; ++i) { this->emplace_back(std::make_unique<Chili>()); }
    for (int i = 0; i < 16; ++i) { this->emplace_back(std::make_unique<Stink>()); }
    for (int i = 0; i < 14; ++i) { this->emplace_back(std::make_unique<Green>()); }
    for (int i = 0; i < 12; ++i) { this->emplace_back(std::make_unique<Soy>()); }
    for (int i = 0; i < 10; ++i) { this->emplace_back(std::make_unique<Black>()); }
    for (int i = 0; i < 8; ++i) { this->emplace_back(std::make_unique<Red>()); }
    for (int i = 0; i < 6; ++i) { this->emplace_back(std::make_unique<Garden>()); }

    // Shuffle the deck after initializing
    shuffleDeck();
}

Card* Deck::draw() {
    if (!this->empty()) {
        // Get a pointer to the last card in the deck
        Card* card = this->back().release();
        // Remove the card from the deck
        this->pop_back();
        return card;
    }
    return nullptr; // Return nullptr if deck is empty
}

void Deck::shuffleDeck() {
    // Use a random engine seeded with the current time
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->begin(), this->end(), g);
}
