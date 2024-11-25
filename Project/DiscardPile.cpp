#include "DiscardPile.h"

void DiscardPile::addCard(Card* card) {
    cards.push_back(std::unique_ptr<Card>(card));
}

Card* DiscardPile::pickUp() {
    if (!cards.empty()) {
        Card* topCard = cards.back().release();
        cards.pop_back();
        return topCard;
    }
    return nullptr;
}

void DiscardPile::print(std::ostream& out) const {
    for (const auto& card : cards) {
        card->print(out);
        out << " ";
    }
}
