#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <list>
#include <memory>
#include <string>
#include "Card.h"

class TradeArea {
    std::list<std::unique_ptr<Card>> cards;

public:
    TradeArea() = default;

    // Adds a card to the trade area without checking legality
    TradeArea& operator+=(Card* card);

    // Checks if a card of the same type is already in the trade area
    bool legal(Card* card) const;

    // Removes and returns a card of the specified bean type
    Card* trade(const std::string& beanName);

    // Returns the number of cards currently in the trade area
    int numCards() const;

    // Prints all cards in the trade area to the output stream
    void print(std::ostream& out) const;

    // Friend operator<< for printing
    friend std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea) {
        tradeArea.print(out);
        return out;
    }
};

#endif // TRADEAREA_H
