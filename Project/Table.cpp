#include "Table.h"
#include "CardFactory.h"
#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Constructor to initialize players and deck
Table::Table(const std::string& player1Name, const std::string& player2Name)
    : player1(std::make_unique<Player>(player1Name)), 
      player2(std::make_unique<Player>(player2Name)) {
    // Deck is already initialized by default
}

// Constructor to load the game from an input stream
Table::Table(std::istream& in, const CardFactory* cardFactory) {
    // Placeholder: Implement deserialization logic if needed (optional feature for loading game state)
    throw std::runtime_error("Deserialization from input stream is not yet implemented.");
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
    out << YELLOW << "=========================================" << RESET << std::endl;
    out << CYAN << "             Current Game State          " << RESET << std::endl;
    out << YELLOW << "=========================================" << RESET << std::endl;

    out << GREEN << "Deck: " << RESET << deck.size() << " cards remaining\n";
    out << RED << "Discard Pile: " << RESET;
    discardPile.print(out);
    out << "\n";

    out << MAGENTA << "Trade Area: " << RESET;
    tradeArea.print(out);
    out << "\n";

    out << BLUE << "Player 1: " << RESET << *player1 << "\n";
    out << BLUE << "Player 2: " << RESET << *player2 << "\n";
}

// Save the game state to an output stream
void Table::saveGame(std::ostream& out) const {
    out << *player1 << "\n";
    out << *player2 << "\n";

    // Save the deck
    out << "Deck: ";
    deck.print(out);
    out << "\n";

    // Save the discard pile
    out << "Discard Pile: ";
    discardPile.print(out);
    out << "\n";

    // Save the trade area
    out << "Trade Area: ";
    tradeArea.print(out);
    out << "\n";
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
DiscardPile& Table::getDiscardPile() {
    return discardPile;
}

// Accessor for the trade area
TradeArea& Table::getTradeArea() {
    return tradeArea;
}
