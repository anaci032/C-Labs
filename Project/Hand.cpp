#include "Hand.h"
#include <iostream>

void Hand::addCard(std::unique_ptr<Card> card) {
    cards.push_back(std::move(card));
}

Card* Hand::play() {
    if (!cards.empty()) {
        Card* card = cards.front().release();
        cards.pop_front();
        return card;
    }
    return nullptr;
}

Card* Hand::top() const {
    return cards.empty() ? nullptr : cards.front().get();
}

Card* Hand::operator[](int index) {
    if (index >= 0 && index < cards.size()) {
        auto it = cards.begin() + index;
        Card* card = it->release();
        cards.erase(it);
        return card;
    }
    return nullptr;
}

void Hand::print(std::ostream& out) const {
    for (const auto& card : cards) {
        card->print(out);
        out << " ";
    }
}
