#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>

Deck::Deck() noexcept {
    // Initialize the deck with the appropriate number of each type of card
    for (int i = 0; i < 20; ++i) { cards.emplace_back(std::make_unique<Blue>()); }
    for (int i = 0; i < 18; ++i) { cards.emplace_back(std::make_unique<Chili>()); }
    for (int i = 0; i < 16; ++i) { cards.emplace_back(std::make_unique<Stink>()); }
    for (int i = 0; i < 14; ++i) { cards.emplace_back(std::make_unique<Green>()); }
    for (int i = 0; i < 12; ++i) { cards.emplace_back(std::make_unique<Soy>()); }
    for (int i = 0; i < 10; ++i) { cards.emplace_back(std::make_unique<Black>()); }
    for (int i = 0; i < 8; ++i) { cards.emplace_back(std::make_unique<Red>()); }
    for (int i = 0; i < 6; ++i) { cards.emplace_back(std::make_unique<Garden>()); }

    // Shuffle the deck after initializing
    shuffleDeck();
}

Card* Deck::draw() {
    if (!cards.empty()) {
        // Get a pointer to the last card in the deck
        Card* card = cards.back().release();
        // Remove the card from the deck
        cards.pop_back();
        return card;
    }
    return nullptr; // Return nullptr if deck is empty
}

void Deck::shuffleDeck() {
    // Use a random engine seeded with the current time
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

size_t Deck::size() const {
    return cards.size();
}

bool Deck::empty() const {
    return cards.empty();
}

void Deck::print(std::ostream& out) const {
    if (cards.empty()) {
        out << "No cards in the deck.";
    } else {
        for (const auto& card : cards) {
            card->print(out);
            out << " ";
        }
    }
}

void Deck::addCard(std::unique_ptr<Card> card) {
    cards.push_back(std::move(card));
}
