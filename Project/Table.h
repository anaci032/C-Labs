#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <memory>
#include <string>
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "CardFactory.h"

class Table {
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    Deck deck;
    DiscardPile discardPile;
    TradeArea tradeArea;

public:
    // Constructors
    Table(const std::string& player1Name, const std::string& player2Name);
    Table(std::istream& in, const CardFactory* cardFactory); // Load game from file

    // Check if a player has won the game
    bool win(std::string& winnerName) const;

    // Print the table state
    void print(std::ostream& out) const;

    // Save the game state to an output stream
    void saveGame(std::ostream& out) const;

    // Accessors
    Player* getPlayer1() const;
    Player* getPlayer2() const;
    Deck& getDeck();
    DiscardPile& getDiscardPile();
    TradeArea& getTradeArea();

    // Friend operator<< for printing the table
    friend std::ostream& operator<<(std::ostream& out, const Table& table) {
        table.print(out);
        return out;
    }
};

#endif // TABLE_H
