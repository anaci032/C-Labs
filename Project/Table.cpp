#include "Table.h"
#include "CardFactory.h"
#include <iostream>

// Constructor to initialize players and deck
Table::Table(const std::string& player1Name, const std::string& player2Name)
    : player1(std::make_unique<Player>(player1Name)), player2(std::make_unique<Player>(player2Name)) {
    // Deck is already initialized by default
}

// Constructor to load the game from an input stream
Table::Table(std::istream& in, const CardFactory* cardFactory) {
    // Implement deserialization logic if needed (optional feature for loading game state)
}

// Check if the game is won
bool Table::win(std::string& winnerName) const {
    if (deck.empty()) {
        if (player1->getNumCoins() > player2->getNumCoins()) {
            winnerName = player1->getName();
        } else if (player2->getNumCoins() > player1->getNumCoins()) {
            winnerName = player2->getName();
        } else {
            winnerName = "Draw";
        }
        return true;
    }
    return false;
}

// Print the table state
void Table::print(std::ostream& out) const {
    out << "Player 1: " << *player1 << "\n";
    out << "Player 2: " << *player2 << "\n";
    out << "Deck has " << deck.size() << " cards remaining\n";
    out << "Discard Pile: ";
    discardPile.print(out);
    out << "\nTrade Area: " << tradeArea << "\n";
}

// Save the game state to an output stream
void Table::saveGame(std::ostream& out) const {
    out << *player1 << "\n";
    out << *player2 << "\n";
    // Additional code to save the deck, discard pile, and trade area if needed
}

// Accessor for player 1
Player* Table::getPlayer1() const {
    return player1.get();
}

// Accessor for player 2
Player* Table::getPlayer2() const {
    return player2.get();
}

// Accessor for the deck
Deck& Table::getDeck() {
    return deck;
}

// Accessor for the discard pile
Hand& Table::getDiscardPile() {
    return discardPile;
}

// Accessor for the trade area
TradeArea& Table::getTradeArea() {
    return tradeArea;
}
