#include "TradeArea.h"
#include <algorithm>

// Adds a card to the trade area without checking legality
TradeArea& TradeArea::operator+=(Card* card) {
    cards.push_back(std::unique_ptr<Card>(card));
    return *this;
}

// Checks if a card of the same type is already in the trade area
bool TradeArea::legal(Card* card) const {
    for (const auto& c : cards) {
        if (c->getName() == card->getName()) {
            return true;
        }
    }
    return false;
}

// Removes and returns a card of the specified bean type from the trade area
Card* TradeArea::trade(const std::string& beanName) {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        if ((*it)->getName() == beanName) {
            Card* card = it->release();
            cards.erase(it);
            return card;
        }
    }
    return nullptr;
}

// Returns the number of cards currently in the trade area
int TradeArea::numCards() const {
    return cards.size();
}

// Prints all cards in the trade area to the output stream
void TradeArea::print(std::ostream& out) const {
    for (const auto& card : cards) {
        card->print(out);
        out << " ";
    }
}
