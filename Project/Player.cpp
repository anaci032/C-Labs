#include "Player.h"
#include "exceptions.h"
#include <iostream>

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

void Player::printHand(std::ostream& out, bool showAll) const {
    if (showAll) {
        out << "Hand: ";
        hand.print(out);
        out << "\n";
    } else {
        out << "Top card of hand: ";
        Card* topCard = hand.top();
        if (topCard) {
            out << *topCard;
        } else {
            out << "No cards";
        }
        out << "\n";
    }
}
