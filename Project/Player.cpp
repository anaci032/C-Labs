#include "Player.h"
#include "exceptions.h"
#include <iostream>
#include "Chain.h"
#include "Card.h"

void displayCard(const Card& card) {
    card.print(std::cout); // Use the card's `print` method for its emoji/shorthand
}

Player::Player(const std::string& playerName, int maxChains)
    : name(playerName), maxChains(maxChains) {
    chains.resize(maxChains); // Initializes chains with a max of `maxChains`
}

std::string Player::getName() const {
    return name;
}

int Player::getNumCoins() const {
    return coins;
}

void Player::addCoins(int num) {
    coins += num;
}

void Player::buyThirdChain() {
    if (coins >= 3 && maxChains == 2) {
        coins -= 3;
        maxChains = 3;
        chains.resize(maxChains); // Resize chains vector to allow a third chain
    } else {
        throw NotEnoughCoins();
    }
}

int Player::getMaxNumChains() const {
    return maxChains;
}

int Player::getNumChains() const {
    int count = 0;
    for (const auto& chain : chains) {
        if (chain) count++;
    }
    return count;
}

void Player::addChain(std::unique_ptr<ChainBase> chain) {
    for (auto& ch : chains) {
        if (!ch) {
            ch = std::move(chain);
            return;
        }
    }
    throw std::runtime_error("All chains are already occupied.");
}

ChainBase* Player::getChain(int index) const {
    if (index >= 0 && index < chains.size()) {
        return chains[index].get();
    }
    return nullptr;
}

void Player::addToChain(Card* card) {
    for (auto& chain : chains) {
        if (chain && chain->canAddCard(card)) {
            *chain += card; // Add the card to the matching chain
            return;
        }
    }

    if (getNumChains() < maxChains) {
        // Create a new chain with the card
        auto newChain = std::make_unique<Chain<Card>>();
        *newChain += card; // Add the card to the new chain
        for (auto& chain : chains) {
            if (!chain) { // Find an empty slot for the new chain
                chain = std::move(newChain);
                return;
            }
        }
    } else {
        throw std::runtime_error("No available chains. Consider selling a chain.");
    }
}

int Player::sellChain(int chainIndex) {
    if (chainIndex >= 0 && chainIndex < chains.size() && chains[chainIndex]) {
        int coinsEarned = chains[chainIndex]->sell(); // Calculate coins earned
        coins += coinsEarned; // Add coins to player's total
        chains[chainIndex] = nullptr; // Remove the chain
        return coinsEarned;
    }
    throw std::runtime_error("Invalid chain index.");
}

void Player::addCardToHand(Card* card) {
    hand.addCard(card); // Add the card to the player's hand
}

void Player::printHand(std::ostream& out, bool showAll) const {
    if (showAll) {
        out << "Hand: ";
        if (!hand.isEmpty()) {
            hand.print(out); // Print all cards in the hand
        } else {
            out << "No cards in hand";
        }
        out << "\n";
    } else {
        out << "Top card of hand: ";
        Card* topCard = hand.top();
        if (topCard) {
            topCard->print(out); // Print the top card
        } else {
            out << "No cards";
        }
        out << "\n";
    }
}

void Player::printChains(std::ostream& out) const {
    out << "Chains:\n";
    for (size_t i = 0; i < chains.size(); ++i) {
        if (chains[i]) {
            out << "Chain " << i + 1 << ": ";
            chains[i]->print(out); // Use ChainBase's print method
            out << "\n";
        } else {
            out << "Chain " << i + 1 << ": Empty\n";
        }
    }
}
