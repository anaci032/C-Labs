#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Hand.h"
#include "Card.h"
#include "Chain.h"
#include "ChainBase.h"

// Utility function for displaying a card (can be used outside Player)
void displayCard(const Card& card);

class Player {
    std::string name;
    int coins = 0;
    Hand hand;
    std::vector<std::unique_ptr<ChainBase>> chains; // Polymorphic behavior for chains
    int maxChains;

public:
    // Constructor
    Player(const std::string& playerName, int maxChains = 2);

    // Getters
    std::string getName() const;
    int getNumCoins() const;
    int getMaxNumChains() const;
    int getNumChains() const;
    ChainBase* getChain(int index) const;

    // Game actions
    void addCoins(int num);
    void buyThirdChain();
    void addToChain(Card* card); // Adds a card to the appropriate chain
    int sellChain(int chainIndex); // Sells a chain for coins
    void addChain(std::unique_ptr<ChainBase> chain);
    void addCardToHand(Card* card); // Add a card to the hand

    // Display methods
    void printHand(std::ostream& out, bool showAll) const;
    void printChains(std::ostream& out) const; // Display chains

    // Overload for printing player info
    friend std::ostream& operator<<(std::ostream& out, const Player& player) {
        out << player.name << " has " << player.coins << " coins\n";
        player.printChains(out); // Display chains
        player.printHand(out, true); // Display all cards in hand
        return out;
    }
};

#endif // PLAYER_H
